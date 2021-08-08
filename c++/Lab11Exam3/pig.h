#include <iostream>
#include <string>
#include "animal.h"

using namespace std;

class Pig {
		private:

		string pigBreed;

		string pigSpayneu;

		string pigOtherComm;

		float pigWeight;

		string pigName;

		string pigGender;

		string pigRegID;

		string pigColorDes;

		void getBreed(string breed);

		string setBreed();

		void getName(string name);

		string setName();

		void getGender(string gender);

		string setGender();

	public:

		Pig();

		Pig(string breed, float weight, string name, string gender, string spayneu, string regID, string colordes , string othercomm);

		 void setBreed(string breed);

		string getBreed();

		void setWeight(float weight);

		float getWeight();

		void setName(string name);

		string getName();

		void setGender(string gender);

		string getGender();

		void setSpayneu(string spayneu);

		string getSpayneu();

		void setRegID(string ID);

		string getRegID();

		void setColordes(string colordes);

		string getColordes();

		void setOthercomm(string othercomm);

		string getOthercomm();

		void print();
};
