#include <iostream>
#include <string>

int main()
{
    std::string firstName = "John";
    std::string lastName = "Doe";
    std::string fullName;
    //There is two ways to consolidate strings 
    fullName = firstName + " " + lastName;
    //or 
    fullName = firstName.append(" " + lastName) ;
    std::cout << fullName;

    //you can also get the length of a string using .length() or .size() 
    std::string txt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
    std::cout << "The length of the txt string is: " << txt.length(); 

    //you can access and change items using their indexs item[index] 
    std::cout << fullName[0] ;

    /*Escape Chars 
    \'	'	Single quote
    \"	"	Double quote
    \\	\	Backslash
    \t      Tab
    \n      New line
    */

    //To get a full line as input use std::getline(std::cin, var) and the var will now become the whole line 

    std::string DadsFullName ;
    std::cout << "Enter your dads full name:\n";
    getline(std::cin, DadsFullName);
    std::cout << "Your dads name is " << DadsFullName ;

    return 0;
}