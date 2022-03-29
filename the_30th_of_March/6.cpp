#include <iostream>
#include <string>
#include "BBall.cpp"

using namespace std;

static bool isGreater(const BBall& x, const BBall& y)
{
    return x.getColor() > y.getColor();
}

void Sort(BBall** a, int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (*a[j] < *a[j + 1])
            {
                swap(a[j + 1], a[j]);
            }
            else if (*a[j] == *a[j + 1])
            {
                if (isGreater(*a[j], *a[j + 1]))
                {
                    swap(a[j + 1], a[j]);
                }
            }

        }
    }
}

int BBall::n = 0;

int main() {
    int n;
    cin >> n;

    BBall** balls = new BBall * [n];
    string str;
    for (int i = 0; i < n; i++)
    {
        int w;
        string color;
        cin >> w >> color;
        balls[i] = new BBall(w, color);
    }

    Sort(balls, n);

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << balls[i]->getW() << ' ' << balls[i]->getColor();
        cout << endl;
    }
}