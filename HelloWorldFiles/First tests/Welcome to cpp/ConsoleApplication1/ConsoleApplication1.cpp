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

struct actionsMap
{
    string message;
    int (*command)(person&); //note this requires that the functions return a status code
};

void clearInputStream();
void lower(string& str);
void upper(string& str);
void titleCase(string& str);

int enterMatix(person& pers) ;
int addFunFact(person & pers) ;
int revealKnowledge(person& pers);
int getActions(vector<actionsMap> acts);
int quit(person& pers);



int main()
{

    vector<actionsMap> acts = {
        {"Enter the matrix", enterMatix},
        {"Reveal the programs knowledge of you", revealKnowledge},
        {"Give the program a fun fact", addFunFact},
        {"Quit the program", quit}
        
    };
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
    while (age == 0){
        cout << "Please enter your age : ";
        cin >> age;
    }
    person user(fname, lname, age);
     
    int statusCode = 0;
    while (statusCode == 0) {
        cout << endl;//make it look nice
        statusCode = acts[getActions(acts)].command(user);
    }
    return 0;
}



void clearInputStream(){
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void lower(string& str){
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

void upper(string& str){
    transform(str.begin(), str.end(), str.begin(), ::toupper);
};

void titleCase(string& str){
    struct local { // there is no local variables in cpp so we need to create a class (local)
        static char upperLetter(char letter){
            return toupper(letter);
        }
        static char lowerLetter(char letter){
            return tolower(letter);
        }
    };
    for (int i = 0; str[i] != '\0'; i++){
        if (i == 0) 
            str[i] = local::upperLetter(str[i]);
        
        else if (str[i - 1] == ' ')
            str[i] = local::upperLetter(str[i]);
        
        else
            str[i] = local::lowerLetter(str[i]);
        
    }
}

int enterMatix(person& pers) {
    string message = "Welcome to the Matrix "+pers.fname;
    const size_t MESSLEN = message.length();
    string finishedMessage = message;
    for (int i = 0; i < MESSLEN; i++) finishedMessage[i] = ' ';

    for (int i = 0; i < MESSLEN; i++) {
        finishedMessage[i] = message[i];
        cout << "\r" << finishedMessage;
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    cout << endl;
    return 0;
}

int addFunFact(person& pers) {
    cout << pers.fname + " please could you enter a fun fact on the line bellow:" << endl;
    string funcFact;
    getline(cin, funcFact);
    pers.funFacts.push_back(funcFact);
    return 0;
}

int revealKnowledge(person& pers) {
    cout << "Your Name Is : " << pers.fname << " " << pers.lname << endl;
    cout << "You are aged : " << pers.age << endl;
    if (pers.funFacts.size() == 0) 
        cout << "And I know no fun facts about you" << endl;
    else {
        cout << "And here's the facts you've told me:" << endl;
        for (int i = 0; i < pers.funFacts.size(); i++) 
            cout << i + 1 << ". " << pers.funFacts[i] << endl;
    }
    return 0;
}

int getActions(vector<actionsMap> acts){
    int index = -1;
    size_t lenActs = acts.size();
    while (index == -1) {
        cout << "Enter the index of the command you want to use" << endl;
        for (int i = 0; i < lenActs; i++) {
            cout << i + 1 << ". " << acts[i].message << endl;
        }
        cin >> index;
        if (index <= 0 || index > lenActs) {
            index = -1;
        }
    }
    clearInputStream();
    return index - 1;
}

int quit(person& pers) {
    return 1;
}
