#include <iostream>

using namespace std;

bool f2(int &num)
{
    if (num < 0)
    {
        num = 0;
        return true;
    }
    return false;
}

bool f(int &a, int &b, int &c)
{
    return (f2(a) | f2(b) | f2(c));
}
int main()
{
    cout << "Введите три числа:" << endl;
    int a, b, c;
    cin >> a >> b >> c;
    f(a, b, c);

    cout << a << ' ' << b << ' ' << c;
    return 0;
}

