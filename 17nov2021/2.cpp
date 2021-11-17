#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double area_circle(const double &r)
{
    return acos(-1)*(r*r);
}
double area_square(const double &a)
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

    if (area_circle(r) + eps < area_square(a))
    {
        cout << "Площадь круга меньше площади квадрата";
    }
    else if (area_square(a) + eps < area_circle(r))
    {
        cout << "Площадь квадрата меньше площади круга";
    }
    else
    {
        cout << "Площади равны";
    }
    return 0;
}

