#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    int last_neg = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] < 0)
        {
            last_neg = arr[i];
        }
    }

    if (last_neg != 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < 0)
            {
                arr[i] = last_neg;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }


    return 0;
}

