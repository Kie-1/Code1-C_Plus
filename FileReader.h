/*
 * FileReader.h
 *
 *  Date: 10/13/2025
 *  Author: Kieh Stevenson
 */

 /*
 This is the header, all comments are included in .cpp files. The header is for all .cpp files.
 */
#ifndef FILE_READER_H
#define FILE_READER_H


#include <string>
#include <fstream>
#include <map> // A data container called 'map'.
#include <vector>

using namespace std;

class FileReader // A object called 'FileReader'
{
public: // Contains functions and constructor.
	FileReader();
	void userInput();
	void lineChar(char c, int spaces);
	void printMenu();
	int singleItemSearch(string wordSearch);
	void multipleItemSearchNumber();
	void multipleItemSearchHistogram();


private: // Contains functions, variables, and certain #include items.
	void fileBackup();
	ifstream inFile;
	ofstream outFile;
	map<string, int> itemFrequency;
	vector<string> wordData;

};


#endif
