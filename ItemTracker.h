#ifndef ITEM_TRACKER_H
#define ITEM_TRACKER_H

#include <string>
#include <map>

class ItemTracker {
private:
    // Map to store item names as keys and their frequency count as values
    std::map<std::string, int> itemFrequencies;

    // Helper method to read the raw input file and populate the map
    void loadData(const std::string& inputFileName);

    // Helper method to automatically write data to frequency.dat at startup
    void createBackupFile(const std::string& outputFileName);

public:
    // Constructor accepts the input file name and handles file tasks right away
    ItemTracker(const std::string& inputFileName);

    // Menu Option 1: Search for a specific item's frequency
    int getItemFrequency(const std::string& item);

    // Menu Option 2: Print list of all items with their numerical frequency
    void printAllFrequencies();

    // Menu Option 3: Print text-based histogram using asterisks
    void printHistogram();
};

#endif
