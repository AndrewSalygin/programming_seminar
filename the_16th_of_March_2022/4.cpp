#include <iostream>
#include <cmath>

using namespace std;

/*
    4) добавить треугольникам методы подсчёта
    площади и периметра, перегрузить "==" и
    "!=" без учёта порядка перечисления сторон
*/

const double EPS = 10e-12;

class Triangle
{
    double length[3];

public:
    bool setLength(double *length)
    {
        for (int i = 0; i < 3; i++)
        {
            if (length[i] > 0 + EPS)
            {
                this->length[i] = length[i];
            }
            else
            {
                cout << "Сторона не может быть отрицательной или "
                << "равной нулю!";
                return false;
            }
        }
    }
    double perimeter()
    {
        double sum = 0;
        for (int i = 0; i < 3; i++)
        {
            sum += this->length[i];
        }
        return sum;
    }
    double area()
    {
        double half_p = this->perimeter() / 2;
        double result = sqrt(half_p);
        for (int i = 0; i < 3; i++)
        {
            result *= sqrt(half_p - this->length[i]);
        }
        return result;
    }
    Triangle(double length1, double length2,
             double length3)
    {
        double length[3] = {length1, length2, length3};
        this->setLength(length);
    }
    bool operator==(Triangle other)
    {
        bool flag;
        for (int i = 0; i < 3; i++)
        {
            flag = false;
            for (int j = 0; j < 3; j++)
            {
                if (abs(this->length[i] - other.length[j]) < EPS)
                {
                    flag = true;
                    other.length[j] = 0;
                    break;
                }
            }
            if (!flag)
            {
                return false;
            }
        }
        return true;
    }
    bool operator!=(const Triangle &other)
    {
        return !(*this == other);
    }
};

int main()
{
    Triangle a(3, 4, 4);
    Triangle b(4, 3, 4);

    if (a == b)
    {
        cout << "RIGHT";
    }
    else
    {
        cout << "FALSE";
    }
    return 0;
}


