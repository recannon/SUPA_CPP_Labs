//Functions for AnalyzeData.cpp
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include "CustomFunctions.h"

void read_data(std::ifstream &data_file, std::vector<double> &x, std::vector<double> &y, int read_lines) {
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

void print_vector(std::vector<double> v, int n) {
    // Function inputs a vector, and int n (no of lines printed)
    // Loops through vector and outputs n lines
    // if n is larger than vector size, prints first 5 values, if n = -1, prints whole vector
    if (n == -1) {
        for (int i = 1; i<=v.size()-1; i++)
            std::cout << v[i] << ' ';
    }
    else if (n > v.size()) {
        for (int i = 1; i<=5; i++)
            std::cout << v[i] << ' ';
        std::cout << "...\n(Vector does not have " << n << " values. The first five values were shown.)";
    }
    else {
        for (int i = 1; i<=n; i++)
            std::cout << v[i] << ' ';
        std::cout << "\n(Printed first " << n << " values of vector.)";
    }
    std::cout << '\n';
}

std::vector<double> vector_mag(std::vector<double> x, std::vector<double> y) {
    //Takes in two vectors (of equal size) and returns a vector of the magnitudes, for each value
    std::vector<double> z;
    if (x.size() != y.size()) {
        std::cout << "Vectors are not of equal length\n";
    }
    for (int i = 1; i<=x.size()-1; i++)
        z.push_back(sqrt(x[i]*x[i] + y[i]*y[i]));
    return z;
}