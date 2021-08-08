#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int countVowels(char array[]);

int main()
{

	char array[36];
	string sentence;
	int length;
	int vowleNum = 0;
	cout << "Enter a sentence up to 35 characters: " << endl;

	cin.getline(array, 36);

	length = countVowels(sentence);

	for (int i = 0; i < 35, i++)
	{

		if(countVowels (char array [36]))
		{
			vowelNum ++
		}
	}


	cout << "Your sentence contains " << vowelNum << " vowels." << endl;


	cin.get ();

	return 0;
}

int countVowels(char array[])
{


	if(array[i] == 'a'|| array[i] == 'e'||array[i] =='i' ||array[i] =='o'||arry[i] == 'u');
	{

		array[i]++
	}

	return array[i];

}
