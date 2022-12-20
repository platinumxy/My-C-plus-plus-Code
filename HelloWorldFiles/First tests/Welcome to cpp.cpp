#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
const int DEFAULTAGE = 10;
const string DEFAULTFNAME = "John";
const string DEFAULTLNAME = "Doe";

class person
{
public:
    string fname, lname;
    int age;
    person(string Fname = DEFAULTFNAME, string Lname = DEFAULTLNAME, int Age = DEFAULTAGE)
    {
        fname = Fname;
        lname = Lname;
        age = Age;
    };
};

void lower(string &str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

void upper(string &str)
{
    transform(str.begin(), str.end(), str.begin(), ::toupper);
};

void titleCase(string &str)
{
    struct local // there is no local variables in cpp so we need to create a class (local)
    {
        static char upperLetter(char letter)
            {return toupper(letter);}
        static char lowerLetter(char letter)
            {return tolower(letter);}
    };
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (i == 0)
            {str[i] = local::upperLetter(str[i]);}
        else if (str[i - 1] == ' ')
            {str[i] = local::upperLetter(str[i]);}
        else
            {str[i] = local::lowerLetter(str[i]);}
    }
}

int main()
{
    cout << "Please enter your full name :";
    string fname = "", lname = "";
    while (fname == "" && lname == "") {
        cin >> fname;    // Warning Unicode is not supported so issues may arrise from that
        cin >> lname;    // Using the fact that space is a termentating char 
    }
    titleCase(fname);
    titleCase(lname);

    int age = 0;
    while (age == 0)
    {
        cout << "Please enter your age :" << endl;
        cin >> age;
    }
    person p1(fname, lname, age);
    
    return 0;
}
