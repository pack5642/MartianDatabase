#include <iostream>
#include <algorithm>
#include <iostream>
#include "Martian.h"

using namespace std;

Martian add()
{
	string fname, lname;
	int SSN;
	cout << "Please enter the martians first name: " << endl;
	cin >> fname;
	cout << "Please enter the martians last name: " << endl;
	cin >> lname;
	cout << "Please enter the Martian Social Security Number: " << endl;
	cin >> SSN;
	if (cin.fail())
	{
		cout << "Error! Try Again" << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		add();
	}
	Martian New(fname, lname, SSN);
	return New;
}
string getFilename() {
	string filename;
	cout << "Please enter the file name: ";
	getline(std::cin, filename);
	return filename;
}
bool optionSelect(int &option) {

	cout << "***************" << endl;
	cout << "What would you like to do?" << endl;
	cout << "1-Add a Martian     2-Delete a Martian  3-Print all the Martians" << endl;
	cout << "***************" << endl;
	cin >> option;
	if (option == 1 || option == 2 || option == 3)
		return true;
	else
		optionSelect(option);
}

int main() {
	int option;
	//MartianDatabase *Database = new MartianDatabase(getFilename());
	//MartianDatabase theDatabase( *Database);
	MartianDatabase theDatabase(getFilename());
	while (optionSelect(option))
	{
		switch (option)
		{
		case 1:
			//ADD MARTIAN
			theDatabase.addMartian(add());
			break;
		case 2:
			theDatabase.deleteMartian(theDatabase.printOriginal());
			break;
		case 3:
			theDatabase.printMartians();
			//cout << "Does nothing for now" << endl;
			break;
		}
	}


}

