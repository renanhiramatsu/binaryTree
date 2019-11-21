/*
partners:
	Renan Silva Hiramatsu
	Amber Low
this lab demonstrates the use of different functions
through the binary search tree. 
ask user for entire file path
if file exists
	search through each entry and create a new person
	add onto the correct birthday or name tree
	traverse and display trees in main and separate outfiles using:	
			pre order
			post order
			in order
			breadthfirst
	demonstrate remove and search
	close files
else
	display message saying the file couldnt be found
*/




#include <iostream>
#include <fstream>

#include "binaryTree.h"
#include "person.h"
#include <string>
using namespace std;

const string fileName = "InputFile.txt";


int main() {

	BinaryTree<Person> birthTree("birthday");
	BinaryTree<Person> nameTree("name");

	string name;
	string bday;
	string filePath;
	int opt;

	ifstream infile;
	ofstream outfile_n, outfile_b;

	outfile_n.open("NamesOutput.txt");
	outfile_b.open("BirthdaysOutput.txt");



	cout << "Press (1) to type the input file path or (2) to use the project folder file:\n";
	cin >> opt;
	cin.ignore();

	if (opt == 1) {
		cout << "Please insert the path for the InputFile.txt file: ";
		getline(cin, filePath);
	}
	else
		filePath = fileName;

	infile.open(filePath);


	if (infile.is_open()) {
		while (!infile.eof()) {
			getline(infile, name);
			getline(infile, bday);
			Person human(name, bday);
			nameTree.insertNode(human, "name");
			birthTree.insertNode(human, "birthday");

		}
		//displayAll(nameTree, birthTree);
		cout << "-------------------------------------------------------" << endl;
		cout << "____________________PRE ORDER NAMES____________________ " << endl;
		nameTree.displayPreOrder();
		cout << "-------------------------------------------------------" << endl;


		cout << endl;

		cout << "-------------------------------------------------------" << endl;
		cout << "___________________POST ORDER NAMES____________________ " << endl;
		nameTree.displayPostOrder();
		cout << "-------------------------------------------------------" << endl;

		cout << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << "__________________IN ORDER BIRTHDAYS___________________ " << endl;
		birthTree.displayInOrder();
		cout << "-------------------------------------------------------" << endl;

		cout << endl;

		cout << "-------------------------------------------------------" << endl;
		cout << "_______________BREADTHFIRST BIRTHDAYS__________________ " << endl;
		cout << "SIKE" << endl;
		//nameTree.displayBreadthFirst();
		cout << "-------------------------------------------------------" << endl;


		//demonstrating the search and remove method 
		string name = "Wallie Walnuts",
			   birthday = "1932-04-02"; 
		Person person1(name , birthday);
		cout << "TESTING SEARCH: " << endl;
		cout <<  name << " was found: " << boolalpha << nameTree.searchNode(person1) << endl;

		Person person2("Jo JackFruit", "2019-08-07");
		cout << "TESTING REMOVE : " << endl;
		nameTree.removeNode(person2);



		//int action;
		//char userInput;

		//do {
		//	cout << "Please select ur action: " << endl;
		//	cout << "1) search for entry " << endl;
		//	cout << "2) remove an entry " << endl;
		//	cin >> action;
		//	cin.ignore();
		//	if (action == 1) {
		//		string n , b;

		//		cout << "Please enter the name of the entry the way it is in the file: ";
		//		getline(cin, n);
		//		cout << "Please enter the birthday the way it is in the file: ";
		//		getline(cin, b);

		//		Person pSearch(name, bday);
		//		cout << n << " was found? : " ;
		//		cout << boolalpha << nameTree.searchNode(pSearch) << endl;

		//	}

		//	if (action == 2) {
		//		string n, b;

		//		cout << "Please enter the name of the entry the way it is in the file: ";
		//		getline(cin, n);
		//		cout << "Please enter the birthday the way it is in the file: ";
		//		getline(cin, b);

		//		Person rem(name, bday);
		//		nameTree.removeNode(rem);
		//	}
		//	cout << "enter 'q' to quit : ";
		//	cin.get(userInput);




		//} while (tolower(userInput) != 'q');

	}

	system("pause");

}
//int main() {
//
//	BinaryTree<Person> birthTree("birthday");
//	BinaryTree<Person> nameTree("name");
//
//	ifstream infile;
//	ofstream outfile_n, outfile_b;
//
//	outfile_n.open("NamesOutput.txt");
//	outfile_b.open("BirthdaysOutput.txt");
//
//	Person someone[99];
//	string birthStr[99], fnameStr[99], lnameStr[99], filePath;
//
//	int i, opt;
//
//	cout << "Press (1) to type the input file path or (2) to use the project folder file:\n";
//	cin >> opt;
//	cin.ignore();
//
//	if (opt == 1) {
//		cout << "Please insert the path for the InputFile.txt file: ";
//		getline(cin, filePath);
//	}
//	else
//		filePath = fileName;
//
//	infile.open(filePath);
//
//
//	if (infile.is_open()) {
//		for (i = 0; !infile.eof(); i++) {
//			getline(infile, fnameStr[i], ' ');
//			getline(infile, lnameStr[i], '\n');
//			someone[i].setName(fnameStr[i], lnameStr[i]);
//
//			// reads birthday and stores it
//			getline(infile, birthStr[i]);
//			someone[i].setBirthDate(birthStr[i]);
//
//		}
//
//
//		//-------------------------------------  NAME FILE INPUT (pre & post) ------------------------------//
//		outfile_n << "================= Names File =================" << endl;
//		cout << "================= Names File =================" << endl;
//
//		for (int j = 0; j < i; j++) {
//			cout << "Name: " << fnameStr[j] << "\tBirthday: " << birthStr[j] << endl;
//			outfile_n << "Name: " << fnameStr[j] << "\tBirthday: " << birthStr[j] << endl;
//			nameTree.insertNode(someone[j], "name");
//		}
//
//		cout << "*************** Pre-Order for Names *************** " << endl;
//		outfile_n << "Pre-Order Names: " << endl;
//
//		nameTree.displayPreOrder();
//		//outfile_n << nameTree.displayPreOrder();		//overload <<
//
//		//nameTree.ouEmpty(); //empty string
//
//		cout << "*************** Post-Order for names *************** " << endl;
//		outfile_n << "\nPost-Order Names: " << endl;
//
//		nameTree.displayPostOrder();
//		//noufile << nameTree.ouPreorder();
//
//		//nameTree.ouEmpty();
//
//
//
//
//
//		//-------------------------------------  BIRTHDAY FILE INPUT (in-order)------------------------------//
//		outfile_b << "================= Birthday File =================" << endl;
//		cout << "================= Birthday File =================" << endl;
//
//
//		for (int j = 0; j < i; j++) {
//			cout << "Name: " << fnameStr[j] << "\tBirthday: " << birthStr[j] << endl;
//			outfile_b << "Name: " << fnameStr[j] << "\tBirthday: " << birthStr[j] << endl;
//			birthTree.insertNode(someone[j], "birthday");
//		}
//
//
//		cout << "*************** In-Order for Birthdays *************** " << endl;
//		outfile_b << "In-Order Birthdays: " << endl;
//
//		birthTree.displayInOrder();
//		//outfile_b << birthTree.ouInorder();
//
//		//birthTree.ouEmpty();
//
//		cout << "*************** Breadth-First for Birthdays: ***************" << endl;
//		outfile_b << "\nBreadth-First Birthdays: " << endl;
//		//birthTree.displayBreadthFirst();
//		//birthTree.printBFirst();
//		//outfile_b << birthTree.ouBFirst();
//		Person dude;
//		cout << "TESTING REMOVE: " << endl;
//		//birthTree.removeNode(dude);
//		birthTree.searchNode(dude, "birthday");
//
//		infile.close();
//	}
//	else
//		cout << "Your file could not be found" << endl;
//
//
//	outfile_b.close();
//	outfile_n.close();
//
//	system("pause");
//
//
//}