#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main ()
{


 cout << " +-----------------------------------------------------+ " << endl;
 cout << " |      Computer Science and Engineering               | " << endl;
 cout << " |       CSCE 1030 - Computer Science I                | " << endl;
 cout << " |  Yashasvi Palawat  yp0110 yashasvipalawat@my.unt.edu| " << endl;
 cout << " +-----------------------------------------------------+ " << endl;



 const double G = 6.673e-11; // Gravitational Constant
 double Mass;                // Mass of the Planet (in Kg)
 double AccelGravity;       // Acceleration due to Gravity
 long int Radius;           // Radius of the Planet (in Meters)
 int Height;               // Height of the object from the surface (in Feets)
 double Time;              // time to reach the surface (in seconds)

 cout << "Enter Mass in Kg:" << endl;
 cin >> Mass;
 cout << "Enter radius in meters:" << endl;
 cin >> Radius;
 AccelGravity = (G * Mass) / pow(Radius, 2);  // equation for calculating Acceleration due to Gravity
 cout.setf(ios::fixed);
 cout.setf(ios::showpoint);
 cout.precision(2);                           // Decimel points precision to 2
 cout << "The acceleration due to gravity is " << AccelGravity << " meters per second squared" << endl;
 cout << "Enter the height in feet:" << endl;
 cin >> Height;
 Time = sqrt((2 * Height) / (AccelGravity * 3.28));    // equation for Time to reach surface
 cout << "The object will reach the surface in " << Time << " seconds" << endl;

return 0;
}
