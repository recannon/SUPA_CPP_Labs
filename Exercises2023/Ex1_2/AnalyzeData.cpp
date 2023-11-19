// 20231115
// Written by Richard Cannon

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <numeric>
#include "CustomFunctions.h"


int main() {
    //Defines global variables
    int line = 0;
    std::vector<double> x,y,z,fit;
    std::string p_m, lobf;
    std::ifstream data_file;
    std::ofstream output_file;

    data_file.open("/workspaces/SUPA_CPP_Labs/Exercises2023/Ex1_2/input2D_float.txt", std::ios::in);
    if (data_file.fail()) {
        std::cout << "Cannot find file \n";
        return 0;
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
        readData(data_file, x, y, -1);
        }

    std::cout << "Would you like to print the arrays(p), or calculate and print their magnitudes(m)?\n";

    while (true) {
        //Ask for input to print or find mag
        std::cout << "p/m: ";
        std::cin >> p_m;
        //Print
        if (p_m.at(0) == 'p') {
            // Defines n to output n lines of data
            int n = -1;
            std::cout << "How many lines of data would you like to print? ";
            std::cin >> n;
            // Outputs data arrays
            std::cout << "X data:\n";
            printVector(x, n);
            std::cout << "Y data:\n";
            printVector(y, n);
            break;
        }
        //Mag
        else if (p_m.at(0) == 'm') {
            //Calculates vector of magnitudes
            z = vectorMag(x,y);
            std::cout << "Magnitudes of data:\n";
            printVector(z,-1);
            break;
        }
        else {
            std::cout << "Don't be stupid, try again.\n";
        }
    }

    fit = leastSquareRegression(x,y);

    lobf = "y = " + std::to_string(fit[0]) + "x + " + std::to_string(fit[1]);

    std::cout << "\nLine of best fit for the data is:\n" << lobf << std::endl;

    //Writing to file
    output_file.open("/workspaces/SUPA_CPP_Labs/Exercises2023/Ex1_2/LOBF.txt", std::ios::out);
    output_file << lobf;

    std::cout << "\n\n";
    return 0;
}

