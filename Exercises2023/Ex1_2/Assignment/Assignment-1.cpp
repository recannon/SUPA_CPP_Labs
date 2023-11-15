// 20231115
// Written by Richard Cannon

#include <iostream>
#include <vector>
#include <cmath>

double vectorMag(double, double);

int main(){

    // 2 I
    std::cout << "2 (I)" << std::endl;
    std::cout << "Hello World! \n" << std::endl;

    // 2 II
    double x, y;
    x = 2.3;
    y = 4.5;

    std::vector<double> v{x, y};

    double z = pow((v[0]*v[0] + v[1]*v[1]),0.5);

    std::cout << "2 (II)" << std::endl;
    std::cout << "The magnitude of vector (x,y) is "
    << z << std::endl << std::endl;

    //2 (III)
    double inp1, inp2;

    std::cout << "Please enter the x and y components of a vector:\n"
    << "Vx = "; 
    std::cin >> inp1; 
    std::cout << "\nVy = ";
    std::cin >> inp2;
    std::cout << std::endl;

    double magnitude = vectorMag(inp1, inp2);

    std::cout << "2 (III)" << std::endl;

    std::cout << std::endl << std::endl;
    return 0;
}