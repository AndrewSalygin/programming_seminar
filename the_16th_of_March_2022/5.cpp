#include <iostream>
#include <cmath>

using namespace std;

/*
    5) добавить в класс статический счётчик
    количества прямоугольных треугольников
*/

const double EPS = 10e-12;

class Triangle
{
    double length[3];

public:
    static int k_right_triangle;
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
    bool is_right_triangle()
    {
        for (int i = 0; i < 3; i++)
        {
            if (pow(this->length[i], 2) == pow(this->length[(i + 1) % 3], 2) +
                pow(this->length[(i + 2) % 3], 2))
            {
                return true;
            }
        }
        return false;
    }

    Triangle(double length1, double length2,
             double length3)
    {
        double length[3] = {length1, length2, length3};
        this->setLength(length);
        if (is_right_triangle())
            k_right_triangle++;
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

int Triangle::k_right_triangle;

int main()
{
    Triangle a(5, 3, 4);
    Triangle b(4, 3, 4);


    if (a == b)
    {
        cout << "RIGHT" << '\n';
    }
    else
    {
        cout << "FALSE" << '\n';
    }

    cout << Triangle::k_right_triangle;
    return 0;
}



