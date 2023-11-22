// 20231115
// Written by Richard Cannon

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <numeric>
#include <math.h>

#include "CustomFunctions.h"

int main() {
    //Defines global variables
    int option, line = 0;
    std::vector<double> x,y,x_err,y_err;
    std::vector<int> choices;
    std::string choice;
    std::ifstream data_file, error_file;
    std::ofstream output_file;
    bool cont;

    //Reading in data
    data_file.open("/workspaces/SUPA_CPP_Labs/Exercises2023/Ex1_2/input2D_float.txt", std::ios::in);
    if (data_file.fail()) {
        std::cout << "Cannot find data file \n";
        return 0;
        }
    else {
        readData(data_file, x, y, -1);
        }

    //Reading in errors
    error_file.open("/workspaces/SUPA_CPP_Labs/Exercises2023/Ex1_2/error2D_float.txt", std::ios::in);
    if (error_file.fail()) {
        std::cout << "Cannot find error file \n";
        return 0;
        }
    else {
        readData(error_file, x_err, y_err, -1);
        }

    //Asking what the user would like to do
    std::cout << "Would you like to:\nPrint the arrays? (p)\n"
        << "Calculate their magnitudes? (m)\n"
        << "Fit the data to a linear model and calculate the Chi squared? (f)\n"
        << "Calculate x^y for all values in the array? (e)\n";

    while (true) {
        //Ask for input to print or find mag
        std::cout << "p/m/f/e: ";
        std::cin >> choice;
        if (choice.at(0) == 'p') {
            option = 1; //Print
            choices.push_back(option);
        }
        else if (choice.at(0) == 'm') {
            option = 2; //Mag
            choices.push_back(option);
        }
        else if (choice.at(0) == 'f') {
            option = 3; //Fit
            choices.push_back(option);
        }
        else if (choice.at(0) == 'e') {
            option = 4; //Exponent
            choices.push_back(option);
        }
        else {
            std::cout << "Don't be stupid, try again.\n";
            continue;
        }
        while (true) {
            std::cout << "Would you like to do something else as well? (y/n) ";
            std::cin >> choice;
            if (choice.at(0) == 'y') {
                std::cout << "What would you like to do?\n";
                cont = true;
                break;
            }
            else if (choice.at(0) == 'n') {
                std::cout << "Proceeding to perform and save tasks.\n";
                cont = false;
                break;
            }
            else {
                std::cout << "Don't be stupid, try again.\n";
                continue;
            }
        }
        if (cont == true) {
            continue;
        }
        else {
            break;
        }
    }

    for (int i = 0; i < choices.size(); i++) {
        switch(choices[i]) {
            case 1:{ // Print
                int n;
                std::cout << "\nPrinting\n";
                std::cout << "How many lines of data would you like to print? (-1 will print all lines) ";
                std::cin >> n;
                std::cout << "\nX data:\n";
                printVector(x, n);
                std::cout << "Y data:\n";
                printVector(y, n);
                std::cout << std::endl;
                continue;
            }
            case 2:{ // Magnitudes
                std::vector<double> z;
                std::cout << "\n Calculating magnitudes\n";
                z = vectorMag(x,y);
                std::cout << "Magnitudes of data:\n";
                printVector(z,-1);
                continue;
            }
            case 3:{ // Fit and Chi Squared
                std::vector<double> fit;
                std::string lobf;
                double chisqr;
                
                std::cout << "\nPerforming fit and Chi Squared\n";

                fit = modelFit_ChiSquared(x,y,x_err,y_err);
                lobf = "y = " + std::to_string(fit[0]) + "x + " + std::to_string(fit[1]);
                chisqr = fit[2]/(x.size()-1);

                std::cout << "Line of best fit for the data is: " << lobf << std::endl;
                std::cout << "The chi squared/NDF: " << chisqr << std::endl;

                //Writing to file
                output_file.open("/workspaces/SUPA_CPP_Labs/Exercises2023/Ex1_2/ModelFit.txt", std::ios::out);
                output_file << lobf << std::endl << chisqr;
                continue;
            }
            case 4:{ // Exponent array
                std::vector<double> exp;
                std::cout << "\nCalculating exponents\n";
                exp = exponentCalc(x,y,0,exp);
                std::cout << "Calculated exponent\n";
                printVector(exp,-1);
                continue;
            }
            default:{ //Should never happen
                break;
            }
        }
    }





    std::cout << "\n\n";
    return 0;
}

