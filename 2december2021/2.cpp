#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double eps = 10e-12;
    double num = 4, prednum, s = 0, i = 2, fact = 1;
    while (abs(num - prednum) > eps)
    {
        prednum = num;
        num = (i + 3) / (fact * i);
        s += num;

        fact = fact * i;
        i++;
    }

    cout << fixed << setprecision(12) << s;
    return 0;
}

