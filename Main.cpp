#include <iostream>
#include <string>
#include "ItemTracker.h"

using namespace std;

// Helper function to print the text interface menu options
void displayMenu() {
    cout << "\n=====================================" << endl;
    cout << "     Corner Grocer Item Tracker      " << endl;
    cout << "=====================================" << endl;
    cout << "1. Search for an item frequency" << endl;
    cout << "2. Print all items and frequencies" << endl;
    cout << "3. Print graphic item histogram" << endl;
    cout << "4. Exit program" << endl;
    cout << "Enter your choice (1-4): ";
}

int main() {
    // Instantiate the tracker object with the target source text file
    ItemTracker tracker("CS210_Project_Three_Input_File.txt");
    int choice = 0;
    string searchItem;

    // Core application menu loop
    while (choice != 4) {
        displayMenu();

        // Input validation to handle non-integer menu selections safely
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            cin.clear();           // Clear error state flag
            cin.ignore(100, '\n'); // Purge input buffer
            continue;
        }

        switch (choice) {
        case 1:
            cout << "Enter the item name to search: ";
            cin >> searchItem;
            cout << searchItem << " was purchased "
                << tracker.getItemFrequency(searchItem) << " times." << endl;
            break;

        case 2:
            tracker.printAllFrequencies();
            break;

        case 3:
            tracker.printHistogram();
            break;

        case 4:
            cout << "Exiting program. Backup saved successfully to frequency.dat." << endl;
            break;

        default:
            cout << "Invalid choice. Please pick an option from 1 to 4." << endl;
            break;
        }
    }

    return 0;
}