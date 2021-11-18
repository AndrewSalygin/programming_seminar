#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double pi = acos(-1);

double area_circle(double &r)
{
    return pi*(r*r);
}
double area_square(double &a)
{
    return a*a;
}
int main()
{
    double a, r;

    cout << "Введите длину стороны квадрата: " << '\n';
    do
    {
        cin >> a;
    } while (a < 0);

    cout << "Введите длину радиуса окружности: " << '\n';
    do
    {
        cin >> r;
    } while (r < 0);

    double eps = 10e-6;

    double area_crcl = area_circle(r);
    double area_sqr = area_square(a);

    if (area_crcl + eps < area_sqr)
    {
        cout << "Площадь круга меньше площади квадрата";
    }
    else if (area_sqr + eps < area_crcl)
    {
        cout << "Площадь квадрата меньше площади круга";
    }
    else
    {
        cout << "Площади равны";
    }
    return 0;
}
