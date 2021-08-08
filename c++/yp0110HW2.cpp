#include <iostream>
#include <string>
using namespace std;

enum Options {ADD = 1, MEAN = 2, MINIMUM = 3, MAXIMUM = 4, EXIT = 5}; //declairing enum choices
int Choice; 
int main ()
{

cout << " +-----------------------------------------------------+ " << endl;
cout << " |      Computer Science and Engineering               | " << endl;
cout << " |       CSCE 1030 - Computer Science I                | " << endl;
cout << " |  Yashasvi Palawat  yp0110 yashasvipalawat@my.unt.edu| " << endl;
cout << " +-----------------------------------------------------+ " << endl;

bool condition = true;
 while (condition){
float num1;
cout << "1. Computer sum of 6 Floating-point numbers" <<endl;
cout << "1. Computer sum of 6 Floating-point numbers" <<endl; 
cout << "2. Computer Mean of 6 Floating-point numbers" <<endl;
cout << "3. Computer MIN of 6 Floating-point numbers" <<endl; 
cout << "4. Computer Max of 6 Floating-point numbers" <<endl;
cin  >>  Choice;
	switch (Choice)
	{
		case ADD:
		{
		int local_num1 = 1;
		float sum = 0;
		while (local_num1 < 7)
		{
			cout << "Enter Number" << local_num1 << ": "; 
			cin  >> num1;
 			 sum += num1;
			local_num1 ++;
		}

			cout << "The sum of 6 numbers is: " << sum << endl;
		}
		break;

		case MEAN:
		{
		int local_num = 1;
		float Mean = 0;
		while (local_num < 7)
		{
			cout << "Enter Number" << local_num << ": ";
			cin >> num1;
			Mean += num1;
			local_num ++;
		}
			Mean = Mean / 6;
		cout << " The Mean of 6 numbers is" << Mean << endl;
		}
		break;

		case MINIMUM:
		{
		int local_num2 = 1;
		 float Minimum = 1000000;
		while (local_num2 < 7) 
		{
			cout << "Enter Number" <<  local_num2 << ": ";
			cin >> num1;

			if ( num1 < Minimum){
				Minimum = num1;
						}
			local_num2 ++;
		}
			cout << " The Minimum of 6 number is: " << Minimum << endl;
		}	
		break;
		case MAXIMUM:
		{
                int local_num3 = 1;
                 float Maximum = -1000000 ;
                while (local_num3 < 7) 
                {
                        cout << "Enter Number" <<  local_num3 << ": ";
                        cin >> num1;
                        if ( num1 > Maximum){
                                Maximum = num1;
                                                }

			local_num3 ++;
                }
                        cout << " The Maximum of 6 number is: " << Maximum << endl;
                }
		break;

		case EXIT:{
		cout << " Thank you for using this program! Have a great day! " << endl;
		condition = false;
			  }
		break;
		default:
			cout << " Invalid selection (" << Choice << ").  Please enter choice 1 - 5." << endl;
		break;
	}
    }





/*	case MEAN:
		cout << "Enter Number 1: ";
                cin >>  num1
                cout << "Enter Number 2: ";
                cin >>  num2
                cout << "Enter Number 3: ";
                cin >>  num3
                cout << "Enter Number 4: ";
                cin >>  num4
                cout << "Enter Number 5: ";
                cin >>  num5
                cout << "Enter Number 6: ";
                cin >>  num6
                        float Mean = (num1 + num2 + num3 + num4 + num5 + num6) / 6;
                cout << "The Mean of 6 numbers is: " << Mean << endl;
		break;

	case MINIMUM:
		cout << "Enter Number 1: ";
                cin >>  num1
                cout << "Enter Number 2: ";
                cin >>  num2
                cout << "Enter Number 3: ";
                cin >>  num3
                cout << "Enter Number 4: ";
                cin >>  num4
                cout << "Enter Number 5: ";
                cin >>  num5
                cout << "Enter Number 6: ";
                cin >>  num6
                for (int i = 1; i < N; i++)
		{



 		}
                cout << "The sum of 6 numbers is: " << sum << endl;

		cout << "Your result is " << num1 - num2 << endl;
		break;
	case MAXIMUM:
		cout << "Please enter two numbers to divide: ";
		cin >> num1 >> num2;
		if (num2 == 0) {
		  cout << "Error! Your demonimator cannot be 0!" << endl;
		}
		else {
		  cout << "Your result is " << num1 / num2 << endl;   
		}
		break;
	  default:
		cout << "That is not a valid choice." << endl;
		break;
*/



























return 0;
}
