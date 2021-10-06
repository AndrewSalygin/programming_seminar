#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    cout << "Enter the coordinates of the point (x, y): ";
    double x, y;
    cin >> x >> y;

    cout << "Enter the coordinates of the start point of the circle (x0, y0): ";
    double x0, y0;
    cin >> x0 >> y0;

    cout << "Enter the radius of the circle: ";
    double r;
    cin >> r;

    cout << "Distance to circle: " << abs(sqrt(pow(x - x0, 2) + pow(y - y0, 2)) - r);

    return 0;
}