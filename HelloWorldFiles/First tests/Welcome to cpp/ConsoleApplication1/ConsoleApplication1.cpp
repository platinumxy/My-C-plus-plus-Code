// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <chrono>
#include <thread>
#include <ios>// for <streamsize>
#include <limits>// for numeric_limits

using namespace std;
const int DEFAULTAGE = 10;
const string DEFAULTFNAME = "John";
const string DEFAULTLNAME = "Doe";


class person
{
public:
    string fname, lname;
    int age;
    vector<string> funFacts;
    person(string Fname = DEFAULTFNAME, string Lname = DEFAULTLNAME, int Age = DEFAULTAGE)
    {
        fname = Fname;
        lname = Lname;
        age = Age;
    };
};

struct actionsMap {
    string message;
    int (*command)(person); //note this requires that the functions return 0
};

void clearInputStream()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void lower(string& str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

void upper(string& str)
{
    transform(str.begin(), str.end(), str.begin(), ::toupper);
};

void titleCase(string& str)
{
    struct local // there is no local variables in cpp so we need to create a class (local)
    {
        static char upperLetter(char letter)
        {
            return toupper(letter);
        }
        static char lowerLetter(char letter)
        {
            return tolower(letter);
        }
    };
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (i == 0)
        {
            str[i] = local::upperLetter(str[i]);
        }
        else if (str[i - 1] == ' ')
        {
            str[i] = local::upperLetter(str[i]);
        }
        else
        {
            str[i] = local::lowerLetter(str[i]);
        }
    }
}

int enterMatix(person pers) {
    string message = "Welcome to the Matrix "+pers.fname;
    const int MESSLEN = message.length();
    string finishedMessage = message;
    for (int i = 0; i < MESSLEN; i++) {
        finishedMessage[i] = ' ';
    }
    for (int i = 0; i < MESSLEN; i++) {
        finishedMessage[i] = message[i];
        cout << "\r" << finishedMessage;
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    return 0;
}

int addFunFact(person pers) {
    cout << pers.fname + " please could you enter a fun fact about youself on a single line:";
    string funcFact;
    getline(cin, funcFact);
}

int main()
{

    actionsMap acts[5] = { 
        {"Enter the matrix", enterMatix},
        {"", },
        {"", },
    };
    acts;

    cout << "Please enter your full name : ";
    string fname = "", lname = "";
    while (fname == "" && lname == "") {
        cin >> fname;    // Warning Unicode is not supported so issues may arrise from that
        cin >> lname;    // Using the fact that space is a termentating char 
    }
    clearInputStream();
    titleCase(fname);
    titleCase(lname);

    int age = 0;
    while (age == 0)
    {
        cout << "Please enter your age : ";
        cin >> age;
    }
    person p1(fname, lname, age);
     
    enterMatix(p1);

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
