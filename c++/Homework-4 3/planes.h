
#ifndef PLANES_H
#define PLANES_H

#include <iostream>
#include <string>
#include <vector>
#include "plane.h"

using namespace std;

class Planes{
	public:
		Planes();				//default constructor
		void addPlane(Plane airline);		//void function to add a plane
		Plane searchMember(string planeID);	//function to search a plane through its ID
		void editPlane(string planeID);		//void function to edit a plane through its ID
		void deletePlane(string planeID);	//void function to delete a plane through its ID
		void printAll();			//void function to print all planes
		void printPlanes(string planeID);	//void function to print a particular plane's details through its ID

	private:
		int count;				//private data member to have the count
		vector<Plane> airlines;			//vector to store the panes and its info
};

#endif
