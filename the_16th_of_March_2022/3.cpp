#include <iostream>

using namespace std;

/*
    3) создать класс "Треугольник"с полями -
    длинами сторон, класс должен следить за
    корректностью значений
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
                << "равной нулю!" << '\n';
                return false;
            }
        }
    }
    Triangle(double length1, double length2,
             double length3)
    {
        double length[3] = {length1, length2, length3};
        this->setLength(length);
    }
};

int main()
{
    Triangle a(3, 4, 5);
    Triangle b(3, -2, 5);
    Triangle c(0, 1, 5);
    return 0;
}


