#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <numeric>
#include <math.h>


void readData(std::vector<double>&, std::string);
void printVector(std::vector<double>, int);
std::vector<double> vectorMag(std::vector<double>, std::vector<double>);
std::vector<double> modelFit_ChiSquared(std::vector<double>, std::vector<double>,
                                            std::vector<double>, std::vector<double>);
std::vector<double> exponentCalc(std::vector<double>,std::vector<double>);
std::vector<double> exponentCalc(std::vector<double>,std::vector<double>, int, std::vector<double>&);
double performPower(double, int, double);
void writeOutput(std::string, std::vector<std::string>);
void writeOutput(std::string, std::vector<double>);


