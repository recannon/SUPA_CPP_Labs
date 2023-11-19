//Functions for AnalyzeData.cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include "CustomFunctions.h"
#include <numeric>

void readData(std::ifstream &data_file, std::vector<double> &x, std::vector<double> &y, int read_lines) {
    // Function inputs data_file, output vectors, and no of lines to read
    // Reads first {read_lines} of file and outputs as x and y vectors
    double x_i, y_i;
    char comma;
    int line = 0;
    while (!data_file.eof()) {
        data_file >> x_i >> comma >> y_i; 
        x.push_back(x_i);
        y.push_back(y_i); 
        line++;
        if (line == read_lines){
            break;
            }
        }
    std::cout << "Read " << line << " lines of the file." << std::endl;
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

std::vector<double> leastSquareRegression(std::vector<double> x_v, std::vector<double> y_v) {
    //Loads data as x_i and y_i arrays
    //Outputs a vector with containing m and c for a y=mx+c fit
    std::vector<double> xy_v, xx_v, fit;
    double x, y, xy, xx, m, c;
    int N = x_v.size();
    // Calculates vectors of xy and xx in order to calculate sums later
    for (int i = 0; i<=N-1; i++)
        xy_v.push_back(x_v[i]*y_v[i]);
    for (int i = 0; i<=N-1; i++)
        xx_v.push_back(x_v[i]*x_v[i]);
    
    // calculating summations
    x = std::accumulate(x_v.begin(),x_v.end(),0);
    y = std::accumulate(y_v.begin(),y_v.end(),0);
    xy = std::accumulate(xy_v.begin(),xy_v.end(),0);
    xx = std::accumulate(xx_v.begin(),xx_v.end(),0);

    m = (N*xy - x*y) / (N*xx - x*x);
    c = (y - m*x) / N;

    fit.push_back(m);
    fit.push_back(c);
    return fit;
}