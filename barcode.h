#ifndef BARCODE_H_
#define BARCODE_H_

#include <iostream>
#include <string>

struct bar {
	std::string name;
	int count = 1;

	friend std::ostream& operator<< (std::ostream& os, bar& rhs) {
		return os << rhs.name << ": " << rhs.id();
	}


	bar() {
		name = "-1";
	}

	bar(std::string _name) :name(_name) {
		return;
	}

	bar(std::string _name, int _count) :name(_name), count(_count) {
		return;
	}

	int id() {
		return stoi(name);
	}
};

/*
bool operator>(bar& lhs, bar& rhs) {
	if (lhs.id() > rhs.id()) return true;
	return false;
}

bool operator>= (bar& lhs, bar& rhs) {
	if (lhs.id() >= rhs.id()) return true;
	return false;
}

bool operator< (bar& lhs, bar& rhs) {
	if (lhs.id() <= rhs.id()) return true;
	return false;
}

bool operator<= (bar& lhs, bar& rhs) {
	if (lhs.id() <= rhs.id()) return true;
	return false;
}
*/
#endif // BARCODE_H_
