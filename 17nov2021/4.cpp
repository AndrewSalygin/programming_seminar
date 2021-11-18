#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

bool correctness(double &a, double &b, double &eps)
{
    if ((a * b) + eps < 0)
    {
        cout << "Данные некорректны" << '\n';
        return false;
    }
    return true;
}

double geometric_average(double &a, double &b)
{
    return sqrt(a*b);
}

double arithmetic_average(double &a, double &b)
{
    return (a * b) / 2;
}

bool f(double &a, double &b, double &eps)
{
    if (a > b + eps)
    {
        return true;
    }
    return false;
}
int main()
{
    double num1, num2;
    double eps = 10e-6;

    cout << "Введите два числа из первой пары: ";
    cin >> num1 >> num2;

    if (!correctness(num1, num2, eps))
    {
        return 0;
    }

    double arif1 = arithmetic_average(num1, num2);
    double geom1 = geometric_average(num1, num2);

    cout << "Введите два числа из второй пары: ";
    cin >> num1 >> num2;

    if (!correctness(num1, num2, eps))
    {
        return 0;
    }

    double arif2 = arithmetic_average(num1, num2);
    double geom2 = geometric_average(num1, num2);

    double max1, max2;
    if (f(arif1, geom1, eps))
    {
        max1 = arif1;
    }
    else
    {
        max1 = geom1;
    }
    if (f(arif2, geom2, eps))
    {
        max2 = arif2;
    }
    else
    {
        max2 = geom2;
    }

    if (f(max1, max2, eps))
    {
        cout << "Среднее первой пары больше" << '\n';
    }
    else if (f(max2, max1, eps))
    {
        cout << "Среднее второй пары больше" << '\n';
    }
    else
    {
        cout << "Средние равны" << '\n';
    }

    return 0;
}


