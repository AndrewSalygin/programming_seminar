#include <iostream>

using namespace std;

int f(const int *arr, int n)
{
    if (n != 0)
    {
        return f(arr, n - 1) * arr[n - 1];
    }
    else
    {
        return 1;
    }
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << f(arr, n);
    return 0;
}
