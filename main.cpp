#include <iostream>
#include <fstream>
#include <string>
#include "binarySearchTree.h"
#include "people.h"

using namespace std;

const int BIRTHLENGTH = 10;	//yyyy-mm-dd has total length of 10 (idk if we can do that)
const string fileName = "InputFile.txt";

int main() {

/*

sketch:
		100                             
		/ \        
		20     500    
		/ \ / \
		10   30                           
		\
		40


*/

	Person me;

	BinaryTree<string> birthTree;
	BinaryTree<string> nameTree;

	string name;
	ifstream infile;
	ofstream outfile_n, outfile_b;

	outfile_n.open("NamesOutput.txt");
	outfile_b.open("BirthdaysOutput.txt");

	string birthStr[99], nameStr[99], filePath;

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
			getline(infile, nameStr[i]);
			getline(infile, birthStr[i]);

		}


	//-------------------------------------  NAME FILE INPUT (pre & post) ------------------------------//
	outfile_n << "================= Names File =================" << endl;
	cout << "================= Names File =================" << endl;

	for (int j = 0; j < i; j++) {
		cout << "Name: " << nameStr[j] << "\tBirthday: " << birthStr[j] << endl;
		outfile_n << "Name: " << nameStr[j] << "\tBirthday: " << birthStr[j] << endl;
		nameTree.insertNode(nameStr[j]);
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
		cout << "Name: " << nameStr[j] << "\tBirthday: " << birthStr[j] << endl;
		outfile_b << "Name: " << nameStr[j] << "\tBirthday: " << birthStr[j] << endl;
		birthTree.insertNode(birthStr[j]);
	}


	cout << "*************** In-Order for Birthdays *************** " << endl;
	outfile_b << "In-Order Birthdays: " << endl;

	birthTree.displayInOrder();
	//outfile_b << birthTree.ouInorder();

	//birthTree.ouEmpty();

	cout << "*************** Breadth-First for Birthdays: ***************" << endl;
	outfile_b << "\nBreadth-First Birthdays: " << endl;

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