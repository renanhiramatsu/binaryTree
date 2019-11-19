#pragma once
#include <string>

class Person {
private:
	std::string fName;
	std::string lName;
	int bMonth;
	int bDate;
	int bYear;

public:

	//constructors
	Person() {};
	Person(std::string, std::string, int, int, int);

	//setters
	void setName(std::string fn, std::string ln);
	void setBirthYMD(int bY, int bM, int bD);
	
	//getters
	int getBirthdate();
	int getBirthYear();
	int getBirthMonth();
	std::string getFirstName();
	std::string getLastName();
};
Person::Person() {
	fName = " ";
	lName = " ";
	bMonth = 0;
	bDate = 0;
	bYear = 0;
}


Person::Person(std::string fn, std::string ln, int bm, int bd, int by) {
	fName = fn;
	lName = ln;
	bMonth = bm;
	bDate = bd;
	bYear = by;
}

void Person::setName(std::string fn, std::string ln) {
	fName = fn;
	lName = ln;
}

void Person:: setBirthYMD(int bY, int bM, int bD) {
	bYear = bY;
	bMonth = bM;
	bDate = bD;
}


int Person::getBirthdate() { return bDate; }
int Person::getBirthYear() { return bYear; }
int Person::getBirthMonth() { return bMonth; }
std::string Person::getFirstName() { return fName;}
std::string Person::getLastName() { return lName; }