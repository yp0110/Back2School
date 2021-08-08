
#include <iostream>
#include <string> 
#include "flight.h"

using namespace std;

Flight::Flight()							//asigning no values to data members
{
	flightID = 0;
	planeID = "";
	numPilots = 0;
	numCrew = 0;
	pID = 0;
	cpID = 0;
	cm1ID = 0;
	cm2ID = 0;
	cm3ID = 0;
	cm4ID = 0;
	startAirportCode = "";
	endAirportCode = "";
	numPassengers = 0;
	currStatus = "";
}
Flight::Flight(int fID, string ID, int numOfPilots, int numOfCabinCrew, int pilotID, int coPilotID, int crew1ID, int crew2ID, int crew3ID, int crew4ID, struct tm startnowLocal, struct tm endnowLocal, string startapCode, string endapCode, int numOfPassengers, string flightStatus)		//assigning parameters to data members
{
	flightID = fID;
	planeID = ID;
	numPilots = numOfPilots;
	numCrew = numOfCabinCrew;
	pID = pilotID;
	cpID = coPilotID;
	cm1ID = crew1ID;
	cm2ID = crew2ID;
	cm3ID = crew3ID;
	cm4ID = crew4ID;
	startAirportCode = startapCode;
	endAirportCode = endapCode;
	numPassengers = numOfPassengers;
	currStatus = flightStatus;
}
void Flight::SetFlightID(int fID)				//set funtion for flight id
{
	flightID = fID;
}
void Flight::SetPlaneID(string ID)				//set funtion for plane id
{
	planeID = ID;
}
void Flight::SetNumPilots(int numOfPilots)			//set funtion for number of pilots
{
	numPilots = numOfPilots;
}
void Flight::SetNumCrew(int numOfCabinCrew)			//set funtion for number of cabin crew
{
	numCrew = numOfCabinCrew;
}
void Flight::SetPilotID(int pilotID)				//set funtion for pilot id
{
	pID = pilotID;
}
void Flight::SetCoPilotID(int coPilotID)			//set funtion for co-pilot id
{
	cpID = coPilotID;
}
void Flight::SetCrew1ID(int crew1ID)				//set funtion for cabin crew1 id
{
	cm1ID = crew1ID;
}
void Flight::SetCrew2ID(int crew2ID)				//set funtion for cabin crew2 id
{
	cm2ID = crew2ID;
}
void Flight::SetCrew3ID(int crew3ID)				//set funtion for cabin crew3 id
{
	cm3ID = crew3ID;
}
void Flight::SetCrew4ID(int crew4ID)				//set funtion for cabin crew4 id
{
	cm4ID = crew4ID;
}
void Flight::SetStartDate(struct tm startnowLocal)		//set funtion for starting date and time
{
	startDate = &startnowLocal;
}
void Flight::SetEndDate(struct tm endnowLocal)			//set function for ending date and time
{
	endDate = &endnowLocal;
}
void Flight::SetStartCode(string startapCode)			//set funtion for starting airport code
{
	startAirportCode = startapCode;
}
void Flight::SetEndCode(string endapCode)			//set funtion for ending airport code
{
	endAirportCode = endapCode;
}
void Flight::SetNumPassengers(int numOfPassengers)		//set funtion for number of passengers
{
	numPassengers = numOfPassengers;
}
void Flight::SetStatus(string flightStatus)			//set funtion for flight status
{
	currStatus = flightStatus;
}
int Flight::GetFlightID()					//get function for flight id
{
	return flightID;
}
string Flight::GetPlaneID()					//get function for plane id
{
	return  planeID;
}
int Flight::GetNumPilots()					//get function for number of pilots
{
	return numPilots;
}
int Flight::GetNumCrew()					//get function for number of cabin crew
{
	return numCrew;
}
int Flight::GetPilotID()					//get function for pilot id
{		
	return pID;
}
int Flight::GetCoPilotID()					//get function for co-pilot id
{
	return cpID;
}
int Flight::GetCrew1ID()					//get function for cabin crew1 id
{
	return cm1ID;
}
int Flight::GetCrew2ID()					//get function for cabin crew2 id
{
	return cm2ID;
}
int Flight::GetCrew3ID()					//get function for cabin crew3 id
{
	return cm3ID;
}
int Flight::GetCrew4ID()					//get function for cabin crew4 id
{
	return cm4ID;
}
struct tm* Flight::GetStartDate()				//get function for start date and time
{
	return startDate;
}
struct tm* Flight::GetEndDate()					//get function for end date and time
{
	return endDate;
}
string Flight::GetStartCode()					//get function for starting airport code
{
	return startAirportCode;
}
string Flight::GetEndCode()					//get function for ending airport code
{
	return endAirportCode;
}
int Flight::GetNumPassengers()					//get function for number of passengers
{
	return numPassengers;
}
string Flight::GetStatus()					//get function for  status
{
	return currStatus;
}
