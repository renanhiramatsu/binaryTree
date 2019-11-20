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
	Person();
	Person(std::string, std::string);

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


Person::Person(std::string name, std::string bday) {
	std::cout << bday << std::endl;
	int pos1;
	int l = name.length();
	pos1 = name.find(" ", 0);
	fName = name.substr(0, pos1);
	lName = name.substr(pos1 + 1, l - pos1);

	int pos2, pos3;
	int length2 = bday.length();
	pos2 = bday.find("-", 0);
	bYear = stoi(bday.substr(0, pos2));
	pos2++;
	pos3 = bday.find("-", pos2);
	bMonth = stoi(bday.substr(pos2, length2 - pos3));
	bDate = stoi(bday.substr(pos3 + 1, length2));
	std::cout << "Bdate: " << bDate << std::endl;
	std::cout << "BMONTH: " << bMonth << std::endl;
	std::cout << "BYear: " << bYear << std::endl;

	std::cout << "last name: " << lName << std::endl;
	std::cout << "first name: " << fName << std::endl;
	std::cout << std::endl;
}

void Person::setName(std::string fn, std::string ln) {
	fName = fn;
	lName = ln;
}

void Person::setBirthYMD(int bY, int bM, int bD) {
	bYear = bY;
	bMonth = bM;
	bDate = bD;
}


int Person::getBirthdate() { return bYear + bMonth + bDate; }
int Person::getBirthYear() { return bYear; }
int Person::getBirthMonth() { return bMonth; }
std::string Person::getFirstName() { return fName; }
std::string Person::getLastName() { return lName; }