#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;

    double *arr = new double[n];
    int n1, n2;

    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i < n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        cout << setprecision(30) << arr[i] << endl;
    }

    delete [] arr;
    return 0;
}


