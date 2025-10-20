/*
 * FileReader.cpp
 *
 *  Date: 10/13/2025
 *  Author: Kieh Stevenson
 */
#include <iostream>
#include <string>
#include "FileReader.h"

using namespace std;
// Constructor backs the file, right at the beginning of the code.
FileReader::FileReader() {
	fileBackup(); // 'fileBackup' function, private.
}
// This function 'fileBackup' moves the data in one file to the other file.
// It also inserts data into a 'map' holder and a 'vector' holder
void FileReader::fileBackup() {

	string tempData = "nil"; // Used to collect the strings.
	
	this->inFile.open("CS210_Project_Three_Input_File.txt"); // Open read file.

	if (!this->inFile.is_open()) cout << "File did not open.\n"; // Testing if its open.
	
	while (getline(this->inFile, tempData)) { // The 'getline' is in the loop, until there is no more string data
		if (this->itemFrequency.count(tempData) == 0) { // If the data doesn't exist in 'map', then add it.
			this->itemFrequency.emplace(tempData, 1); // Inserts the data string with a value.
			this->wordData.push_back(tempData); // Inserts into 'vector', required to access 'map'.
		}
		else if (this->itemFrequency.count(tempData) == 1) // Does exist in the 'map' data.
			this->itemFrequency.at(tempData)++; // Add the integer inside of the 'map', accessed via string.
	}

	this->inFile.close(); // Close

	this->outFile.open("frequency.dat"); // Open the new file to write. Or create a new file to write.

	for (string tempData : this->wordData) { // This writes to the writing file.
		outFile << tempData << ' ' << this->itemFrequency.at(tempData) << '\n'; 
	}

	this->outFile.close(); // Close

	return;
}

// 'charLine' function outputs a line of chars.
void FileReader::lineChar(char c,int spaces) {
	for (int i = 0; i < spaces; i++) {
		cout << c;
	}
}
// A 'printMenu', for the user to read and understand how to use.
void FileReader::printMenu() {

	lineChar('=', 40); // Previous function called 'lineChar'.
	cout << "\n- Option 1: Specific item search\n\n";
	cout << "\n- Option 2: Print list, with item frequencies\n\n";
	cout << "\n- Option 3: Print a histogram, with item frequencies\n\n";
	cout << "\n- Option 4: Quit program\n\n";
	lineChar('=', 40); // Previous function called 'lineChar'.

}

// The 'userInput' function, for accepting user input.
void FileReader::userInput() {

	int keyNum = 0; // The key for selecting options.
	int itemNumber; // Used for the single search.
	string itemName; // Also used for single search.

	while (keyNum != 4) { // Typing in 4 ends the loop.

		printMenu(); // Menu printed.

		cout << "\nPlease choose a menu option: \n";

		try { // A try container, used in-case the user types anything but a integer.
			cin >> keyNum;
			if (cin.fail()) throw invalid_argument("Not a valid input, please try again."); // Goes to catch with written statement.
		}
		catch(invalid_argument e) { // With already written text, the user is told the input was invalid.
			cout << e.what() << endl;
			cin.clear(); // Clear the error.
			cin.ignore(); // Ignore previous input entirely.
			continue; // Go back to start of loop.
		}

		switch (keyNum) { // A 'switch' for menu options.

		case 1: // This is for single search, for selecting one item only. Returns a number and outputs it.
			cout << "Enter the item's name:\n";
			cin >> itemName;
			itemNumber = singleItemSearch(itemName);
			cout << itemNumber << endl;
			break;

		case 2: // Prints out all items from the file with numbers.
			multipleItemSearchNumber();
			break;

		case 3: // Prints out all itmes from the file, instead with a histogram.
			multipleItemSearchHistogram();
			break;
		
		case 4: // Quit the loop entirely, return.
			return;
			break;

		default: // Any other number not included.
			cout << "Not a valid option\n";
			break;
		}

	}
	

	return;
}