#include "dictionary.h"

//-----------------------------------------------------------
// Constructor function
//-----------------------------------------------------------
Dictionary::Dictionary()
{
    // Initialize word array
    count = 0;
    for (int i = 0; i < NUM_WORDS; i++)
        word[i] = "";
}

//-----------------------------------------------------------
// Constructor function
//-----------------------------------------------------------
Dictionary::Dictionary(const Dictionary & copy)
{
    // Initialize word array
    count = copy.count;
    for (int i = 0; i < NUM_WORDS; i++)
        word[i] = copy.word[i];
}

//-----------------------------------------------------------
// Destructor function
//-----------------------------------------------------------
Dictionary::~Dictionary()
{
}


//-----------------------------------------------------------
// Read words into dictionary
//-----------------------------------------------------------
void Dictionary::ReadFile(string name)
{
    // Open input file
    ifstream din;
    din.open(name.c_str());
    if (din.fail())
        return;

    // Read strings into word array
    count = 0;
    int num;
    string str;
    din >> num >> str;
    while (!din.eof() && count < NUM_WORDS)
    {
        word[count++] = str;
        din >> num >> str;
    }

    for (int i = 0; i < NUM_WORDS; i++){
        cout<<i<<" "<<word[i]<<endl;
    }
    din.close();
}

//-----------------------------------------------------------
// Look up words in dictionary
//-----------------------------------------------------------
bool Dictionary::Lookup(string str)
{
    // Search word array for string
    bool found = false;
    for (int i = 0; i < count; i++)
        if (word[i] == str)
            found = true;
    return found;
}