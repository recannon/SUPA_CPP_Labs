// 20231115
// Written by Richard Cannon

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <cstdlib>

void read_data(std::ifstream&, std::vector<double>&, std::vector<double>&, int);

void print_vector(std::vector<double>, int);

std::vector<double> vector_mag(std::vector<double>, std::vector<double>);

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


void read_data(std::ifstream &data_file, std::vector<double> &x, std::vector<double> &y, int read_lines) {
    // Function inputs data_file, output vectors, and no of lines to read
    // Reads first {read_lines} of file and outputs as x and y vectors
    double x_i, y_i;
    char comma;
    int line = 0;
    while (!data_file.eof()) {
        data_file >> x_i >> comma >> y_i; 
        x.push_back(x_i);
        y.push_back(y_i); 
        line++;
        if (line == read_lines){
            break;
            }
        }
    std::cout << "Read " << line << " lines of the file." << std::endl;
}

void print_vector(std::vector<double> v, int n) {
    // Function inputs a vector, and int n (no of lines printed)
    // Loops through vector and outputs n lines
    // if n is larger than vector size, prints first 5 values, if n = -1, prints whole vector
    if (n == -1) {
        for (int i = 1; i<=v.size()-1; i++)
            std::cout << v[i] << ' ';
    }
    else if (n > v.size()) {
        for (int i = 1; i<=5; i++)
            std::cout << v[i] << ' ';
        std::cout << "...\n(Vector does not have " << n << " values. The first five values were shown.)";
    }
    else {
        for (int i = 1; i<=n; i++)
            std::cout << v[i] << ' ';
        std::cout << "\n(Printed first " << n << " values of vector.)";
    }
    std::cout << '\n';
}

std::vector<double> vector_mag(std::vector<double> x, std::vector<double> y) {
    //Takes in two vectors (of equal size) and returns a vector of the magnitudes, for each value
    std::vector<double> z;
    if (x.size() != y.size()) {
        std::cout << "Vectors are not of equal length\n";
    }
    for (int i = 1; i<=x.size()-1; i++)
        z.push_back(sqrt(x[i]*x[i] + y[i]*y[i]));
    return z;
}