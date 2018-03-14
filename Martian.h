#ifndef Martian_H
#define Martian_H

#include <string>
const int MAX = 100; 

struct Martian {
	std::string m_firstName;
	std::string m_LastName;
	int MSSN;
	//CONSTRUCTOR TO MAKE EMPTY
	Martian() {
		m_firstName = " ";
		m_LastName = " ";
		MSSN = 0;
	}
	//CONSTRUCTOR TO FILL FIELDS
	Martian(std::string fname, std::string lname, int ssn) {
		m_firstName = fname;
		m_LastName = lname;
		MSSN = ssn;
	}
	//OVERLOADED ASSIGNMENT OPERATOR
	Martian& operator = (const Martian &M)
	{
		if (this == &M)
			return *this;

		this->m_firstName = M.m_firstName;
		this->m_LastName = M.m_LastName;
		this->MSSN = M.MSSN;
		return *this;
	}
	//COMPARING OVERLOAD
	bool operator ==(const Martian& right)
	{
		if (this->MSSN == right.MSSN && this->m_firstName == right.m_firstName
			&& this->m_LastName == right.m_LastName)
			return true;
		else
			return false;
	}
	//COPY CONSTRUCTOR
	Martian (const Martian& M) {
		m_firstName = M.m_firstName;
		m_LastName = M.m_LastName;
		MSSN = M.MSSN;
	}
	
};

class MartianDatabase {
private:
	Martian original[MAX];
	Martian * f_name[MAX];
	Martian * l_Name[MAX];
	Martian * SSN[MAX];
public:
	int numMartians = 0;
	MartianDatabase(std::string filename);
	void addMartian(Martian m);
	bool deleteMartian(Martian m);
	bool isEmpty();
	bool isFull();
	void printMartians();
	Martian printOriginal();
	static bool Fsort(Martian *r, Martian *l);
	static bool Lsort(Martian *r, Martian *l);
	static bool Ssort(Martian *r, Martian *l);
	~MartianDatabase();
	//COPY
	MartianDatabase(const MartianDatabase& MD) {
		for (int i = 0; i < MD.numMartians; i++)
		{
			original[i] = MD.original[i];
			f_name[i] = MD.f_name[i];
			l_Name[i] = MD.l_Name[i];
			SSN[i] = MD.SSN[i];
		}
		numMartians = MD.numMartians;
	}
	//Assignment operator
	MartianDatabase& operator = (const MartianDatabase &M)
	{
		if (this == &M)
			return *this;
		for (int i = 0; i < M.numMartians; i++)
		{
			this->original[i] = M.original[i];
			this->f_name[i] = M.f_name[i];
			this->l_Name[i] = M.l_Name[i];
			this->SSN[i] = M.SSN[i];
		}
		
		return *this;
	}
};

#endif