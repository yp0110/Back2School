#ifndef CREWMEMBER_H
#define CREWMEMBER_H
#include <iostream>
#include <string>
using namespace std;

class crewMember{
	public:
		crewMember();							//default constructor
		crewMember(string crewName, int crewID, string crewTpye);	//constructor with all parameters
		void SetName(string crewName);					//mutator function for name
		string GetName();						//accessor function for name
		void SetID(int crewID);						//mutator function for ID
		int GetID();							//accessor function for ID
		void SetType(string crewType);					//mutator function for type
		string GetType();						//accessor function for type

	private:
		string name;							//private data member for name
		int IDnumber;							//private data member for ID
		string crewMemberType;						//private data member for type
};
		
#endif
