/*
 * Contact.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: escarf
 */

#include "Contact.h"
#include <iostream>
using namespace std;

Contact::Contact() {

	fName = "none";
	lName = "none";
	num = 0;
}
Contact::Contact(string f, string l, int num) {

	Contact:: fName = f;
	Contact:: lName = l;
	Contact:: num = num;

}

Contact::~Contact() {

}

void fPrint(Contact &con) {

	if(con.num == 0) {
		cout<<" "<<endl;
	}
	else {
		cout<< con.fName<<" "<<con.lName<<" "<< con.num<<endl;
	}
}

bool Contact::operator==(const Contact& other) const {
	return ( (fName == other.fName) && (lName == other.lName) );

}

string Contact::getFirst() {
	return this->fName;

}

string Contact::getLast() {
	return this->lName;
}


int Contact::getNum() {
	return this->num;
}

void Contact::del() {
	fName = "";
	lName = "";
	num = 0; // 0 is the number for a "deleted" Contact

}
