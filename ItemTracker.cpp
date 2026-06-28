#include "ItemTracker.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Constructor initializes data file reading and backup automatically
ItemTracker::ItemTracker(const std::string& inputFileName) {
    loadData(inputFileName);
    createBackupFile("frequency.dat");
}

// Private method to read input text file and accumulate frequency counts
void ItemTracker::loadData(const string& inputFileName) {
    ifstream inputFile(inputFileName);
    string item;

    // Error handling if input file is missing
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open input file: " << inputFileName << endl;
        return;
    }

    // Read file word-by-word until EOF
    while (inputFile >> item) {
        // Convert file word to lowercase
        for (int i = 0; i < item.length(); ++i) {
            item[i] = tolower(item[i]);
        }
        // Increment the count for the item in the map
        itemFrequencies[item]++;
    }

    inputFile.close();
}

// Private method to generate the required frequency.dat file at startup
void ItemTracker::createBackupFile(const string& outputFileName) {
    ofstream outputFile(outputFileName);

    if (!outputFile.is_open()) {
        cerr << "Error: Could not create backup file." << endl;
        return;
    }

    // Iterate through map elements and write to file
    for (const auto& pair : itemFrequencies) {
        outputFile << pair.first << " " << pair.second << endl;
    }

    outputFile.close();
}

// Public method to look up a single specific item (Option 1)
int ItemTracker::getItemFrequency(const string& item) {
    // Convert user search input to lowercase
    string searchLower = item;
    for (int i = 0; i < searchLower.length(); ++i) {
        searchLower[i] = tolower(searchLower[i]);
    }

    // Exact match check
    if (itemFrequencies.find(searchLower) != itemFrequencies.end()) {
        return itemFrequencies[searchLower];
    }

    // Substring check (handles singular vs plural variations)
    std::map<std::string, int>::const_iterator it;
    for (it = itemFrequencies.begin(); it != itemFrequencies.end(); ++it) {
        string currentKey = it->first;

        // Check if the search term lives inside the map key string
        if (currentKey.find(searchLower) != std::string::npos) {
            return it->second;
        }
    }

    return 0; 
}

// Public method to print all records numerically (Option 2)
void ItemTracker::printAllFrequencies() {
    cout << "\n--- Item Frequencies ---" << endl;
    for (const auto& pair : itemFrequencies) {
        cout << left << setw(15) << pair.first << pair.second << endl;
    }
}

// Public method to output the text-based histogram (Option 3)
void ItemTracker::printHistogram() {
    cout << "\n--- Item Histogram ---" << endl;
    for (const auto& pair : itemFrequencies) {
        cout << left << setw(15) << pair.first << " ";
        // Print an asterisk for each count of the item
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}