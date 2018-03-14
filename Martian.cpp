#include "Martian.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>

MartianDatabase::MartianDatabase(std::string filename) {
	std::ifstream fin;
	std::string fname, lname;
	int social;
	fin.open(filename);
	if (fin.fail())
	{
		std::cout << "Bad file!" << std::endl;
		exit(0);
	}
	else
		while (!fin.eof())
		{
			fin >> lname;
			fin >> fname;
			fin >> social;
			Martian fresh(fname, lname, social);
			addMartian(fresh);
		}
	
}
void MartianDatabase::addMartian(Martian m) {
	if (isFull())
	{
		std::cout << "Database full, please delete some data";
		return;
	}
	else
	{
		original[numMartians] = m;
		f_name[numMartians] = &original[numMartians];
		l_Name[numMartians]= &original[numMartians];
		SSN[numMartians]= &original[numMartians];
		numMartians++;
	}
}

bool MartianDatabase::deleteMartian(Martian m) {
	if (isEmpty())
	{
		std::cout << "Database is empty" << std::endl;
		return false;
	}
	int target=0;
	Martian temp; //or Martian *temp; ???
	int temp_location;
	int end_location;
	int index = 0;
	for (int i = 0; i < numMartians; i++)
	{
		if (original[i] == m)
		{
			target = original[i].MSSN;
			index = i;
			temp = original[numMartians - 1];
			original[numMartians - 1] = original[index];
			original[index] = temp;
			break;
		}
	}
	if (target == 0) {
		std::cout << "Martian not found!" << std::endl;
		return false;
	}
	for (int i = 0; i < numMartians; i++)
	{
		if (f_name[i]->MSSN == target)
		{
			Martian *temp0 = f_name[numMartians - 1];
			//*temp0 = *f_name[numMartians-1];
			f_name[numMartians-1] = f_name[i]; //maybe numMartions-1
			f_name[i] = temp0;
		}
		if (l_Name[i]->MSSN == target)
		{
			Martian *temp1 = l_Name[numMartians - 1];
			//*temp1 = *l_Name[numMartians-1];
			l_Name[numMartians-1] = l_Name[i]; //maybe numMartions-1
			l_Name[i] = temp1;
			//delete l_Name[i];
		}
		if (SSN[i]->MSSN == target)
		{
			Martian *temp2 = SSN[numMartians - 1];
			//temp2 = SSN[numMartians-1];
			SSN[numMartians-1] = SSN[i]; //maybe numMartions-1
			SSN[i] = temp2;
			//swap the address for the pointers that im swapping
			//SSN[i]=

			//delete SSN[i];
		}
	}
	/*
	temp = original[numMartians - 1];
	original[numMartians-1] = original[index];
	original[index] = temp;
	*/
	numMartians--;
	return true;
}

MartianDatabase::~MartianDatabase() {
	for (int i = 0; i < MAX; i++) { //should i delete from less than MAX or numMartians
		delete f_name[i];
		delete l_Name[i];
		delete SSN[i];
	}
	//delete[]original; //this might not be necessary
	//delete[]f_name;
	//delete[]l_Name;
	//delete[]SSN;


}
bool MartianDatabase::isFull() {
	if (numMartians == MAX)
		return true;
	else
		return false;
}
bool MartianDatabase::isEmpty() {
	if (numMartians == 0)
		return true;
	else
		return false;
}
bool MartianDatabase::Fsort(Martian *r, Martian *l) {
	if (r->m_firstName < l->m_firstName)
		return true;
	else
		return false;
}
bool MartianDatabase::Lsort(Martian *r, Martian *l) {
	if (r->m_LastName < l->m_LastName)
		return true;
	else
		return false;

}
bool MartianDatabase::Ssort(Martian *r, Martian *l) {
	if (r->MSSN < l->MSSN)
		return true;
	else
		return false;
}
Martian MartianDatabase::printOriginal()
{
	std::cout << std::left;
	int index;
	std::cout << "Please choose the martian you would like to delete by the entering the number to the left of it " << std::endl;
	std::cout <<std::setw(20)<< "Last"<<std::setw(20)<< "First" <<std::setw(10)<< "  SSN" << std::endl;
	for (int i = 0; i < numMartians; i++)
	{
		std::cout << i << " " <<std::setw(20)<< this->original[i].m_LastName << " " <<std::setw(20)<< this->original[i].m_firstName << " " <<std::setw(10)<< this->original[i].MSSN << std::endl;
	}
	std::cin >> index;
	while (index > numMartians)
	{
		std::cout << "Please enter a valid index: " << std::endl;
		std::cin >> index;
	}
	return original[index];
}
void MartianDatabase::printMartians() {
	std::cout << std::left;
			//PRINT NOT SORTED
	std::cout << "********************************UNSORTED*****************************" << std::endl;
	std::cout << std::setw(20) << "Last Name" << std::setw(20) << "First Name" << std::setw(10) << "MSSN" << "\n\n";
	for (int i = 0; i < numMartians; i++)
	{
		std::cout <<std::setw(20)<< original[i].m_LastName << std::setw(20)<< original[i].m_firstName << std::setw(10)<< original[i].MSSN << std::endl;
	}
			//PRINT SORTED BY FIRST NAME
	std::cout << "********************************SORTED BY FIRST NAME*****************************" << std::endl;
	std::cout << std::setw(20) << "Last Name" << std::setw(20) << "First Name" << std::setw(10) << "MSSN" << "\n\n";
	std::sort(f_name, f_name + numMartians, Fsort);
	for (int i = 0; i < numMartians; i++)
	{
		std::cout <<std::setw(20)<< f_name[i]->m_LastName <<std::setw(20)<< f_name[i]->m_firstName << std::setw(10)<< f_name[i]->MSSN << std::endl;
	}
			//PRINT SORTED BY LAST NAME
	std::cout << "********************************SORTED BY LAST NAME*****************************" << std::endl;
	std::cout << std::setw(20) << "Last Name" << std::setw(20) << "First Name" << std::setw(10) << "MSSN" << "\n\n";
	std::sort(l_Name, l_Name + numMartians, Lsort);
	for (int i = 0; i < numMartians; i++)
	{
		std::cout <<std::setw(20)<< l_Name[i]->m_LastName <<std::setw(20)<< l_Name[i]->m_firstName << std::setw(10)<< l_Name[i]->MSSN << std::endl;
	}

	
			//PRINT SORTED BY SSN
	std::cout << "********************************SORTED BY MSSN*****************************" << std::endl;
	std::cout << std::setw(20) << "Last Name" << std::setw(20) << "First Name" << std::setw(10) << "MSSN" << "\n\n";
	std::sort(SSN, SSN + numMartians, Ssort);
	for (int i = 0; i < numMartians; i++)
	{
		std::cout <<std::setw(20)<< SSN[i]->m_LastName << std::setw(20)<< SSN[i]->m_firstName << std::setw(10)<< SSN[i]->MSSN << std::endl;
	}



}