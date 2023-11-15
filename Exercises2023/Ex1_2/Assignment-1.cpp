// 20231115
// Written by Richard Cannon

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <cstdlib>

int main() {
    std::cout << "Instructions 4.1" << std::endl;
    std::ifstream data_file;
    int line = 0;
    data_file.open("/workspaces/SUPA_CPP_Labs/Exercises2023/Ex1_2/input2D_float.txt", std::ios::in);
    if (data_file.fail()) {
        std::cout << "Cannot find file \n";
    }
    else {
        std::cout << "File found\n";
        std::string headers;
        double x = 4.56;
        double y = 3.45;
        
        // Takes first line and saves it as header strings
        data_file >> headers;
        std::cout << headers << std::endl;

        while (1) {
            if(data_file.eof())          
                break;  
            data_file >> x >> y;              
            std::cout<<x<<" "<<y<<std::endl; 
            line++;
            }
        }

    std::cout << "\n\n";
    return 0;
}