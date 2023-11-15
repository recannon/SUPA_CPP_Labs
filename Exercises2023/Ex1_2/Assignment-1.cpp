// 20231115
// Written by Richard Cannon

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <cstdlib>

int main() {

    std::cout << "Instructions 4.1" << std::endl;
    std::ifstream data;
    data.open("input2D_float.txt", std::ios::in);

    data.clear();
    data.seekg(0, std::ios::beg);

    int line = 0;

    std::cout << line << std::endl;


    //while (!data.eof()){
      //  if (!data.eof()){
       //     line++;
       // }
    //}
    double x;
    data >> x;

    std::cout << x << std::endl;

    std::cout << line << std::endl;

    std::cout << "\n\n";
}