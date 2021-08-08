

#include <iostream>
#include <time.h>
#include <string> 
#include "flights.h"
using namespace std;

void printMenu();

int main ()
{

	cout << endl << "+----------------Computer Science and Engineering------------------------+" << endl;
        cout << "|									 |" << endl;
        cout << "|                CSCE 1040 - Computer Science II (Homework-IV)       	 |" << endl;
        cout << "|                                                                        |" <<endl;
        cout << "|       Manasa Nimmagadda    EUID:mn0338    ManasaNimmagadda@my.unt.edu  |" << endl;
        cout << "|                                                                        |" <<endl;
        cout << "+------------------------------------------------------------------------+" << endl;
        cout << endl;

	Flights flights;
	crewMembers people;
	Planes airlines;
	int num;
	
	while(true)
	{
		cout <<"Menu" << endl << "1) Add Crew Member" << endl << "2) Add plane" << endl << "3) Schedule a flight" << endl;
		cout << "4) Edit crew Member" << endl << "5) Edit plane" << endl << "6) Edit Flight" << endl; 
		cout << "7) Delete crew member" << endl << "8) Delete plane" << endl << "9) Delete Flight" << endl;
		cout <<"10) Print all the Crew members"<< endl << "11) Print all the planes" << endl << "12) Print all the Flights" << endl;
		cout <<"13) Print details of member"<<endl << "14) Print details of plane" << endl << "15) Print details of flight" << endl << "16) Print crew schedule" << endl << "17. Print aircraft schedule" << endl;
		cout << "18) Print flight status" << endl << "19) update flight status" << endl << "20) Delete flight by status" << endl << 
		cout <<"21) Store to a file" << endl << "22) Load form file" << endl;
		
		cout << "Enter the number(0 to quit): ";
		cin >> num;
	
		if(num == 0)
		{
			break;
		}
		else if(num == 1)
		{
			string name;
			int id;
			string type;
						
			cout << "Enter the Name of the member: ";
			cin.ignore();
			getline(cin,name);
			cout<<"Enter the ID of the member: ";
			cin >> id;
			cout<<"Enter the type (Pilot, CoPilot, Cabin) of the member: ";
			cin >> type;
			cout<<name;
			crewMember temp;
			temp.SetName(name);
			temp.SetID(id);
			temp.SetType(type);
						
			people.addCrewMember(temp);
			
		}
		else if(num == 2)
		{
			string make;
			int model;
			string num;
			int seats;
			int range;
			int minNumCabinCrew;
			
			cout<<"Enter the Make of the plane: ";
			cin.ignore();
			getline(cin,make);
			cout<<"Enter the Model of the plane: ";
			cin >> model;
			cout<<"Enter the tail number of the plane: ";
			cin >> num;
			cout<<"Enter the number of seats:  ";
			cin >> seats;
			cout<<"Enter the range: ";
			cin >> range;
			cout<<"Enter the minimum num of cabin crew: ";
			cin >> minNumCabinCrew;
			
			Plane temp;
			temp.SetMake(make);
			temp.SetModel(model);
			temp.SetTailNum(num);
			temp.SetRange(range);
			temp.SetMinCabinCrew(minNumCabinCrew);
			
			airlines.addPlane(temp);
			
		}
		else if(num == 3)
		{
			
			int min;
			int hour;
			int mday;
			int month;
			int year;
			string planeID;
			int pilotID;
			int copilotID;
			int one;
			int two;
			int three;
			int four;
			string startCode;
			string endCode;
			int passengers;
			string status;
			int flightID;
			
			cout <<"Enter Flight ID: ";
			cin >> flightID;
			cout <<"Enter the plane ID(Tail number): ";
			cin >> planeID;
			cout <<"Enter Pilot ID: ";
			cin>> pilotID;
			cout <<"Enter CoPilot ID: ";
			cin >> copilotID;
			cout <<"Enter cabin crew member 1 ID: ";
			cin >> one;
			cout <<"Enter cabin crew member 2 ID: ";
			cin >> two;
			cout <<"Enter cabin crew member 3 ID: ";
			cin >> three;
			cout <<"Enter cabin crew member 4 ID: ";
			cin >> four;
			cout <<"Enter hour(for start date and time): ";
			cin >>hour;
			cout <<"Enter minutes(for start date and time): ";
			cin >>min;
			cout <<"Enter month(for start date and time): ";
			cin >> month;
			cout <<"Enter date in the month(for start date and time): ";
			cin >>mday;
			cout <<"Enter the year(for start date and time): ";
			cin >> year;
			month -= 1;
			year -= 1900;
			struct tm start = {0, min, hour, mday, month, year};
					
			cout << "Enter hour(for end date and time): ";
			cin >> hour;
			cout << "Enter minutes(for end date and time): ";
			cin >> min;
			cout << "Enter month(for end date and time): ";
			cin >> month;
			cout << "Enter date in the month(for end date and time): ";
			cin >> mday;
			cout << "Enter the year(for end date and time): ";
			cin >> year;
			month -= 1;
			year -= 1900;
			struct tm end = {0, min, hour, mday, month, year};
			
			cout<<"Enter starting the airport code: ";
			cin >> startCode;
			cout<<"Enter ending the airport code: ";
			cin >> endCode;
			cout<<"Enter the numebr of passengers: ";
			cin >> passengers;
			cout<<"Enter the status (active, cancelled, completed): ";
			cin >> status;
			
			Flight temp;
			temp.SetFlightID(flightID);
			temp.SetPlaneID(planeID);
			temp.SetPilotID(pilotID);
			temp.SetCoPilotID(copilotID);
			temp.SetCrew1ID(one);
			temp.SetCrew2ID(two);
			temp.SetCrew3ID(three);
			temp.SetCrew4ID(four);
			temp.SetStartDate(start);
			temp.SetEndDate(end);
			temp.SetStartCode(startCode);
			temp.SetEndCode(endCode);
			temp.SetNumPassengers(passengers);
			temp.SetStatus(status);
			if(flights.checkAvaliability(temp, people) == true)
			{
				if((airlines.searchMember(planeID)).GetNumSeats() >= passengers)
				{
					flights.addFlight(temp);
				}
			}			
			
		}
		else if(num == 4)
		{
			int id;
			cout << endl <<"Enter the crew Member ID: ";
			cin >> id;
			people.editCrewMember(id);
		}
		else if(num == 5)
		{
			string id;
			cout << endl <<"Enter the plane ID (Tail Number): ";
			cin >> id;
			airlines.editPlane(id);
		}
		else if(num == 6)
		{
			int id;
			cout << endl <<"Enter the flight ID: ";
			cin >> id;
			flights.editFlight(id);
		}
		else if(num == 7)
		{
			int id;
			cout << endl << "Enter the crew Member ID: ";
			cin >> id;
			people.deleteCrewMember(id);
		}
		else if(num == 8)
		{
			string id;
			cout << endl <<"Enter the plane ID(Tail Number): ";
			cin >> id;
			airlines.deletePlane(id);
		}
		else if(num == 9)
		{
			int id;
			cout << endl <<"Enter the flight ID: ";
			cin >> id;
			flights.deleteFlight(id);
		}
		else if(num == 10)
		{
			people.printAll();
		}
		else if(num == 11)
		{
			airlines.printAll();
		}
		else if(num == 12)
		{
			flights.printAll();
		}
		else if(num == 13)
		{
			int id;
			cout << endl <<"Enter the crew Member ID: ";
			cin >> id;
			people.printCrewMember(id);
		}
		else if(num == 14)
		{
			string id;
			cout << endl << "Enter the plane ID(Tail Number): ";
			cin >> id;
			airlines.printPlanes(id);
		}
		else if(num == 15)
		{
			int id;
			cout << endl <<"Enter the flight ID: ";
			cin >> id;
			flights.printFDetails(id);
		}
		else if(num == 16)
		{
			int id;
			cout << endl << "Enter the crew Member ID: ";
			cin >> id;
			flights.printCMSchedule(id, people);
		}
		else if(num == 17)
		{
			string id;
			cout << endl << "Enter the plane ID(Tail Number): ";
			cin >> id;
			flights.printFSchedule(id);
		}
		else if(num == 18)
		{
			cout << endl << "Flights orderd based on status: ";
			flights.printFStatus();
		}
		else if(num == 19)
		{
			int id;
			cout << endl << "Enter the flight ID: ";
			cin >> id;
			flights.updateFStatus(id);
		}
		else if(num == 20)
		{
			int id;
			cout << endl << "Enter the flight ID: ";
			cin >> id;
			flights.deleteFStatus();
		}
	}
	
	return 0;
}
