#include "resource.h"


void writeWordsCool(std::string message); // from writeCoolWords.cpp

std::string lineBreakRemover(std::vector<std::string> data, std::string sep = " "); //  From lineBreakRemover.cpp
std::string lineBreakRemover(std::string sep = " "); 

int main()
{
    std::string message = "Hello World!";
    writeWordsCool(message);

    std::cout << lineBreakRemover();
}

