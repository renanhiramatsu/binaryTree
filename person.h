#pragma once
#include <string>

class Person {
private:
	std::string fName;
	std::string lName;
	int bMonth;
	int bDate;
	int bYear;
	Person* left;
	Person* right;
public:
	Person() {};
	Person(std::string, std::string, int, int, int);
	void setName(std::string n);
	void setBirthdate(int bM, int bD, int bY);

	std::string getBirthdate();
	std::string getName();
};
Person::Person() {
	fName = " ";
	lName = " ";
	bMonth = 0;
	bDate = 0;
	bYear = 0;
	left = nullptr;
	right = nullptr;
}

Person::Person(std::string fn, std::string ln, int bm, int bd, int by) {
	fName = fn;
	lName = ln;
	bMonth = bm;
	bDate = bd;
	bYear = by;
	//pointers?
}

std::string Person::getBirthdate() {
	
}
std::string Person::getName() {
}