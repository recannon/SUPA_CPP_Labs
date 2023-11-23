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
    std::string data_path, error_path, general_path, output_path;
    bool cont;

    general_path = "/workspaces/SUPA_CPP_Labs/Exercises2023/Ex1_2/";

    //Reading in data
    data_path = general_path + "input2D_float.txt";
    readData(x, y, data_path, -1);

    //Reading in errors
    error_path = general_path + "error2D_float.txt";
    readData(x_err, y_err, data_path, -1);

    //Asking what the user would like to do
    std::cout << "Would you like to:\nPrint the arrays? (p)\n"
        << "Calculate their magnitudes? (m)\n"
        << "Fit the data to a linear model and calculate the Chi squared? (f)\n"
        << "Calculate x^y for all values in the array? (e)\n";

    //Get inputs for what they want to do (Accepts multiple inputs)
    while (true) {
        choice = "z_placeholder";
        std::cout << "p/m/f/e: ";
        std::cin >> choice;
        if (choice.length() != 1) {
            std::cout << "Don't be stupid, try again.\n";
            continue;
        }
        else if (choice.at(0) == 'p') {
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
        choice = "z_placeholder";
        //Do they have another instruction?
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

    // Performing instructions
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
                output_path = general_path + "output_magnitudes.txt";
                std::cout << "\n Calculating magnitudes\n";
                z = vectorMag(x,y);
                writeOutput(output_path, z);
                std::cout << "Saved to file\n";
                continue;
            }
            case 3:{ // Fit and Chi Squared
                std::vector<double> fit_chisqr;
                std::string lobf, chisqr;
                std::vector<std::string> output;
                output_path = general_path + "output_fit-chisqr.txt";
                std::cout << "\nPerforming fit and Chi Squared\n";
                fit_chisqr = modelFit_ChiSquared(x,y,x_err,y_err);
                lobf = "y = " + std::to_string(fit_chisqr[0]) + "x + " + std::to_string(fit_chisqr[1]);
                chisqr = std::to_string(fit_chisqr[2]);
                output.push_back(lobf); output.push_back(chisqr);
                //Writing to file
                writeOutput(output_path, output);
                std::cout << "Saved to file\n";
                continue;
            }
            case 4:{ // Exponent array
                std::vector<double> exp;
                output_path = general_path + "output_exponents.txt";
                std::cout << "\nCalculating exponents\n";
                exp = exponentCalc(x,y,0,exp);
                writeOutput(output_path, exp);
                std::cout << "Saved to file\n";
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

