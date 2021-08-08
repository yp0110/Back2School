#include <iostream>
#include <string> 
#include "plane.h"

using namespace std;

Plane::Plane()								 //assigning no value to all data members
{
	make = "";
	model = 0;
	tailNumber = "";
	numOfSeats = 0;
	range = 0;
	minNumOfCabinCrew = 0;
}
Plane::Plane(string planeMake, int planeModel, string planeTailNumber, int planeNumOfSeats, int planeRange, int planeMinNumOfCabinCrew)		 //assigning values to all data members
{
	make = planeMake;
	model = planeModel;
	tailNumber = planeTailNumber;
	numOfSeats = planeNumOfSeats;
	range = planeRange;
	minNumOfCabinCrew = planeMinNumOfCabinCrew;
}
void Plane::SetMake(string planeMake)					//set function for make
{
	make = planeMake;
}
void Plane::SetModel(int planeModel)					//set function for model
{
	model = planeModel;
}
void Plane::SetTailNum(string planeTailNumber)				//set function for tail number
{
	tailNumber= planeTailNumber;
}
void Plane::SetNumSeats(int planeNumOfSeats)				//set function for number of seats
{
	numOfSeats = planeNumOfSeats;
}
void  Plane::SetRange(int planeRange)					//set function for range
{
	range = planeRange;
}
void Plane::SetMinCabinCrew(int planeMinNumOfCabinCrew)			//set function for minimum number of cabin crew
{
	minNumOfCabinCrew = planeMinNumOfCabinCrew;
}

string Plane::GetMake()							//get function for make
{
	return make;
}
int Plane::GetModel()							//get function for model
{
	return model;
}
string Plane::GetTailNum()						//get function for tail number
{
	return tailNumber;
}
int Plane::GetNumSeats()						//get function for number of seats
{
	return numOfSeats;
}
int Plane::GetRange()							//get function for range
{
	return range;
}
int Plane::GetMinCabinCrew()						//get function for minimum number of cabin crew
{
	return minNumOfCabinCrew;
}
