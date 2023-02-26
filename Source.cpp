#include <iostream>
#include <fstream>

#include "ArgumentManager.h"

#include "DLinkedList.h"
#include "barcode.h"

#include "decoder.h"

//#include "ga1_printing.h"

using namespace std;

DLinkedList<> bar1;
//DLinkedList<> bar2;

ifstream inp;
ofstream out;

//Change when decode function is ready
bool add(int _case, string encoded) { 
	bool success = false;
	string decoded = encoded;
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
		bar1.add(barcode);
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

stringstream guilty;
template<typename T = bar>
void printGuiltyRecursive(Node<T>* curr) {
	if (curr == nullptr)
		return;
	if (curr->data.count > 1)
		guilty << curr->data.name << endl;
	printGuiltyRecursive(curr->next);
}

stringstream innoc;
template<typename T = bar>
void printInnocentRecursive(Node<T>* curr) {
	if (curr == nullptr)
		return;
	if (curr->data.count <= 1)
		innoc << curr->data.name << endl; // << "--" << curr->data.count
	printInnocentRecursive(curr->next);
}

void printAll(Node<>* curr) {
	if (curr == 0)
		return;

	cout << curr->data.name << "--" << curr->data.count << endl;
	printAll(curr->next);
}

void printAll() {
	printAll(bar1.getHead());
}

bool print() {

	printGuiltyRecursive(bar1.getHead());
	if(guilty.str().size() > 0)
		out << "Guilty:\n" << guilty.str().substr(0, guilty.str().size()-1) << endl;

	printInnocentRecursive(bar1.getHead());
	if(innoc.str().size() > 0)
		out << "Innocent:\n" << innoc.str().substr(0, innoc.str().size() - 1) << endl;
	
	return true;
}

// Just for Testing Purposes
/*
void linkTester() {
	DLinkedList<> link;
	link.add("A"); link.add("B"); link.add("C"); link.add("D"); link.add("E");
	
	printInnocentRecursive(link.getHead());
}
*/

int main(int argc, char* argv[]) {
	ArgumentManager am(argc, argv);
	string input = am.get("input");
	string output = am.get("output");

	//string input = "input3.txt";
	//string output = "output.txt";

	inp.open(input);
	out.open(output);

	//linkTester();
	//main3(); //Decoder

	getInput();

	//Sort
	bar1.RecurBubbleSort();

	bar1.checkDuplicates();

	print();

	inp.close();
	out.close();

	return 0;
}