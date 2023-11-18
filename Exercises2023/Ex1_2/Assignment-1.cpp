// 20231115
// Written by Richard Cannon

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <cstdlib>

int main() {
    //Defines global variables
    int line = 0;
    std::vector<double> y;
    std::vector<double> x;

    std::cout << "Instructions 4.1" << std::endl;
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
        std::cout << headers << std::endl;

        // Defines comma char to deal with CSV, and x_i, y_i for use in the loop
        char comma = ',';
        double x_i, y_i;

        // Loads data into temporary variables, ignoring the comma, and saves into arrays
        while (!data_file.eof()) {
            data_file >> x_i >> comma >> y_i; 
            x.push_back(x_i);
            y.push_back(y_i); 
            //std::cout<<x_i<<" "<<y_i<<std::endl; 
            line++;
            }
        }

    std::cout << "File has " << line << " lines" << std::endl;

    for (auto i: x)
        std::cout << i << ' ';
    std::cout << '\n';
    for (auto i: y)
        std::cout << i << ' ';
    std::cout << '\n';


    std::cout << "\n\n";
    return 0;
}