#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

bool f(double &a, double &eps)
{
    if (a + eps > 0)
    {
        a = sqrt(a);
        return true;
    }
    else
    {
        return false;
    }

}
int main()
{
    double num;
    double eps = 10e-6;
    for (int i = 0; i < 3; i++)
    {
        cin >> num;
        if (f(num, eps))
        {
            cout << fixed << setprecision(6) << num << '\n';
        }
        else
        {
            cout << "Число отрицательно" << '\n';
        }
    }
    return 0;
}


