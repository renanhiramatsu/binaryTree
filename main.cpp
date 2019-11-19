#include <iostream>
#include <fstream>
#include <string>
#include "binarySearchTree.h"
#include "pple.h"
//#include "treeNode.h"

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

	BinaryTree<int> tree;


	int data = 3;

	tree.insertNode(data);

	//tree.displayInOrder();



	//BinaryTree<string> *birthTree;
	//BinaryTree<string> nameTree;
	//TreeNode<string> *tree = new TreeNode<string>;

	//string name;
	//ifstream infile;
	//ofstream outfile_n, outfile_b;

	//outfile_n.open("NamesOutput.txt");
	//outfile_b.open("BirthdaysOutput.txt");

	//int i;
	//string birthStr[99], nameStr[99];

	////cout << "Please insert the path for the InputFile.txt file: ";

	//infile.open(fileName);					// TODO: ADD DIRECT PATH
	//if (infile.is_open()) {
	//	for (i = 0; !infile.eof(); i++) {			//somehow has to read two consecutive lines since name->birthday IDK HOW THO
	//		//std::string line;
	//		//getline(infile, line);

	//		getline(infile, nameStr[i]);
	//		getline(infile, birthStr[i]);

	//	}



	////-------------------------------------  NAME FILE INPUT (pre & post) ------------------------------//
	//outfile_n << "Names File:" << endl;
	//cout << "Names File:" << endl;

	//for (int j = 0; j < i; j++) {
	//	cout << "Name: " << nameStr[j] << "\tBirthday: " << birthStr[j] << endl;
	//	outfile_n << "Name: " << nameStr[j] << "\tBirthday: " << birthStr[j] << endl;
	//	//tree->insert(tree, nameStr[j]);
	//}

	//cout << "Post-Order for Names: " << endl;
	//outfile_n << "Post-Order Names: " << endl;

	////nameTree.printPostorder();
	////outfile_n << nameTree.ouPostorder();

	////nameTree.ouEmpty(); //empty string

	//cout << "Pre-Order for names: " << endl;
	//outfile_n << "\nPre-Order Names: " << endl;

	////nameTree.printPreorder();
	////noufile << nameTree.ouPreorder();

	////nameTree.ouEmpty();





	////-------------------------------------  BIRTHDAY FILE INPUT (in-order)------------------------------//
	//outfile_b << "Birthday File:" << endl;
	//cout << "Birthday File:" << endl;


	//for (int j = 0; j < i; j++) {
	//	cout << "Name: " << nameStr[j] << "\tBirthday: " << birthStr[j] << endl;
	//	outfile_b << "Name: " << nameStr[j] << "\tBirthday: " << birthStr[j] << endl;
	//	//	name.insert(nameStr[j]);
	//}



	//cout << "In-Order for Birthdays: " << endl;
	//outfile_b << "In-Order Birthdays: " << endl;

	////birthTree.printInorder();
	////outfile_b << birthTree.ouInorder();

	////birthTree.ouEmpty();

	//cout << "Breadth-First for Birthdays: " << endl;
	//outfile_b << "\nBreadth-First Birthdays: " << endl;

	////birthTree.printBFirst();
	////outfile_b << birthTree.ouBFirst();


	//	infile.close();
	//}
	//else
	//	cout << "Your file could not be found" << endl;


	//outfile_b.close();
	//outfile_n.close();

	system("pause");
}