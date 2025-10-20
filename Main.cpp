/*
 * Main.cpp
 *
 *  Date: 10/13/2025
 *  Author: Kieh Stevenson
 */
#include "FileReader.h"

using namespace std;

int main() {

	auto fileReader = make_unique<FileReader>(); // Auto memory management and pointer of object 'FileReader'.

	fileReader->userInput(); // Start 'userInput'.

	return 1;
}