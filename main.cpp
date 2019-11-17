#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream infile;
	infile.open("InputData.txt");
	if (infile) {

	}
	else
		cout << "Your file could not be found" << endl;
}