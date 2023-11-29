// Written by Richard Cannon
// 20231129

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <numeric>
#include <math.h>
#include <filesystem> //To check extensions in a nice way

//#include "gnuplot-iostream.h"
#include "FiniteFunctions.h"
#include "CustomFunctions2.h"

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
    
    //FiniteFunction.plotdata(data, 10);
    
    
    std::cout << "\n\n";
}