#include <iostream>

using namespace std;

/*
    1) в классе BBall перегрузить сравнение
    "<" (только по весу) и "==" (и по весу, и по цвету)
*/

class BBall
{
    int w;
    string color;

public:
    bool setColor(string color)
    {
        if (color != "")
        {
            this->color = color;
            return true;
        }
        return false;
    }
    bool setW(int w)
    {
        if (w > 0)
        {
            this->w = w;
            return true;
        }
        return false;
    }

    int getW()
    {
        return w;
    }
    string getColor()
    {
        return color;
    }

    bool operator<(const BBall &ball)
    {
        return (this->w < ball.w);
    }
    bool operator==(const BBall &ball)
    {
        return ((this->color == ball.color) &&
            (this->w == ball.w));
    }
};

int main()
{
    BBall a;
    a.setW(2);
    a.setColor("red");

    BBall b;
    b.setW(3);
    b.setColor("green");

    if (a < b)
    {
        cout << "a легче b" << '\n';
    }
    else
    {
        cout << "a тяжелее b" << '\n';
    }

    if (a == b)
    {
        cout << "Они одинаковы" << '\n';
    }
    else
    {
        cout << "Они разные" << '\n';
    }

    return 0;
}

