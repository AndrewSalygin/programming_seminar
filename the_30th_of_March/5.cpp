#include <iostream>
#include <string>
#include "BBall.cpp"

using namespace std;

bool compare_bbals(BBall b1, BBall b2)
{
    return b1.getColor() > b2.getColor();
}

void Sort(BBall** a, int n)
{
    int min_index;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (compare_bbals(*a[j], *a[j + 1]))
            {
                swap(a[j + 1], a[j]);
            }
        }
    }
}

int BBall::n = 0;

int main() {
    int n;
    cin >> n;

    BBall** balls = new BBall *[n];
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