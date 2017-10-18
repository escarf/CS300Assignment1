//============================================================================
// Name        : CS300Assignment1.cpp
// Author      : Ephraim Scarf
//============================================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include "Contact.h"
using namespace std;


int main() {

	bool quit = 0; // false while the user hasn't selected quit
	int bookCount = 0; // number of Contacts in phonebook array

	string temp; // used to increment file stream when the strings within that file won't be stored


	ifstream counter; // for getting size of book array by counting lines of text file
	counter.open("phonebook.txt");

	string fName;
	string lName;
	int phoneNum;

	int arrayPlace = 0; // placeholder of current index for adding to phonebook array

	// used to get size of book array by counting lines of text file
	while(!counter.eof()) {
		getline(counter,temp );
		bookCount++;

	}


	Contact *book = new Contact[bookCount]; // creates an array of Contact objects. Size equals the number of contacts in original phonebook.txt
	counter.close();


	ifstream infile; // parses over phonebook.txt for filling the array
	infile.open("phonebook.txt");


	//reads contacts from file, adds to array
	while(!infile.eof()) {

		infile >> fName;
		infile >> lName;
		infile >> phoneNum;

		Contact adding(fName, lName, phoneNum);

		book[arrayPlace] = adding; // add contact for this line

		arrayPlace++;
	}


	ofstream outfile;

	infile.close();
	outfile.open("phonebook.txt");


	while(!quit) {

		string choice; // which of the options below is chosen

		cout << "***MY PHONEBOOK APPLICATION***" << endl;
		cout << "Please choose an operation:" << endl;
		cout <<"A(Add) | S(Search) | D(Delete) | L(List) | Q(Quit): ";

		cin >> choice;

		if( (choice.compare("A") == 0) || (choice.compare("a") == 0) ) {
			string addF;
			string addL;
			int addNum;

			cout<<"Enter name to add: "<< endl;
			cin>> addF;
			cin>> addL;
			cout<<"Enter number: "<< endl;
			cin>> addNum;

			Contact adding(addF, addL, addNum);

			Contact *tempBook = new Contact[bookCount+1];

			// adds Contact objects to a temporary, bigger array
			for( int i = 0; i <= bookCount; i++ ) {
				tempBook[i] = book[i];
			}

			tempBook[bookCount] = Contact(adding.getFirst(), adding.getLast(), adding.getNum()); // adds new Contact to temp

			book = new Contact[bookCount+1]; // resizes original array

			// adds all Contacts into resized original array
			for( int i = 0; i <= bookCount; i++ ) {
				 book[i] = tempBook[i];
			}

			bookCount++; // since the array contains a new Contact

			delete tempBook;
			cout<<"Contact added "<< endl;

		}

		else if((choice.compare("S") == 0) || (choice.compare("s") == 0)) {

			string searchF;
			string searchL;
			cout<<"Enter name to search for: "<< endl;

			cin>> searchF;
			cin>> searchL;

			Contact search(searchF, searchL, 0);

			for(int i = 0; i < bookCount; i++) {

				if(search ==(book[i])) {

					cout<<"Number: "<<book[i].getNum() << endl;
					break;
				}
			}

			search.~Contact();
		}

		else if((choice.compare("D") == 0) || (choice.compare("d") == 0)) {

			string delF;
			string delL;
			cout<<"Enter name to delete: "<< endl;

			cin>> delF;
			cin>> delL;

			Contact deleting(delF, delL, 0);

			// uses Contact::del() to effectively delete specified Contact without resizing array
			for(int i = 0; i < bookCount; i++) {

				if(deleting ==(book[i])) {

					cout<<"Name to delete: "<<book[i].getFirst() <<" " << book[i].getLast()<< endl;
					book[i].del();
					break;
				}
			}

			cout<<"Name deleted " << endl;
			deleting.~Contact();
		}

		else if((choice.compare("L") == 0) || (choice.compare("l") == 0)) {
			cout<<"List of contacts: "<< endl;

			for(int i = 0; i < bookCount; i++) {
				fPrint(book[i]);
			}
		}

		else if((choice.compare("Q") == 0) || (choice.compare("q") == 0)) {

			quit = 1;
		}

		else {
			cout<<"Unrecognized input: try again"<< endl;
		}

	}

	delete book;
	return 0;
}

