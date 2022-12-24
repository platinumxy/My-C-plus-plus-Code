#include "resource.h"
#include <algorithm>

void lowercase(std::string& str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

void uppercase(std::string& str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
}

void titleCase(std::string& str) {
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (i == 0)
            str[i] = toupper(str[i]);

        else if (str[i - 1] == ' ')
            str[i] = toupper(str[i]);

        else
            str[i] = tolower(str[i]);
    }
}

bool isUpper(char letter) {
    return (letter >= 'A' && letter <= 'Z');
}

void invertCase(std::string& str) {
    for (int i = 0; i < str.size(); i++) {
        if (isUpper(str[i])) {
            str[i] = tolower(str[i]);
        }
        else {
            str[i] = toupper(str[i]);
        }
    }
}

void reverseString(std::string& str) {
    size_t n = str.length() - 1;
    int i = 0;
    while (i <= n) {
        //Using the swap method to switch values at each index
        std::swap(str[i], str[n]);
        n--;
        i++;
    }
}