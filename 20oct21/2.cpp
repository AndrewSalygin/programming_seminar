#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n > 0)
    {
        for (int i = 1; i <= n; ++i)
        {
            cout << i << '\n';
        }
    }
    else if (n < 0)
    {
        for (int i = 1; i >= n; --i)
        {
            cout << i << '\n';
        }
    }
    else
    {
        cout << 0 << '\n';
    }
    return 0;
}

