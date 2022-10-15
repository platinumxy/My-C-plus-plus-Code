#include <iostream>
#include <string>
int main()
{
    int number = 10;           // Storing whole numbs 10
    double decimal = 13.12;    // Storing decimal numbers 3.12
    float flotingpoint = 9.23; // Storing decimal numbers with less pressision
    char text = 'B';           // Storing individual characters 'A'
    std::string str = "Hello"; // Storing strings
    bool YesNo = true;         // Storing true or false

    std::cout << str << " World !" << std::endl; // When consolidating strings and data types sepreate them with <<
    // Use \n or <<std::endl

    // can delcare multiple on one line
    int a = 10, b = 20, c = 30; // or
    int x, y, z;
    x = y = z = 50;

    const int minutesPerHour = 60; // Use const to create a read only var
}