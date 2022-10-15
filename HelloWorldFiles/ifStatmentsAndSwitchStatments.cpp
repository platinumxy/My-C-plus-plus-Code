#include <iostream>
#include <string>

int main()
{
    /*
    Use if to specify a block of code to be executed, if a specified condition is true
    Use else to specify a block of code to be executed, if the same condition is false
    Use else if to specify a new condition to test, if the first condition is false
    Use switch to specify many alternative blocks of code to be executed
    */
    bool condition = true;

    if (condition)
    {
        std::cout << "Conditon met";
    }
    else
    {
        std::cout << "Condtion not met";
    };
    return 0;

    // Short hand If Else (Ternary Operator)
    // The variable becomes the output of the short hand 
    // variable = (condition) ? expressionTrue : expressionFalse;

    int time = 20;
    std::string result = (time < 18) ? "Good day." : "Good evening.";
    std::cout << result;
    
    //Switchs Choses one of many code blocks to exicute 
    //switch(expression) {
    //    case x:
    //      // code block
    //      break;
    //    case y:
    //      // code block
    //      break;
    //    default:
    //      // code block
}