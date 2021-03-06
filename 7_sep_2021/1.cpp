#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double angle, hyp;
    cout << "Enter the hypotenuse value: ";
    cin >> hyp;
    cout << "Enter the angle value: ";
    cin >> angle;

    double x = hyp * cos(angle * M_PI / 180.0); //One radian is equivalent to 180/PI degrees. 
    double y = hyp * sin(angle * M_PI / 180.0); // 1 rad = 180/PI deg => n deg = PI/180 * n

    cout << "Perimeter: " << x + y + hip << '\n';
    cout << "Area: " << (x * y) / 2.0 << '\n';
    
    return 0;
}