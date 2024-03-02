#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "dictionary.h"

using namespace std;

int main() {
    // Create a dictionary for ranking
    Dictionary rankDict;

    // Read the "rank.txt" file into the rank dictionary
    rankDict.ReadFile("rank.txt");

    // Create a map to store word ranks
    unordered_map<string, int> wordRanks;

    // Open the "rank.txt" file
    ifstream rankFile("rank.txt");
    if (!rankFile.is_open()) {
        cerr << "Error: Could not open rank.txt." << endl;
        return 1;
    }

    string line;
    int rank = 1; // Initialize the rank to 1
    while (getline(rankFile, line)) {
        string word;
        size_t pos = line.find(' ');

        if (pos != string::npos) {
            // Extract the word from the line
            word = line.substr(pos + 1);

            // Convert word to lowercase
            for (char& c : word) {
                c = tolower(c);
            }

            // Store the rank of the word in the map (adjusted by subtracting 1)
            wordRanks[word] = rank - 1;
        }

        rank++; // Increment the rank for the next word
    }

    rankFile.close();

    // Prompt the user to enter a word
    string userWord;
    cout << "Enter a word to see its rank (lowercase): ";
    cin >> userWord;

    // Convert user input to lowercase
    for (char& c : userWord) {
        c = tolower(c);
    }

    // Look up the rank of the user's input word
    if (wordRanks.find(userWord) != wordRanks.end()) {
        int rank = wordRanks[userWord];
        cout << "Rank of '" << userWord << "': " << rank << endl;
    } else {
        cout << "'" << userWord << "' not found in the dictionary." << endl;
    }

    return 0;
}

