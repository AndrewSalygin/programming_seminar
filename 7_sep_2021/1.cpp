#define _USE_MATH_DEFINES

#include <iostream>
#include <math.h>

using namespace std;

void main()
{
    setlocale(LC_ALL, "Russian");
    double angle, hip;
    cout << "¬ведите значение гипотенузы: ";
    cin >> hip;
    cout << "¬ведите значение угла: ";
    cin >> angle;

    double x = hip * cos(angle * M_PI / 180.0); //One radian is equivalent to 180/PI degrees. 
    double y = hip * sin(angle * M_PI / 180.0); // 1 rad = 180/PI deg => n deg = PI/180 * n

    cout << "ѕериметр: " << x + y + hip << '\n';
    cout << "ѕлощадь: " << (x * y) / 2.0 << '\n';
}