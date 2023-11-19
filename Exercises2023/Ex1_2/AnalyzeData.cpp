// 20231115
// Written by Richard Cannon

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include "CustomFunctions.h"

int main() {
    //Defines global variables
    int line = 0;
    std::vector<double> y;
    std::vector<double> x;
    std::vector<double> z;

    std::ifstream data_file;

    data_file.open("/workspaces/SUPA_CPP_Labs/Exercises2023/Ex1_2/input2D_float.txt", std::ios::in);
    if (data_file.fail()) {
        std::cout << "Cannot find file \n";
        }
    else {
        std::cout << "File found\n";

        // Takes first line and saves it as header string, then outputs
        std::string headers;
        data_file >> headers;
        std::cout << "Headers of: " << headers << std::endl;

        // Defines comma char to deal with CSV, and x_i, y_i for use in the loop
        char comma = ',';
        double x_i, y_i;

        // Loads data into temporary variables, ignoring the comma, and saves into arrays
        read_data(data_file, x, y, -1);
        }

    // Defines n to output n lines of data
    int n = -1;
    // Outputs data arrays
    std::cout << "X data:\n";
    print_vector(x, n);
    std::cout << "Y data:\n";
    print_vector(y, n);

    //Calculates vector of magnitudes
    z = vector_mag(x,y);
    std::cout << "Magnitudes of data:\n";
    print_vector(z,-1);

    std::cout << "\n\n";
    return 0;
}

