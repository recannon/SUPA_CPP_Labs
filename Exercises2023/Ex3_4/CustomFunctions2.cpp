//Functions for AnalyzeData.cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <numeric>
#include <math.h>

#include "CustomFunctions2.h"

void readData(std::vector<double> &data, std::string data_path) {
    // Function inputs data_file, output vectors, and no of lines to read
    // Reads first {read_lines} of file and outputs as x and y vectors
    std::ifstream data_file(data_path);
    if (!data_file.is_open()) {
        std::cout << "Cannot find/open data file \n";
        }
    else {
        double data_i;
        // Data values    
        while (!data_file.eof()) {
            data_file >> data_i; 
            if (data_file.fail()) {
                std::cout << "\nERROR: Stopped when a line of data could not be read in\n";
                break;
            }
            data.push_back(data_i);
           }
           std::cout << "Data read successfully\n";
        }
}

void printVector(std::vector<double> v, int n) {
    // Function inputs a vector, and int n (no of lines printed)
    // Loops through vector and outputs n lines
    // if n is larger than vector size, prints first 5 values, if n = -1, prints whole vector
    if (n == -1) {
        for (int i = 0; i<=v.size()-1; i++)
            std::cout << v[i] << ' ';
    }
    else if (n > v.size()) {
        for (int i = 0; i<=5; i++)
            std::cout << v[i] << ' ';
        std::cout << "...\n(Vector does not have " << n << " values. The first five values were shown.)";
    }
    else {
        for (int i = 0; i<=n; i++)
            std::cout << v[i] << ' ';
        std::cout << "\n(Printed first " << n << " values of vector.)";
    }
    std::cout << '\n';
}

std::vector<double> vectorMag(std::vector<double> x, std::vector<double> y) {
    //Takes in two vectors (of equal size) and returns a vector of the magnitudes, for each value
    std::vector<double> z;
    if (x.size() != y.size()) {
        std::cout << "Vectors are not of equal length\n";
    }
    for (int i = 0; i<=x.size()-1; i++)
        z.push_back(sqrt(x[i]*x[i] + y[i]*y[i]));
    return z;
}

std::vector<double> modelFit_ChiSquared(std::vector<double> x_v, std::vector<double> y_v,
                                            std::vector<double> x_err, std::vector<double> y_err) {
    //Loads data as x_i and y_i arrays
    //Outputs a vector with containing m and c for a y=mx+c fit
    std::vector<double> xy_v, xx_v, fit, exp_val;
    double x, y, xy, xx, m, c, chisqr = 0.00;
    int N = x_v.size();
    // Calculates vectors of xy and xx in order to calculate sums later
    for (int i = 0; i<=N-1; i++) {
        xy_v.push_back(x_v[i]*y_v[i]);
        xx_v.push_back(x_v[i]*x_v[i]);
    }
    
    // calculating summations
    x = std::accumulate(x_v.begin(),x_v.end(),0);
    y = std::accumulate(y_v.begin(),y_v.end(),0);
    xy = std::accumulate(xy_v.begin(),xy_v.end(),0);
    xx = std::accumulate(xx_v.begin(),xx_v.end(),0);

    // calculating model parameters and saving into a vector
    m = (N*xy - x*y) / (N*xx - x*x);
    c = (y - m*x) / N;
    fit.push_back(m);
    fit.push_back(c);

    // calculating the expected values
    for (int i = 0; i<=N-1; i++) {
        exp_val.push_back(m*x_v[i] + c);
        chisqr = chisqr + pow((y_v[i] - exp_val[i]),2)/pow((x_err[i]*x_err[i] + y_err[i]*y_err[i]),0.5);
    }
    fit.push_back(chisqr/(x_v.size()-1));
    return fit;
}

std::vector<double> exponentCalc(std::vector<double> x,std::vector<double> y, int i, std::vector<double> &exp) {
    double rounded,exponent,power = x[i];
    //Round the number from the y array
    rounded = std::round(y[i]);
    //If it rounds down to zero, manually set x^y to 1
    if (rounded == 0) {
        exponent = 1;
    }
    else {
        //Recursive function that multiplies x[i] by power(also defined as x[i]) by {rounded} times
        // power increases in every call, x[i] does not
        exponent = performPower(x[i], rounded, power);
    }
    //Add final value to array
    exp.push_back(exponent);
    //If finished array, return exponent array, otherwise return recursive call on next value in the array
    if (exp.size() == x.size()) {
        return exp;
    }
    i++;
    return exponentCalc(x, y, i, exp);
}

double performPower(double a, int no, double power) {
    // If number of times to multiply is now equal to one, return final value
    if (no == 1) {
        return power;
    }
    else { //Otherwise multiply again and return recursive function
        power *= a;
        no --;
    }
    return performPower(a, no, power);
}
void writeOutput(std::string output_path, std::vector<double> output) {
    //Open output file
    std::ofstream output_file(output_path);
    if (!output_file.is_open()) {
        std::cout << "Cannot open output file \n";
        }
    else {
        //Writes each element to file
        for (auto element : output) {
                output_file << element << std::endl;
            }
        }
}
void writeOutput(std::string output_path, std::vector<std::string> output) {
    //Open output file
    std::ofstream output_file(output_path);
    if (!output_file.is_open()) {
        std::cout << "Cannot open output file \n";
        }
    else {
        //Writes each element to file
        for (auto i : output)
                output_file << i << std::endl;
        }
}