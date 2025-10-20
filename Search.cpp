/*
 * Search.cpp
 *
 *  Date: 10/13/2025
 *  Author: Kieh Stevenson
 */
#include <iostream>
#include <string>
#include "FileReader.h"

using namespace	std;
// Searches just one item.
int FileReader::singleItemSearch(string wordSearch) {
	wordSearch.at(0) = toupper(wordSearch.at(0)); // Makes sure the word is able to match the choice. (Apple or apple, will work here).
	if (this->itemFrequency.count(wordSearch) == 1) {
		return this->itemFrequency.at(wordSearch); // Uses the 'map' count to check if item exists, and selects that item with 'vector'.
	}
	else 
		cout << "This item does not exist.\n"; // The item does not exist.
	return 0;

}
// Prints out all of the items from the file via 'map' and 'vector'.
void FileReader::multipleItemSearchNumber() {

	for (string word : this->wordData) { // A 'range loop', used to simplify the code.
		cout << word << ' ' << this->itemFrequency.at(word) << endl; // Prints out the name and the frequency.
	}

}
// Prints out all of the items from file with 'map' and 'vector', instead turning integer into histogram.
void FileReader::multipleItemSearchHistogram() {

	for (string word : this->wordData) { // A 'range loop', used to simplify the code. 
		cout << word << ' '; // Code split up because of function.
		this->lineChar('*', this->itemFrequency.at(word)); // Using function 'lineChar' to output histogram.
		cout << endl;
	}

}