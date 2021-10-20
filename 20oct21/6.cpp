#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cout << "Введите значения переменных (a, b): ";
    double a, b;
    cin >> a >> b;
    cout << "Введите значения отрезка [c; d]: ";
    double c, d;
    cin >> c >> d;
    cout << "Введите шаг (h): ";
    double h;
    cin >> h;
    double eps = 0.0001;
    while (c < d + eps)
    {
        if (c == 1.0)
        {
            cout << "Неопределено" << '\n';
        }
        else
        {
            cout << c << " - " << (a * pow(c, 3)) + (b / (c - 1.0)) << '\n';
        }
        c += h;
    }
    return 0;
}

