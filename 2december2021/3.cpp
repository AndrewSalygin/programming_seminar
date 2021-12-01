#include <iostream>
using namespace std;

void swap_elem(int *arr, int &n1, int &n2)
{
    int temp;
    temp = arr[n1];
    arr[n1] = arr[n2];
    arr[n2] = temp;
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

    if (n % 2 == 0)
    {
        int n1 = (n / 2) - 1;
        int n2 = n / 2;

        swap_elem(arr, n1, n2);
    }
    else
    {
        arr[n / 2] *= 2;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    delete [] arr;
    return 0;
}

