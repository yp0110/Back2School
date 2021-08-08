#include <iostream>
#include <string>
#include "pig.h"
#include<iomanip>

using namespace std;

Pig::Pig(){

	pigBreed = "None";
	pigSpayneu = "None";
	pigRegID = "None";
	pigOtherComm = "None";
	pigWeight = 0.0;
	pigName = "None";
	pigGender = "None";
	pigColorDes = "None";
}

Pig::Pig(string breed, float weight, string name, string gender,string spayneu, string regID, string colordes , string othercomm){

	pigBreed = breed;
	pigSpayneu = spayneu;
	pigRegID = regID;
	pigOtherComm = othercomm;
	pigWeight = weight;
	pigName = name;
	pigGender = gender;
	pigColorDes = colordes;
}

void Pig::setBreed(string breed) {

	pigBreed = breed;

}

string Pig::getBreed() {

	return pigBreed;

}

void Pig::setWeight(float weight) {

	pigWeight = weight;

}

float Pig::getWeight() {

	return pigWeight;

}

void Pig::setName(string name) {

	pigName = name;

}

string Pig::getName() {

	return pigName;

}

void Pig::setGender(string gender) {

	pigGender = gender;

}

string Pig::getGender() {

	return pigGender;

}

void Pig::setSpayneu(string spayneu) {

	pigSpayneu = spayneu;

}

string Pig::getSpayneu() {

	return pigSpayneu;

}

void Pig::setRegID(string regID) {

	pigRegID = regID;

}

string Pig::getRegID() {

	return pigRegID;

}

void Pig::setColordes(string colordes) {

	pigColorDes = colordes;

}

string Pig::getColordes() {

	return pigColorDes;

}

void Pig::setOthercomm(string othercomm) {

	pigOtherComm = othercomm;

}

string Pig::getOthercomm() {

	return pigOtherComm;

}

void Pig::print() {

	 cout<<pigBreed<<setw(20)<<pigWeight<<setw(20)<<pigName<<setw(20)<<pigGender<<setw(20)<<pigSpayneu<<setw(20)<<pigRegID<<setw(20)<<pigColorDes<<setw(20)<<pigOtherComm<<endl;

}
