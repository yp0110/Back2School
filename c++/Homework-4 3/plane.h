

#ifndef PLANE_H
#define PLANE_H
#include <iostream>
#include <string>

using namespace std;

class Plane{
	public:
		Plane();					//deafult constructor
		Plane(string planeMake, int planeModel, string planeTailNumber, int planeNumOfSeats, int planeRange, int planeMinNumOfCabinCrew);	//constructor with all data
		void SetMake(string planeMake);				//mutator function for make
		string GetMake();					//accessor function for make
		void SetModel(int planeModel);				//mutator function for model
		int GetModel();						//accessor function for model
		void SetTailNum(string planeTailNumber);		//mutator function for tail number
		string GetTailNum();					//accessor function for tail number
		void SetNumSeats(int planeNumOfSeats);			//mutator function for number of seats
		int GetNumSeats();					//accessor function for number of seats
		void SetRange(int planeRange);				//mutator function for the range
		int GetRange();						//accessor function for the range
		void SetMinCabinCrew(int planeMinNumofCabinCrew);	//mutator function for minimum number of crew
		int GetMinCabinCrew();					//accessor function for minimum number of crew
		
	private:
		string make;						//private data member for make
		int model;						//private data member for model
		string tailNumber;					//private data member for tail number
		int numOfSeats;						//private data member for number of seats
		int range;						//private data member for range
		int minNumOfCabinCrew;					//private data member for minimum number of cabin crew
};

#endif
