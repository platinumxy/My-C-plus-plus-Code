#include "resource.h"


void writeWordsCool(std::string message); // from writeCoolWords.cpp

std::string lineBreakRemover(std::vector<std::string> data, std::string sep = " "); //  from lineBreakRemover.cpp
std::string lineBreakRemover(std::string sep = " "); 

std::string mostCommonWord(std::vector<std::string> words, bool strict = false); // from mostCommonWord.cpp

void invertCase(std::string& str); // fromCaseManipulation.cpp
void reverseString(std::string& str);

int main()
{
    //std::string message = "Hello World!";
    //writeWordsCool(message);

    //std::cout << lineBreakRemover();

    //std::vector<std::string> test{ "abc", "word", "Word", "age", "bob" };
    //std::cout << mostCommonWord(test) << std::endl;

    std::string tmp;
    std::getline(std::cin, tmp);
    //invertCase(tmp);
    //std::cout << tmp << std::endl;
    reverseString(tmp);
    std::cout << tmp << std::endl;

    return 0;
}

