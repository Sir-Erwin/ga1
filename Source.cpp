#include <iostream>
#include <fstream>

#include "ArgumentManager.h"

#include "DLinkedList.h"
#include "barcode.h"

#include "decoder.h"

#include "ga1_printing.h"

using namespace std;

DLinkedList<> bar1;
DLinkedList<> bar2;

ifstream inp;
ofstream out;

bool add(int _case, string encoded) {
	bool success = false;
	string decoded;
	bar barcode;

	// decode method from "decoder.h"
	try {
		decoded = decode(encoded);
	}
	catch (exception e) {
		cout << "IN ADD FUNCTION : " << e.what() << endl;
	}

	// Making new bar object from "barcode.h
	try {
		barcode = *(new bar(decoded));
	}
	catch (exception e) {
		cout << "IN ADD FUNCTION : " << e.what() << endl;
	}

	if (_case == 1) {
		bar1.add(barcode);
		success = true;
	} 

	else if (_case == 2) {
		bar2.add(barcode);
		success = true;
	}

	else {
		success = false;
	}

	return success;
}

bool getInput() {
	bool success = false;

	if (inp.peek() == 0) 
		return success;

	string line; int _case = 0;
	while (!inp.eof()) {
		inp >> line;

		if (!isdigit(line[0]) && line[0] != '(' && line[0] != ')') { // Bar1 or Bar2
			_case = stoi(line.substr(line.size()-1));
		}
		else { // Encoded ID
			success = add(_case, line);

			if (!success){
				cout << "\n\nERROR: ADDING DIDN'T WORK\n\n";
				return success; 
			}
		}
	}
	return success;
}

bool print() {
	DLinkedList<> full = bar1;
	full.getTail()->next = bar2.getHead();
	printInnocentRecursive(full.getHead());
	return true;
}

int main(int argc, char* argv[]) {
	ArgumentManager am(argc, argv);
	//string input = am.get("input");
	//string output = am.get("output");

	string input = "input1.txt";
	string output = "output.txt";

	inp.open(input);
	out.open(output);

	main3();

	//getInput();

	//print();

	return 0;
}