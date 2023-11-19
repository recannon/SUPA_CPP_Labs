#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <numeric>

void readData(std::ifstream&, std::vector<double>&, std::vector<double>&, int);
void printVector(std::vector<double>, int);
std::vector<double> vectorMag(std::vector<double>, std::vector<double>);
std::vector<double> leastSquareRegression(std::vector<double>, std::vector<double>);
