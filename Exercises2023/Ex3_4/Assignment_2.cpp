// Written by Richard Cannon
// 20231129

#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <fstream>
#include <cstdlib>
#include <numeric>
#include <math.h>
#include <filesystem> //To check extensions in a nice way
#include <time.h>
#include "gnuplot-iostream.h"
#include "FiniteFunctions.h"
#include "CustomFunctions2.h"
#include "AdditionalDistributions.h"

double calculatePi(double,int);


int main() {
    //Define variables
    std::string data_file, out_file;
    std::vector<double> data;
    double dmin, dmax;

    data_file = "./Outputs/data/MysteryData20222.txt";
    readData(data, data_file);
    
    // Minimum and maximum data value
    dmin = *min_element(std::begin(data), std::end(data));
    dmax = *max_element(std::begin(data), std::end(data));
    std::cout << "Minimum: " << dmin << "\nMaximum: " << dmax << std::endl;

    out_file = "Result.txt";
    
    //FiniteFunction myFit(dmin, dmax, out_file);
    NormalDistribution myFit(dmin, dmax, out_file, -2, 2);
    //CauchyLorentzDistribution myFit(dmin, dmax, out_file, 2, 2.2);
    //negCrystalBallDistribution myFit(dmin,dmax,out_file,1,1,0,1);

    //Generate plot
    myFit.plotData(data, 50);
    myFit.plotFunction();
    std::cout << "\nThe distribution is a normal distribution with a mean of -2 and standard deviation of 2.\n";

    //Generate random number. This should work for all models
    std::vector<double> mcmc;
    //Fills the mcmc array with sample
    myFit.metropolisSample(mcmc, dmin, dmax, 10000);

    //Plot
    myFit.plotData(mcmc, 50, false);

    std::cout << "\n\n";

    std::cout << "Bonus Question\nFunction defined below main script\n"
        << "(It takes a while!)\n";

    double pi = calculatePi(1.0,1e8);

}

double calculatePi(double radius,int n_random) {
    if (radius <= 0) {
        std::cout << "Enter a positive value for radius, dummy\n";
        return -1;
    }
    auto seed = time(NULL);
    double x_i, y_i, pi;
    double count = 0;
    double sample = n_random;
    std::mt19937 mtEngine{static_cast<unsigned int>(seed)};
    std::uniform_real_distribution<> inside_square{0,radius};
    for (int i=0; i < n_random; i++) {
        x_i = inside_square(mtEngine);
        y_i = inside_square(mtEngine);
        if (std::sqrt(std::pow(x_i,2) + std::pow(y_i,2)) < radius) {
            count++;
        }
    }
    pi = (count/sample)*4;
    std::cout << count << " " << sample << std::endl;
    std::cout << (count/sample) << std::endl;
    std::cout << std::fixed;
    std::cout << std::setprecision(10);
    std::cout << pi << std::endl;
    return pi;
}