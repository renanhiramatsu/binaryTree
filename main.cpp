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
	ifstream infile;
	ofstream outfile_n, outfile_b;

	outfile_n.open("NamesOutput.txt");
	outfile_b.open("BirthdaysOutput.txt");

	Person someone[99];
	string birthStr[99], fnameStr[99], lnameStr[99], filePath;

	int i, opt;

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
		for (i = 0; !infile.eof(); i++) {

			// reads fname and lname from file and store in data members
			getline(infile, fnameStr[i], ' ');
			getline(infile, lnameStr[i], '\n');
			someone[i].setName(fnameStr[i], lnameStr[i]);

			// reads birthday and stores it
			getline(infile, birthStr[i]);
			someone[i].setBirthDate(birthStr[i]);

		}


		//-------------------------------------  NAME FILE INPUT (pre & post) ------------------------------//
		outfile_n << "================= Names File =================" << endl;
		cout << "================= Names File =================" << endl;

		for (int j = 0; j < i; j++) {
			cout << "Name: " << fnameStr[j] << "\tBirthday: " << birthStr[j] << endl;
			outfile_n << "Name: " << fnameStr[j] << "\tBirthday: " << birthStr[j] << endl;
			nameTree.insertNode(someone[j], "name");
		}

		cout << "*************** Pre-Order for Names *************** " << endl;
		outfile_n << "Pre-Order Names: " << endl;

		nameTree.displayPreOrder();
		//outfile_n << nameTree.displayPreOrder();		//overload <<

		//nameTree.ouEmpty(); //empty string

		cout << "*************** Post-Order for names *************** " << endl;
		outfile_n << "\nPost-Order Names: " << endl;

		nameTree.displayPostOrder();
		//noufile << nameTree.ouPreorder();

		//nameTree.ouEmpty();





		//-------------------------------------  BIRTHDAY FILE INPUT (in-order)------------------------------//
		outfile_b << "================= Birthday File =================" << endl;
		cout << "================= Birthday File =================" << endl;


		for (int j = 0; j < i; j++) {
			cout << "Name: " << fnameStr[j] << "\tBirthday: " << birthStr[j] << endl;
			outfile_b << "Name: " << fnameStr[j] << "\tBirthday: " << birthStr[j] << endl;
			birthTree.insertNode(someone[j], "birthday");
		}


		cout << "*************** In-Order for Birthdays *************** " << endl;
		outfile_b << "In-Order Birthdays: " << endl;

		birthTree.displayInOrder();
		//outfile_b << birthTree.ouInorder();

		//birthTree.ouEmpty();

		cout << "*************** Breadth-First for Birthdays: ***************" << endl;
		outfile_b << "\nBreadth-First Birthdays: " << endl;
		//birthTree.displayBreadthFirst();
		//birthTree.printBFirst();
		//outfile_b << birthTree.ouBFirst();


		infile.close();
	}
	else
		cout << "Your file could not be found" << endl;


	outfile_b.close();
	outfile_n.close();

	system("pause");


}