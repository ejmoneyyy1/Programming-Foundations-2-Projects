#ifndef DICTIONARY_H
#define DICTIONARY_H

//-----------------------------------------------------------
// Purpose: Header file for the Dictionary class.
// Author:  John Gauch
//-----------------------------------------------------------
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//-----------------------------------------------------------
// Define the Dictionary class interface
//-----------------------------------------------------------
const int NUM_WORDS = 1000;
class Dictionary
{
public:
    Dictionary();
    Dictionary(const Dictionary & copy);
    ~Dictionary();

    void ReadFile(string name);
    bool Lookup(string str);

private:
    int count;
    string word[NUM_WORDS];
};

#endif