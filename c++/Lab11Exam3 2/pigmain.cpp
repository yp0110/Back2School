#include <iostream>
#include <string>
#include <vector>
#include "pig.h"
#include<iomanip>

using namespace std;

int main() {

	string breed;
	float weight;
	string name;
	string gender;
	string spayneu;
	string regID;
	string colordes;
	string othercomm;

	vector<Pig*> PigInfo;
	vector<Animal*> AnimalInfo;

	for(int i =0; i <5 ; i++) {

		cout << " Pigs " << i+1 << endl;

		cout << "Enter Pig Breed: ";

		cin >> breed;

		cout << "Enter Pig Weight:";

		cin >> weight;

		cout << "Enter Pig Name:";

		cin >> name;

		cout << "Enter Pig Gender:";

		cin >> gender;

 		cout <<"Enter Pig Spayed: ";

		cin>>spayneu;

		cout << "Enter Pig Registration ID:";

		cin >> regID;

		cout << "Enter the Color Description of the Pig:";

		cin.ignore();
		getline(cin,colordes);

		cout << "Enter any Other Comments about the Pig:";

		cin.ignore();
		getline(cin,othercomm);
	Pig* Pigg;

	Pig newAnimal(breed, weight, name, gender, spayneu, regID, colordes, othercomm);

	Pigg= &newAnimal;

	PigInfo.push_back(Pigg);

	cout << endl;
	}

	 {

	         cout<<"BREED"<<setw(20)<<"WEIGHT"<<setw(20)<<"NAME"<<setw(20)<<"GENDER"<<setw(20)<<"Spaneu"<<setw(20)<<"Registration ID"<<setw(20)<<"COLOR"<<setw(20)<<"COMMENTS"<<endl;

	for (vector<Pig*>::iterator P=PigInfo.begin(); P != PigInfo.end(); P++){

		 (*P)->print();
	}

}

	AnimalInfo.clear();

	PigInfo.clear();

	return 0;
}
