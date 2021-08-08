#include <iostream>
#include <string>
#include "crewMember.h"

using namespace std;

crewMember::crewMember()							//assigning no value to data members
{
	name = "";
	IDnumber = 0;
	crewMemberType = "";
}

crewMember::crewMember(string crewName, int crewID, string crewType)		//assigning data members to parameters
{
	name = crewName;
	IDnumber = crewID;
	crewMemberType = crewType;
}

void crewMember::SetName(string crewName)					//set function for name
{
	name = crewName;
}

void crewMember::SetID(int crewID)						//set function for ID
{
	IDnumber = crewID;
}
void crewMember::SetType(string crewType)					//set function for type
{
	crewMemberType = crewType;
}
string crewMember::GetName()							//get function for name
{
	return name;
}
int crewMember::GetID()								//get function for ID
{
	return IDnumber;
}
string crewMember::GetType()							//get function for type
{
	return crewMemberType;
}

