#include <iostream>

using namespace std;

/*
    2) перегрузить копирующий оператор присваивания
    BBall& operator=(const BBall&);
    выяснить, в каком случае вызывается именно он, а
    когда конструктор копирования
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

    BBall& operator=(const BBall &other)
    {
        this->color = other.color;
        this->w = other.w;
        return *this;
    }
};

int main()
{
    BBall a;

    a.setW(2);
    a.setColor("red");

    BBall b = a;

    BBall c;

    c = a;

    return 0;
}

