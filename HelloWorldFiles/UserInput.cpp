#include <iostream>
#include <string>


int main()
{
    std::string fName, lName;
    std::cout << "Enter your first name" << std::endl ; 
    std::cin >> fName ;                                     //Note when resiving inputs like this spaces are thought as termenating chars so lname will get the stuff after the space
    std::cout << "\nEnter your last name" << std::endl ; 
    std::cin >> lName ;
    std::cout << "\nFirst name : " << fName <<std::endl;
    std::cout << "\nLast name : " << lName <<std::endl;

    int num1, num2;
    std::cout << "Enter number 1: "; 
    std::cin >> num1 ;
    std::cout << "\nEnter number 2: ";
    std::cin >> num2; 
    std::cout << "\n" << num1 + num2 ;
    return 0;
}