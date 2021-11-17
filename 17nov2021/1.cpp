#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double sum = 0;
    for (int i = 1; i <= 100000; i++)
    {
        sum += 1. / i;
    }
    cout << fixed << setprecision(6) << sum << '\n';

    sum = 0;
    for (int i = 100000; i > 0; i--)
    {
        sum += 1. / i;
    }
    cout << fixed << setprecision(6) << sum << '\n';

    return 0;
}

