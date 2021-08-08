#ifndef FLIGHTS_H
#define FLIGHTS_H
#include <string>
#include <vector>
#include "flight.h"
#include "crewMembers.h"
#include "planes.h"
using namespace std;

class Flights{
	public:
		Flights();							//default constructor
		void addFlight(Flight name);					//void function to add a flight 
		Flight searchFlight(int flightID);				//function to serach a flight through its ID
		void editFlight(int flightID);					//void function to edit a flight through its ID
		void deleteFlight(int flightID);				//void function to delete a flight by its ID
	 	void printAll();						//void function to print all flights
		void printFDetails(int flightID);				//void fuction to print flight details
		void printFSchedule(string planeID);				//void function to print flight schedule
		void printCMSchedule(int crewID,crewMembers flightInfo);	//void function to print crew members schedule
		void printFStatus();						//void dunction to print flight status
		void deleteFStatus();						//void function to delete flight status
		void updateFStatus(int flightID);				//void function to update flight status
		bool checkAvaliability(Flight temp, crewMembers persons);	//bool function to check flight availability

	private:
		int count;							//private data member to count the flights
		vector<Flight> flightInfo;					//vector to store flights info
};

#endif
