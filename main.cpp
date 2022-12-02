#include <iostream>
#include <fstream>
#include <random>

#include "Date.h"


void load(std::string * maleNames, std::string * femaleNames, std::string * surnames);

int main() {

    //Loading source files
    std::string *maleNames, *femaleNames, *surnames;

    maleNames = new std::string[1000];
    femaleNames = new std::string[1000];
    surnames = new std::string[1000];

    load(maleNames,femaleNames,surnames);



    delete maleNames;
    delete femaleNames;
    delete surnames;
    return 0;
}

void load(std::string * maleNames, std::string * femaleNames, std::string * surnames) {

    int i = 0;

    std::ifstream myStream("../source/maleNames.txt");
    if(myStream.is_open()){
        std::string line;
        while (getline(myStream, line)) {
            maleNames[i] = line;
            i++;
        }
        myStream.close();

    } else {
        printf("Unable to open maleNames.txt.");
    }

    i = 0;

    std::ifstream myStream2("../source/femaleNames.txt");
    if(myStream2.is_open()){
        std::string line;
        while (getline(myStream2, line)) {
            femaleNames[i] = line;
            i++;
        }
        myStream2.close();

    } else {
        printf("Unable to open femaleNames.txt");
    }

    i = 0;

    std::ifstream myStream3("../source/surnames.txt");
    if(myStream3.is_open()){
        std::string line;
        while (getline(myStream3, line)) {
            surnames[i] = line;
            i++;
        }
        myStream3.close();

    } else {
        printf("Unable to open surnames.txt.");
    }
}
