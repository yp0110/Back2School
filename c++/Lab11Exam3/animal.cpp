#include <iostream>
#include "animal.h"
#include <string>

using namespace std;

Animal::Animal(){

	animalWeight = 0.0;
	animalName = "None";
	animalGender = "None";
	animalColordes = "None";
}

Animal::Animal(float weight,string name,string gender,string colordes){

	animalWeight = weight;
	animalName = name;
	animalGender = gender;
	animalColordes = colordes;

}

void Animal::setWeight(float weight) {

	animalWeight = weight;
}

float Animal::getWeight() {

	return animalWeight;
}

void Animal::setName(string name) {

	animalName = name;

}

string Animal::getName() {

	return animalName;

}

void Animal::setGender(string gender) {

	animalGender = gender;

}

string Animal::getGender() {

	return animalGender;

}

void Animal::setColordes(string colordes) {

	animalColordes = colordes;

}

string Animal::getColordes() {

	return animalColordes;

}
void Animal::printinfo() {

	cout << "Animal's Weight: " << animalWeight <<endl;

	cout << "Animal's Name: " << animalName << endl;

	cout << "Animal's Gender: " << animalGender << endl;

	cout << "Animal's Color description: " << animalColordes <<endl;
}
