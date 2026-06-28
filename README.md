# Corner-Grocer-Item-Tracker
Inventory item tracker for a grocery store

#Project Summary:
The Corner Grocer Item Tracker is a C++ application designed to solve an inventory analysis problem for a local supermarket. The program parses an unstructured text file containing a daily record of item purchases, calculates the frequency of each item sold, and stores this data efficiently. It provides a text-based menu interface allowing users to look up specific item frequencies, view a complete list of daily items with their numerical counts, and output a visual histogram of purchasing trends. Additionally, it automatically backs up the frequency data to a file (frequency.dat) upon execution to ensure data persistence.

#Design & Data Structures: 
A tool called a Map was selected for this project because it stores unique pairs which are sorted automatically by key (alphabetically by item name). It provides an efficient means to search, insert, and delete items. The map also allows the program to look up any item instantly, no matter how large the store's daily text file grows.

#File Interactivity & Security: 
Before the user even sees the main menu, the code opens the item list text file, reads all the items, and converts them to lowercase so there are no capitalization mismatches. To make sure the program doesn't crash if a file is missing, it runs a quick check first. Once the data is read, it instantly creates the frequency.dat backup file on your computer without requiring the user to make this happen. 

#Input Validation: 
This program asks a user to type a number between 1 and 4. There is a risk that they will  type a word like “one” or a symbol instead. Without intervention this type mismatch causes a total system lockup or an infinite loop. To prevent this, I built a safety net into the menu. If the user enters data that does not match the right criteria, the program catches the mistake, resets the input line, clears out the broken text, and asks them to try again. 

#Areas for Enhancement:
Input validation could be taken a step further by catching bad user input of a character during menu selection. File handling and security could also be improved by adding explicit checks to verify that the input file exists and is not corrupted before attempting data extraction.

#Transferable Skills:
Algorithmic Data Mapping: The logic used to pair item names with counts in a map directly.
Stream-Based Logic: Understanding how data flows from a physical file, into a localized stream, and out to a user display.

#Readability, Maintainability, and Adaptability:
Readability: Followed a strict, descriptive naming convention for all variables.
Maintainability: Kept the logical functions clean and separated. Loops are constrained with explicit boundary checks, and I opted for clear if/else blocks to control flow and keep code structure predictable.
Adaptability: Built the program to avoid fixed-size arrays in favor of dynamic STL containers. This allows the system to instantly scale from tracking 10 items to 10,000 items, processing high-volume inventory scenarios without needing any updates to the source code.



