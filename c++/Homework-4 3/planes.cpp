
#include <iostream>
#include <string> 
#include "planes.h"

using namespace std;

Planes::Planes()
{
	count = 0;
}

void Planes::addPlane(Plane airline)
{
	airlines.push_back(airline);
}
void Planes::editPlane(string planeID)
{
	bool revise = false;
	for (unsigned int i = 0; i<airlines.size(); ++i)
	{
		if((airlines.at(i)).GetTailNum() == planeID)
		{
			while(revise == false)
			{
				int choice;				//to get an input choice from user to make edits
				cout<<"Which of the following information do you want to edit?" << endl << "1) Make " << endl << "2) Model" << endl << "3) Tail Number" << endl << "4) Number of seats" << endl << "5) Range" << endl << "6) Minimum number of cabin crew" << endl;
				cout << "choose an option from the above list: " <<endl;
				cin >> choice;			
				if(choice == 1)
				{
					cout<<"Enter a new value for Make: "<<endl;
					string input; 
					getline(cin,input);
					(airlines.at(i)).SetMake(input);
					revise = true;
					cout << "Changes made for make" << endl;
				}
				else if(choice == 2)
				{
					cout<<"Enter a new value for model: "<<endl;
					int numInput;
					cin >> numInput;
					(airlines.at(i)).SetModel(numInput);
					revise = true;
					cout << "Changes made for model" << endl;
				}
				else if(choice == 3)
				{
					cout<<"Enter a new value for tail number: "<<endl;
					string strInput; 
					getline(cin,strInput);
					(airlines.at(i)).SetTailNum(strInput);
					revise = true;
					cout << "Changes made for tail number" << endl;
				}
				else if(choice == 4)
				{
					cout<<"Enter a new value for number of seats in plane: "<<endl;
					int numInput;
					cin >> numInput;
					(airlines.at(i)).SetNumSeats(numInput);
					revise = true;
					cout << "Changes made for number of seats in plane" << endl;
				}
				else if(choice ==5 )
				{
					cout<<"Enter a new value for range: "<<endl;
					int numInput;
					cin >> numInput;
					(airlines.at(i)).SetRange(numInput);
					revise = true;
					cout << "Changes made for range of the plane" << endl;
				}
				else if(choice == 6)
				{
					cout<<"Enter a new value for the minimum number of cabin crew: "<<endl;
					int num; 
					cin >> num;
					(airlines.at(i)).SetMinCabinCrew(num);
					revise = true;
					cout << "Changes made for minimum number of cabin crew in a plane" << endl;
				}
				else 
				{
					cout <<"Error! Please check you options and enter a valid choice"<<endl;
				}
			}
		}
	}
}
void Planes::deletePlane(string planeID)
{
	bool revise = false;
	for(unsigned int i = 0; i<airlines.size(); ++i)
	{
		if((airlines.at(i)).GetTailNum() == planeID)
		{
			airlines.erase(airlines.begin()+i);
			revise = true;
			cout << "Deleted" << endl;
		}
	}
	if (revise == false)
	{
		cout << "Error! We cannot find a plane with the ID: " << planeID << endl;
	}
}
Plane Planes::searchMember(string planeID)
{
	bool revise = false;
	for(int i = 0; i< airlines.size(); ++i)
	{
		if((airlines.at(i)).GetTailNum() == planeID)
		{
			return airlines.at(i);
			revise = true;
		}
	}
	if (revise == false)
	{
		cout << "Error! We cannot find a plane with the ID: " << planeID << endl;
	}
}
void Planes::printAll()
{
	for(unsigned int i=0; i<airlines.size(); ++i)
	{
		cout << "Make: " << (airlines.at(i)).GetMake() << endl << "Model: " << (airlines.at(i)).GetModel() << endl << "Tail Number: "<< airlines.at(i).GetTailNum() << endl << "Number of seats: "<< airlines.at(i).GetNumSeats()<< endl << "Range: " << airlines.at(i).GetRange()<< endl << "Minimum number of cabin crew: "<< airlines.at(i).GetMinCabinCrew()<<endl;
	}
}
void Planes::printPlanes(string planeID)
{
	for (unsigned int i = 0; i< airlines.size(); ++i)
	{
		if((airlines.at(i)).GetTailNum() == planeID)
		{
			cout << "Make: " << (airlines.at(i)).GetMake() << endl << "Model: " << (airlines.at(i)).GetModel() << endl << "Tail Number: "<<	airlines.at(i).GetTailNum() << endl << "Number of seats: "<< airlines.at(i).GetNumSeats()<< endl << "Range: " << airlines.at(i).GetRange()<< endl << "Minimum number of cabin crew: "<<	airlines.at(i).GetMinCabinCrew()<<endl;
			return;
		}
	}
}
