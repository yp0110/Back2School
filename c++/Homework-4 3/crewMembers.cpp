#include <iostream>
#include <string>
#include "crewMembers.h"

using namespace std;

crewMembers::crewMembers()
{
	count = 0;
}
void crewMembers::addCrewMember(crewMember person)
{
	persons.push_back(person);
}
void crewMembers::editCrewMember(int personID)
{
	bool revise = false;
	for(unsigned int i=0; i<persons.size(); ++i)
	{
		if((persons.at(i)).GetID() == personID)
		{
			while (revise == false)
			{
				int choice;
				cout << "which of the following information would you want to change?" << endl << "1) crew member name " << endl << "2)crew member ID" << endl << "3)crew member type" << endl;
				cout << "Enter a choice to edit: ";
				cin >> choice;
				if (choice == 1)
				{
					cout << "Enter a name: ";
					string strInput;
					getline(cin, strInput);
					(persons.at(i)).SetName(strInput);
					revise = true;
					cout << "crew member name changed to " << strInput << endl;
				}
				else if (choice == 2)
				{
					cout << "Enter an ID: ";
					int numInput;
					cin >> numInput;
					(persons.at(i)).SetID(numInput);
					revise = true;
					cout << "crew member ID changed to " << numInput << endl;
				}
				else if (choice == 3)
				{
					cout << "Enter a type: ";
					string strInput;
					cin >> strInput;
					(persons.at(i)).SetType(strInput);
					revise = true;
					cout << "crew member type changed to " << strInput << endl;
				}
				else
				{
					cout << "Error! Please check your options and enter a valid choice" << endl;
				}
			}
		}
	}
} 
void crewMembers::deleteCrewMember(int personID)
{
	bool revise = false;
	for (unsigned int i=0; i< persons.size(); ++i)
	{
		if((persons.at(i)).GetID() == personID)
		{
			persons.erase(persons.begin()+i);
			revise = true;
			cout << "crew memeber with " << personID << " is deleted." << endl;
		}
	}
	if(revise == false)
	{
		cout << "Error! We cannot find any member with ID: " << personID << endl;
	}
}
crewMember crewMembers::searchCrewMember(int personID)
{
	bool revise = false;
	for(unsigned int i=0; i< persons.size(); ++i)
	{
		if((persons.at(i)).GetID() == personID)
		{
			return persons.at(i);
		}
	}
	if(revise == false)
	{
		cout << "Error! We cannot find any member with ID: " << personID << endl;
	}
}
void crewMembers::printAll()
{
	for(unsigned int i=0; i<persons.size(); ++i)
	{
		cout << "Name: " << (persons.at(i)).GetName() << endl << "ID: " << (persons.at(i)).GetID() << endl << "Type: " << (persons.at(i)).
GetType() << endl;		
	}
}
void crewMembers::printCrewMember(int personID)
{
	for(unsigned int i=0; i<persons.size(); ++i)
	{
		if((persons.at(i)).GetID() == personID)
		{
			cout << "Name: " << (persons.at(i)).GetName() << endl << "ID: " << (persons.at(i)).GetID() << endl << "Type: " << (persons.at(i)).GetType() << endl;
		return;
		}
	}
}
