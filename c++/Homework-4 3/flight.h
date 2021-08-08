#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <string>
#include <ctime>

#include "plane.h"
#include "crewMember.h"

using namespace std;

class Flight{
	public:
		Flight();						//default constructor
		Flight(int fID, string ID, int numOfPilots, int numOfCabinCrew, int pilotID, int coPilotID, int crew1ID, int crew2ID, int crew3ID, int crew4ID, struct tm startnowLocal, struct tm endnowLocal, string startapCode, string endapCode, int numOfPassengers, string flightStatus);		//constructor with all parameters
		void SetFlightID(int fID);				//mutator function for flight id
		int GetFlightID();					//accessor function for flight id
		void SetPlaneID(string ID);				//mutator function for plane if
		string GetPlaneID();					//accessor function for plane id
		void SetNumPilots(int numOfPilots);			//mutator function for number of pilots
		int GetNumPilots();					//accessor function for number of pilots
		void SetNumCrew(int numOfCabinCrew);			//mutator function for number of cabin crew
		int GetNumCrew();					//accessor function for number of cabin crew
		void SetPilotID(int pilotID);				//mutator function for pilot id
		int GetPilotID();					//accessor function for pilot id
		void SetCoPilotID(int coPilotID);			//mutator function for co-pilot id
                int GetCoPilotID();					//accessor function for co-pilot id
		void SetCrew1ID(int crew1ID);				//mutator function for cabin crew member1
		int GetCrew1ID();					//accessor function for cabin crew member1
		void SetCrew2ID(int crew2ID);				//mutator function for cabin crew member2
                int GetCrew2ID();					//accessor function for cabin crew member2
		void SetCrew3ID(int crew3ID);				//mutator function for cabin crew member3
                int GetCrew3ID();					//accessor function for cabin crew member3
		void SetCrew4ID(int crew4ID);				//mutator function for cabin crew member4
                int GetCrew4ID();					//accessor function for cabin crew member4
		void SetStartDate(struct tm startnowLocal);		//mutator funtion for start date and time
		struct tm* GetStartDate();				//accessor funtion for start date and time
		void SetEndDate(struct tm endnowLocal);			//mutator funtion for end date and time
		struct tm* GetEndDate();				//accessor funtion for end date and time
		void SetStartCode(string startapCode);			//mutator function for starting airport code
		string GetStartCode();					//accessor function for starting airport code	
		void SetEndCode(string endapCode);			//mutator function for ending airport code
		string GetEndCode();					//accessor function for ending airport code
		void SetNumPassengers(int numOfPassengers);		//mutator function for number of passengers
		int GetNumPassengers();					//accessor function for number of passengers
		void SetStatus(string flightStatus);			//mutator function for status
		string GetStatus();					//accessor function for status

	private:
		int flightID;						//private data member for flight ID
		string planeID;						//private data member for plane id
		int numPilots;						//private data member for number of pilots
		int numCrew;						//private data member for number of cabin crew
		int pID;						//private data member for pilot id
		int cpID;						//private data member for co-pilot id
		int cm1ID;						//private data member for cabin crew 1
		int cm2ID;						//private data member for cabin crew 2
		int cm3ID;						//private data member for cabin crew 3
		int cm4ID;						//private data member for cabin crew 4
		struct tm* startDate;					//private data member for starting date and time 
		struct tm* endDate;					//private data member for ending date and time
		string startAirportCode;				//private data member for starting airport code
		string endAirportCode;					//private data member for ending airport code
		int numPassengers;					//private data member for number of passengers
		string currStatus;					//private data member for current status
};

#endif
