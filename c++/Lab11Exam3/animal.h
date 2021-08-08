#include <iostream>
#include <string>

using namespace std;

 class Animal {

	private:

		string animalBreed;

		float animalWeight;

		string animalName;

		string animalGender;

		string animalColordes;
	public:

		Animal();

		Animal( float animalWeight, string animalName, string animalGender, string animalColordes);

                void setWeight(float weight);

                void setName(string name);

                void setGender(string gender);

                void setColordes(string colordes);

                virtual void printinfo();

                float getWeight();

                string getName();

                string getGender();

                string getColordes();
};
