#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include "flights.h"

using namespace std;

Flights::Flights()
{
	count =0;
}
void Flights::addFlight(Flight name)
{
	flightInfo.push_back(name);
}
void Flights::editFlight(int flightID)
{
	bool revise =false;
	for(unsigned int i=0; i < flightInfo.size(); ++i)
	{
		if((flightInfo.at(i)).GetFlightID() == flightID)
		{
			while (revise == false)
			{
				int choice;
				cout<<"Which of the following information do you want to edit?" << endl << "1) Plane ID" << endl << "2) Pilot ID" << endl << "3) CoPilot ID" << endl << " 4) Crew ID" << endl << "5) Start date and time" << endl << "6) End date and time" << endl << "7) Start Airport code" << endl << "8) End Airport code" << endl << "9) Number of Passengers" << endl << " 10) Satatus?" << endl;
				cout << "Enter a choice: ";
				cin >> choice;
			
				if(choice == 1)
				{
					cout<<"Enter a new value for plane ID: "<<endl;
					string strInput;
					cin >> strInput;
					(flightInfo.at(i)).SetPlaneID(strInput);
					revise = true;
					cout << "Changes made for plane ID" << endl;
				}
				else if(choice == 2)
				{
					cout<<"Enter a new value for pilot ID: "<<endl;
					int numInput;
					cin >> numInput;
					(flightInfo.at(i)).SetPilotID(numInput);
					revise = true;
					cout << "Changes made for pilot ID" << endl;
				}
				else if(choice == 3)
				{
					cout<<"Enter a new value for co-pilot ID: "<<endl;
					int numInput;
					cin >>numInput;
					(flightInfo.at(i)).SetCoPilotID(numInput);
					revise = true;
					cout << "Changes made for co pilot ID" << endl;
				}
				else if(choice == 4)
				{
					int numInput1;
                                        int numInput2;
                                        int numInput3;
                                        int numInput4;
					cout<<"Enter an ID for the first crew member: "<<endl;
					cin >>numInput1;
					(flightInfo.at(i)).SetCrew1ID(numInput1);
					cout<<"Enter an ID for the second crew member: "<<endl;
					cin >>numInput2;
					(flightInfo.at(i)).SetCrew2ID(numInput2);
					cout<<"Enter an ID for the third crew member: "<<endl;
					cin >>numInput3;
					(flightInfo.at(i)).SetCrew3ID(numInput3);
					cin >>numInput4;
                                        (flightInfo.at(i)).SetCrew4ID(numInput4);
					revise = true;
					cout << "Changes made for cabin crew members" << endl;
				}
				else if(choice == 5)	
				{					
					int min;
					int hour;
					int mday;
					int month;
					int year;
					
					cout << "Enter the time in hours: ";
					cin >> hour;
					cout << endl << "Enter the time in minutes: ";
					cin >> min;
					cout << endl << "Enter month: ";
					cin >> month;
					cout << endl << "Enter the date of the month: ";
					cin >>mday;
					cout << endl << "Enter the year: ";
					cin >> year;
					cout << endl;
					month = month - 1;
					year = year - 1900;
					struct tm day = {0, min, hour, mday, month, year};
					(flightInfo.at(i)).SetStartDate(day);
					revise = true;
					cout << "Changes made for start date and time" << endl;
				}
				else if(choice == 6)
				{
							
					int min;
					int hour;
					int mday;
					int month;
					int year;
					
					cout << "Enter hours: ";
					cin >> hour;
					cout << endl << "Enter minutes: ";
					cout << endl << "Enter minutes: ";
					cin >> min;
					cout << endl <<"Enter month: ";
					cin >> month;
					cout << endl << "Enter date in the month: ";
					cin >>mday;
					cout << endl <<"Enter the year: ";
					cin >> year;
					month = month - 1;
					year = year - 1900;
					struct tm day = {0, min, hour, mday, month, year};
					(flightInfo.at(i)).SetEndDate(day);
					revise = true;
					cout << "Changes made for end date and time" << endl;
				}
				else if(choice == 7)
				{
					cout << endl <<"Enter a new code for starting airport: ";
					string strInput;
					cin >> strInput;
					(flightInfo.at(i)).SetStartCode(strInput);
					revise = true;
					cout << "Changes made for starting airport code" << endl;
				}
				else if(choice == 8)
				{
					cout << "Enter a new code for ending airport: ";
					string strInput;
					cin >>strInput;
					(flightInfo.at(i)).SetEndCode(strInput);
					revise = true;
					cout << "Changes made for ending airport code" << endl;
				}
				else if(choice == 9)
				{
					cout << "Enter a value for the number of passengers: ";
					int numInput;
					cin >>numInput;
					(flightInfo.at(i)).SetNumPassengers(numInput);
					revise = true;
					cout << "Changes made for the number of passengers" << endl;
				}
				else if(choice == 10)
				{
					cout << "Enter the current status for flight: ";
					string strInput;
					cin >> strInput;
					(flightInfo.at(i)).SetStatus(strInput);
					revise = true;
					cout << "Changes made for current status of flight" << endl;
				}
				else 
				{
					cout <<"Error. Please check the options and enter a valid choice."<<endl;
				}
			}
			
		}
	}
}
void Flights::deleteFlight(int flightID)
{
	bool revise = false;
	for (unsigned int i=0; i<flightInfo.size(); ++i)
	{
		if((flightInfo.at(i)).GetFlightID() == flightID)
		{
			flightInfo.erase(flightInfo.begin() + i);
			revise = true;
			cout << "Flight Deleted" << endl;
		}
	}
	if(revise == false)
	{
		cout<< "Error! We cannot find a flight with the ID: "<< flightID <<endl;
	}
}
Flight Flights::searchFlight(int flightID)
{
	bool revise = false;
	for(unsigned int i=0; i<flightInfo.size(); ++i)
	{
		if((flightInfo.at(i)).GetFlightID() == flightID)
		{
			return flightInfo.at(i);
			revise = true;
		}
	}
	if(revise == false)
	{
		cout << "Error! We cannot find a flight with the ID: " << flightID << endl;
	}
}
void Flights::printAll()
{
	for(unsigned int i=0; i <flightInfo.size(); ++i)
	{
		cout << "FlightID: " << (flightInfo.at(i)).GetFlightID() << endl << "Plane ID: " << (flightInfo.at(i)).GetPlaneID() << endl << "Pilot ID: " << (flightInfo.at(i)).GetPilotID() << endl << "Co-Pilot ID: " << (flightInfo.at(i)).GetCoPilotID() << endl;
		cout << "Cabin Crew1 ID: " << (flightInfo.at(i)).GetCrew1ID() << endl << "Cabin Crew2 ID: " << (flightInfo.at(i)).GetCrew2ID() << endl << "Cabin Crew3 ID: " << (flightInfo.at(i)).GetCrew3ID() << endl << "Cabin Crew4 ID: " << (flightInfo.at(i)).GetCrew4ID() << endl;
		printf("Start Date and Time: %s\n", asctime((flightInfo.at(i)).GetStartDate()));
		printf("End Date and Time: %s\n", asctime((flightInfo.at(i)).GetEndDate()));
		cout << "Starting Airport Code: " << (flightInfo.at(i)).GetStartCode() << endl << "Ending Airport Code: " << (flightInfo.at(i)).GetEndCode() << endl << "Number of Passengers: " << (flightInfo.at(i)).GetNumPassengers() << endl << "Flight Status: " << (flightInfo.at(i)).GetStatus() << endl;		
	}
}
void Flights::printFDetails(int flightID)
{
	bool revise = false;
	for(unsigned int i=0; i<flightInfo.size(); ++i)
	{
		if((flightInfo.at(i)).GetFlightID() == flightID)
		{
			cout << "FlightID: " << (flightInfo.at(i)).GetFlightID() << endl << "Plane ID: " << (flightInfo.at(i)).GetPlaneID() << endl << "Pilot ID: " << (flightInfo.at(i)).GetPilotID() << endl << "Co-Pilot ID: " << (flightInfo.at(i)).GetCoPilotID() << endl;
			cout << "Cabin Crew1 ID: " << (flightInfo.at(i)).GetCrew1ID() << endl << "Cabin Crew2 ID: " << (flightInfo.at(i)).GetCrew2ID() << endl << "Cabin Crew3 ID: " << (flightInfo.at(i)).GetCrew3ID() << endl << "Cabin Crew4 ID: " << (flightInfo.at(i)).GetCrew4ID() << endl;
			printf("Start Date and Time: %s\n", asctime((flightInfo.at(i)).GetStartDate()));
			printf("End Date and Time: %s\n", asctime((flightInfo.at(i)).GetEndDate()));
			cout << "Starting Airport Code: " << (flightInfo.at(i)).GetStartCode() << endl << "Ending Airport Code: " << (flightInfo.at(i)).GetEndCode() << endl << "Number of Passengers: " << (flightInfo.at(i)).GetNumPassengers() << endl << "Flight Status: " << (flightInfo.at(i)).GetStatus() << endl;
		}
	}
	if (revise == false)
	{
		cout << "Error! We cannot find a flight with the ID: " << flightID << endl;
	}
}
void Flights::printFSchedule(string planeID)
{
	vector<Flight> names;
	bool revise = false;
	for (unsigned int i=0; i<flightInfo.size(); ++i)
	{
		if((flightInfo.at(i)).GetPlaneID() == planeID)
		{
			names.push_back(flightInfo.at(i));
		}
	}
	while(names.size()>0)
	{
		Flight thing = names.at(0);
		int num = 0;
		for(unsigned int i=0; i<names.size(); ++i)
		{
			time_t time1 = mktime(thing.GetStartDate());
			time_t time2 = mktime(names.at(i).GetStartDate());
			if(difftime(time1,time2) < 0) 
			{
				
				num =i;
				thing = names.at(i);
			}
		}
		cout << "Flight ID: " << thing.GetFlightID() << endl << "Plane ID: " << thing.GetPlaneID() << endl;
		printf("Start date and time: %s\n", asctime(thing.GetStartDate()));
		printf("Start date and time: %s\n", asctime(thing.GetEndDate()));
		names.erase(names.begin()+num);
		cout << endl;
	}
	if (revise == false)
	{
		cout << "Error! We cannot find a flight with the ID: " << planeID << endl;
	}
}
void Flights::printFStatus()
{
	for(unsigned int i=0; i <flightInfo.size(); ++i)
	{
		if(flightInfo.at(i).GetStatus() == "active" ||flightInfo.at(i).GetStatus() == "Active" )
		{
			cout << "Plane ID: " << flightInfo.at(i).GetPlaneID() << "	Flight ID: " << flightInfo.at(i).GetFlightID() << "	Active" <<endl;
		}
	}
	cout<<endl;
	for(unsigned int i=0; i <flightInfo.size(); ++i)
	{
		if(flightInfo.at(i).GetStatus() == "cancelled" ||flightInfo.at(i).GetStatus() == "Cancelled" )
		{
			cout<<"Plane ID: " << flightInfo.at(i).GetPlaneID() << "	Flight ID: " << flightInfo.at(i).GetFlightID() << "	Cancelled" << endl;
		}
	}
	cout << endl;
	for(unsigned int i=0; i <flightInfo.size(); ++i)
	{
		if(flightInfo.at(i).GetStatus() == "completed" || flightInfo.at(i).GetStatus() == "Completed" )
		{
			cout<<"Plane ID: " << flightInfo.at(i).GetPlaneID() << "	Flight ID: " << flightInfo.at(i).GetFlightID() << "	Completed" << endl;
		}
	}
	cout << endl;
}
void Flights::deleteFStatus()
{
	for(unsigned int i=0; i <flightInfo.size(); ++i)
	{
		if(flightInfo.at(i).GetStatus() == "cancelled" ||flightInfo.at(i).GetStatus() == "Cancelled" )
		{
			flightInfo.erase(flightInfo.begin() + i);
		}
	}
	for(unsigned int i=0; i <flightInfo.size(); ++i)
	{
		if(flightInfo.at(i).GetStatus() == "completed" ||flightInfo.at(i).GetStatus() == "Completed" )
		{
			flightInfo.erase(flightInfo.begin() + i);
		}
	}
}
void Flights::updateFStatus(int flightID)
{
	bool revise = false;
	for(unsigned int i=0; i <flightInfo.size(); ++i)
	{
		
		if((flightInfo.at(i)).GetFlightID() == flightID)
		{
			cout<<"Update the new status(active, cancelled, completed): ";
			string strInput;
			cin >> strInput;
			flightInfo.at(i).SetStatus(strInput);
			revise = true;
		}
	}
	if(revise == false)
	{
		cout<< "Error! We cannot find a flight with the ID: " << flightID << endl;
	}
}
bool Flights::checkAvaliability(Flight temp, crewMembers persons)  
{
	//plane
	vector <Flight> names;
	bool revise =false;
	for(unsigned int i=0; i <flightInfo.size(); ++i)
	{
		
		if((flightInfo.at(i)).GetPlaneID() == temp.GetPlaneID())
		{
			names.push_back(flightInfo.at(i));
		}
	}
	while(names.size()>0)
	{	
		int num =0;
		for(unsigned int i=0; i < names.size(); ++i)
		{
			time_t time1 = mktime(names.at(i).GetStartDate());
			time_t time2 = mktime(temp.GetStartDate());
			time_t time3 = mktime(names.at(i).GetEndDate());
			time_t time4 = mktime(temp.GetEndDate());
			
			if(difftime(time1,time2 ) < 0 && difftime(time3,time2) > 0 )
			{
				cout<<"The plane is already scheduled at that time period" <<endl;
				return false;
			}
			
			if(difftime(time1,time4) < 0 && difftime(time3,time4) > 0 )
			{
				cout<<"The plane is already scheduled at that time period." <<endl;
				return false;
			}
		
		}
	}
	//pilot
	names.clear();
	crewMember currType = persons.searchCrewMember(temp.GetPilotID());
	if(currType.GetType() != "Pilot" && currType.GetType() != "pilot")
	{
		cout << "Error. Wrong assignment."<<endl;
		return false;
	}
		revise =false;
		for(unsigned int i=0; i <flightInfo.size(); i++)
		{
		
			if((flightInfo.at(i)).GetPilotID() == names.at(i).GetPilotID())
			{
				names.push_back(flightInfo.at(i));
			}
		}
		
		while(names.size()>0)
		{
			for(unsigned int i=1; i <names.size(); i++)
			{				
			time_t time1 = mktime(names.at(i).GetStartDate());
			time_t time2 = mktime(temp.GetStartDate());
			time_t time3 = mktime(names.at(i).GetEndDate());
			time_t time4 = mktime(temp.GetEndDate());
			
			if(difftime(time1,time2 ) < 0 && difftime(time3,time2) > 0 )
			{
				cout<<"Error. Pilot is already scheduled another plane at that time"<<endl;
				return false;
			}
			
			if(difftime(time1,time4) < 0 && difftime(time3,time4) > 0 )
			{
				cout<<"Error. Pilot is already scheduled another plane at that time"<<endl;
				return false;
			}
		
			}
		}
	//copilot
	names.clear();
	currType = persons.searchCrewMember(temp.GetCoPilotID());
	if(currType.GetType()!="copilot" && currType.GetType()!="Copilot")
	{
		cout << "Error. Wrong assignment." <<endl;
		return false;
	}
		revise =false;
		for(unsigned int i=0; i <flightInfo.size(); ++i)
		{
		
			if((flightInfo.at(i)).GetCoPilotID() == names.at(i).GetCoPilotID())
			{
				names.push_back(flightInfo.at(i));
			}
		}
		
		while(names.size()>0)
		{
			for(unsigned int i=1; i <names.size(); i++)
			{
				time_t time1 = mktime(names.at(i).GetStartDate());
				time_t time2 = mktime(temp.GetStartDate());
				time_t time3 = mktime(names.at(i).GetEndDate());
				time_t time4 = mktime(temp.GetEndDate());
				
				if(difftime(time1,time2 ) < 0 && difftime(time3,time2) > 0 )
				{
					cout<< "Error. The CoPilot is already scheduled another plane at that time" <<endl;
					return false;
				}
				
				if(difftime(time1,time4) < 0 && difftime(time3,time4) > 0 )
				{
					cout<< "Error. The CoPilot is already scheduled another plane at that time" <<endl;
					return false;
				}
		
			}
		}
	// cabin 1
	currType = persons.searchCrewMember(temp.GetCrew1ID());
	if(currType.GetType() != "cabin" && currType.GetType() != "Cabin")
	{
		cout << "Error. Wrong assignment." <<endl;
		return false;
	}
	names.clear();
		revise =false;
		for(unsigned int i=0; i <flightInfo.size(); i++)
		{
		
			if((flightInfo.at(i)).GetCrew1ID() == names.at(i).GetCrew1ID())
			{
				names.push_back(flightInfo.at(i));
			}
		}
		while(names.size()>0)
		{
			for(unsigned int i=1; i <names.size(); i++)
			{
				time_t time1 = mktime(names.at(i).GetStartDate());
				time_t time2 = mktime(temp.GetStartDate());
				time_t time3 = mktime(names.at(i).GetEndDate());
				time_t time4 = mktime(temp.GetEndDate());
				
				if(difftime(time1,time2 ) < 0 && difftime(time3,time2) > 0 )
				{
					cout<<"Error. Cabin crew member 1 is already scheduled to another plane at that time"<<endl;
					return false;
				}
				
				if(difftime(time1,time4) < 0 && difftime(time3,time4) > 0 )
				{
					cout<<"Error. Cabin crew member 1 is already scheduled to another plane at that time"<<endl;
					return false;
				}
			}
		}
	//cabin 2
	names.clear();
	currType = persons.searchCrewMember(temp.GetCrew2ID());
	if(currType.GetType() != "cabin" && currType.GetType() != "Cabin")
	{
		cout << "Error. Wrong assignment." <<endl;
		return false;
	}
		revise =false;
		for(unsigned int i=0; i <flightInfo.size(); i++)
		{
			if((flightInfo.at(i)).GetCrew2ID() == names.at(i).GetCrew2ID())
			{
				names.push_back(flightInfo.at(i));
			}
		}
		while(names.size()>0)
		{
			for(unsigned int i=1; i < names.size(); i++)
			{
			time_t time1 = mktime(names.at(i).GetStartDate());
			time_t time2 = mktime(temp.GetStartDate());
			time_t time3 = mktime(names.at(i).GetEndDate());
			time_t time4 = mktime(temp.GetEndDate());
			
			if(difftime(time1,time2 ) < 0 && difftime(time3,time2) > 0 )
			{
				cout<<"Error. Cabin crew member 2 is already scheduled to another plane at that time"<<endl;
				return false;
			}
			
			if(difftime(time1,time4) < 0 && difftime(time3,time4) > 0 )
			{
				cout<<"Error. Cabin crew member 2 is already scheduled to another plane at that time"<<endl;
				return false;
			}
		
			}
		}
	//cabin 3
	names.clear();
	currType = persons.searchCrewMember(temp.GetCrew3ID());
	if(currType.GetType() != "cabin" && currType.GetType() != "Cabin")
	{
		cout << "Error. Wrong assignment." <<endl;
		return false;
	}
		revise =false;
		for(unsigned int i=0; i <flightInfo.size(); i++)
		{
			if((flightInfo.at(i)).GetCrew3ID() == names.at(i).GetCrew3ID())
			{
				names.push_back(flightInfo.at(i));
			}
		}
		while(names.size() > 0)
		{
			for(unsigned int i=1; i <names.size(); i++)
			{
				time_t time1 = mktime(names.at(i).GetStartDate());
				time_t time2 = mktime(temp.GetStartDate());
				time_t time3 = mktime(names.at(i).GetEndDate());
				time_t time4 = mktime(temp.GetEndDate());
				
				if(difftime(time1,time2 ) < 0 && difftime(time3,time2) > 0 )
				{
					cout<<"Error. Cabin crew member 3 is already scheduled to another plane at that time."<<endl;
					return false;
				}
				
				if(difftime(time1,time4) < 0 && difftime(time3,time4) > 0 )
				{
					cout<<"Error. Cabin crew member 3 is already scheduled to another plane at that time."<<endl;
					return false;
				}
		
			}
		}
	//cabin 4
	names.clear();
	currType = persons.searchCrewMember(temp.GetCrew4ID());
	if(currType.GetType() != "cabin" && currType.GetType() != "Cabin")
	{
		cout << "Error. Wrong assignment." <<endl;
		return false;
	}
		revise =false;
		for(unsigned int i=0; i <flightInfo.size(); i++)
		{
			if((flightInfo.at(i)).GetCrew4ID() == names.at(i).GetCrew4ID())
			{
				names.push_back(flightInfo.at(i));
			}
		}
		while(names.size() > 0)
		{
			for(unsigned int i=1; i <names.size(); i++)
			{
				time_t time1 = mktime(names.at(i).GetStartDate());
				time_t time2 = mktime(temp.GetStartDate());
				time_t time3 = mktime(names.at(i).GetEndDate());
				time_t time4 = mktime(temp.GetEndDate());
				
				if(difftime(time1,time2 ) < 0 && difftime(time3,time2) > 0 )
				{
					cout<<"Error. Cabin crew member 4 is already scheduled to another plane at that time."<<endl;
					return false;
				}
				
				if(difftime(time1,time4) < 0 && difftime(time3,time4) > 0 )
				{
					cout<<"Error. Cabin crew member 4 is already scheduled to another plane at that time."<<endl;
					return false;
				}
		
			}
		}
		return true;
}
void Flights::printCMSchedule(int crewMembersID, crewMembers persons)
{
	crewMember member = persons.searchCrewMember(crewMembersID);
	if(member.GetType() == "Pilot" || member.GetType() == "pilot" )
	{
		vector <Flight> names;
		bool revise =false;
		for(unsigned int i=0; i <flightInfo.size(); i++)
		{
		
			if((flightInfo.at(i)).GetPilotID() == names.at(i).GetPilotID())
			{
				names.push_back(flightInfo.at(i));
			}
		}
		
		while(names.size()>0)
		{
			Flight thing =names.at(0);
			int num =0;
			for(unsigned int i=1; i <names.size(); i++)
			{
				time_t time1 = mktime(thing.GetStartDate());
				time_t time2 = mktime(names.at(i).GetStartDate());
				if(difftime(time1,time2) < 0)
				{				
					num =i;
					thing = names.at(i);
				}
		
			}
			cout<<"Name: "<< member.GetName() << endl <<"ID: "<< thing.GetPlaneID() <<endl;
			printf("Start date and time: %s\n", asctime(thing.GetStartDate()));
			printf("Start date and time: %s\n", asctime(thing.GetEndDate()));
			names.erase(names.begin()+num);
			cout<<endl;
		}
	}
	if(member.GetType() == "coPilot" || member.GetType() == "CoPilot" )
	{
		vector <Flight> names;
		bool revise =false;
		for(unsigned int i=0; i <flightInfo.size(); i++)
		{
		
			if((flightInfo.at(i)).GetCoPilotID() == names.at(i).GetCoPilotID())
			{
				names.push_back(flightInfo.at(i));
			}
		}
		
		while(names.size()>0)
		{
			Flight thing =names.at(0);
			int num =0;
			for(unsigned int i=1; i <names.size(); i++)
			{
				time_t time1 = mktime(thing.GetStartDate());
				time_t time2 = mktime(names.at(i).GetStartDate());
				if(difftime(time1,time2) < 0)
				{				
					num =i;
					thing = names.at(i);
				}
		
			}
			cout<<"Name: "<< member.GetName() << endl <<"ID: "<< thing.GetPlaneID() << endl;
			printf("Start date and time: %s\n", asctime(thing.GetStartDate()));
			printf("Start date and time: %s\n", asctime(thing.GetEndDate()));
			names.erase(names.begin()+num);
			cout<<endl;
		}
	}
	if(member.GetType() == "cabin" || member.GetType() == "Cabin" )
	{
		vector <Flight> names;
		bool revise =false;
		for(unsigned int i=0; i <flightInfo.size(); i++)
		{
		
			if((flightInfo.at(i)).GetCrew1ID() == names.at(i).GetCrew1ID())
			{
				names.push_back(flightInfo.at(i));
			}
			if((flightInfo.at(i)).GetCrew2ID() == names.at(i).GetCrew2ID())
			{
				names.push_back(flightInfo.at(i));
			}
			if((flightInfo.at(i)).GetCrew3ID() == names.at(i).GetCrew3ID())
			{
				names.push_back(flightInfo.at(i));
			}
			if((flightInfo.at(i)).GetCrew4ID() == names.at(i).GetCrew4ID())
			{
				names.push_back(flightInfo.at(i));
			}
		}
		
		while(names.size()>0)
		{
			Flight thing =names.at(0);
			int num =0;
			for(unsigned int i=1; i <names.size(); i++)
			{
				time_t time1 = mktime(thing.GetStartDate());
				time_t time2 = mktime(names.at(i).GetStartDate());
				if(difftime(time1,time2) < 0)
				{			
					num =i;
					thing = names.at(i);
				}
		
			}
			cout<<"Name: "<< member.GetName() << endl <<"ID: "<< thing.GetPlaneID() << endl;
			printf("Start date and time: %s\n", asctime(thing.GetStartDate()));
			printf("Start date and time: %s\n", asctime(thing.GetEndDate()));
			names.erase(names.begin()+num);
			cout<<endl;
		}
	}
}
