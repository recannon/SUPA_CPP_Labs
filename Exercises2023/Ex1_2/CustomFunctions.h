#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <cstdlib>

void read_data(std::ifstream&, std::vector<double>&, std::vector<double>&, int);
void print_vector(std::vector<double>, int);
std::vector<double> vector_mag(std::vector<double>, std::vector<double>);