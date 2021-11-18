#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n = 100000;
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += 1. / i;
    }
    cout << fixed << setprecision(20) << sum << '\n';

    sum = 0;
    for (int i = n; i > 0; i--)
    {
        sum += 1. / i;
    }
    cout << fixed << setprecision(20) << sum << '\n';

    return 0;
}

