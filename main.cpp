#include <iostream>
#include <fstream>
#include <string>
#include "binarySearchTree.h"
using namespace std;

const int BIRTHLENGTH = 10;	//yyyy-mm-dd has total length of 10 (idk if we can do that)
int main() {
	BinaryTree<string> birthTree;
	BinaryTree<string> nameTree;

	string name;
	ifstream infile;
	ofstream outfile_1, outfile_2;

	cout << "Please enter the file name: ";
	cin >> name;
	infile.open(name);
	if(infile){
		while (infile) {				//somehow has to read two consecutive lines since name->birthday IDK HOW THO
			std::string line;
			getline(infile, line);

			
		}
		
		infile.close();
	}
	else
		cout << "Your file could not be found" << endl;
}