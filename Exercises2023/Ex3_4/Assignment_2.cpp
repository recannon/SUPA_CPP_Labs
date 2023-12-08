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

    out_file = "test.txt";
    
    FiniteFunction myFit(dmin, dmax, out_file);
    //NormalDistribution myFit(dmin, dmax, out_file, -2, 2);
    //CauchyLorentzDistribution myFit(dmin, dmax, out_file, 2, 2.2);
    //negCrystalBallDistribution myFit(dmin,dmax,out_file,1,1,0,1);

    //Generate plot
    myFit.plotData(data, 50);
    myFit.plotFunction();
    std::cout << "\nThe distribution is a normal distribution with a mean of -2 and standard deviation of 2.\n\n";

    //Generate random number. This should work for all models
    std::vector<double> mcmc;
    //Fills the mcmc array with sample
    myFit.metropolisSample(mcmc, dmin, dmax, 10000);

    //Plot
    myFit.plotData(mcmc, 50, false);

    std::cout << "\n\n";
}