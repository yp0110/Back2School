
#ifndef CREWMEMBERS_H
#define CREWMEMBERS_H
#include <iostream>
#include <string>
#include <vector>

#include "crewMember.h"

using namespace std;

class crewMembers{
	public:
		crewMembers();					//default constructor
		void addCrewMember(crewMember person);		//void function to add a crew member
		crewMember searchCrewMember(int personID);		//function to search a crew member through ID
		void editCrewMember(int personID);		//void function to edit a crew member through ID
		void deleteCrewMember(int personID);		//void function to delete a crew member through ID
		void printAll();				//void function to print all crew members
		void printCrewMember(int personID);		//void function to print particular crew member roles through ID

	private:
		int count;					//private data member to count crewmembers
		vector<crewMember> persons;			//vector to store crewmembers data
};

#endif
