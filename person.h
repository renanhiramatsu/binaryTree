#pragma once
#include <string>

class Person {
private:
	std::string fName;
	std::string lName;
	std::string birthday;
	std::string fullName;
public:

	//constructors
	Person();
	Person(std::string, std::string);

	//setters
	void setName(std::string fn, std::string ln);
	void setBirthDate(std::string);

	//getters
	std::string getBirthdate();
	std::string getFirstName();
	std::string getLastName();
	std::string getFullName();
	bool operator == (const  Person&);
};

//default constructor
Person::Person() {
	fName = " ";
	lName = " ";
	birthday = " ";
}

//overloaded constructor
Person::Person(std::string name, std::string bday) {
	//std::cout << bday << std::endl;
	int pos1;
	int l = name.length();
	pos1 = name.find(" ", 0);
	fName = name.substr(0, pos1);
	lName = name.substr(pos1 + 1, l - pos1);
	fullName = fName + " " + lName;
	birthday = bday;
}

void Person::setName(std::string fn, std::string ln) {
	fName = fn;
	lName = ln;
}

void Person::setBirthDate(std::string bday) {
	birthday = bday;
}

//getter definitions
std::string Person::getBirthdate() { return birthday; }
std::string Person::getFirstName() { return fName; }
std::string Person::getLastName() { return lName; }
std::string Person::getFullName() { return fullName; }

bool Person::operator == (const Person& right) {
	if (this->fullName == right.fullName && this->birthday == right.birthday)
		return true;
	else
		return false;
}
