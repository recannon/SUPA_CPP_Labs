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
    std::vector<double> x,y,z,fit, x_err, y_err;
    std::string p_m, lobf;
    std::ifstream data_file, error_file;
    std::ofstream output_file;
    double chisqr;

    //Reading in data
    data_file.open("/workspaces/SUPA_CPP_Labs/Exercises2023/Ex1_2/input2D_float.txt", std::ios::in);
    if (data_file.fail()) {
        std::cout << "Cannot find data file \n";
        return 0;
        }
    else {
        std::cout << "File found\n";
        readData(data_file, x, y, -1);
        }

    //Reading in errors
    error_file.open("/workspaces/SUPA_CPP_Labs/Exercises2023/Ex1_2/error2D_float.txt", std::ios::in);
    if (error_file.fail()) {
        std::cout << "Cannot find error file \n";
        return 0;
        }
    else {
        std::cout << "File found\n";
        readData(error_file, x_err, y_err, -1);
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

    //Least squares fit
    fit = modelFit_ChiSquared(x,y,x_err,y_err);

    lobf = "y = " + std::to_string(fit[0]) + "x + " + std::to_string(fit[1]);

    chisqr = fit[2];

    std::cout << "\nLine of best fit for the data is: " << lobf << std::endl;
    std::cout << "The chi squared of this fit is: " << chisqr << std::endl;

    //Writing to file
    output_file.open("/workspaces/SUPA_CPP_Labs/Exercises2023/Ex1_2/ModelFit.txt", std::ios::out);
    output_file << lobf << std::endl << chisqr;

    std::cout << "\n\n";
    return 0;
}

