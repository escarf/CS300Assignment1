#ifndef CONTACT_H_
#define CONTACT_H_
#include <iostream>
using namespace std;

class Contact {
	string fName;
	string lName;
	int num;

	public:

	Contact();
	Contact(string f, string l, int num);
	~Contact();

	friend void fPrint(Contact&);
	bool operator==(const Contact& other) const; // no member variables of parameter object can be altered bc of outside const

	string getFirst();
	string getLast();
	int getNum();

	void del();

};


#endif /* CONTACT_H_ */
