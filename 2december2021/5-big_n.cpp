#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    std::srand(std::time(nullptr));
    int n, k;
    n = 100000;
    k = std::rand() % 100;
    int* skis_length = new int[n];

    for (int i = 0; i < n; i++)
    {
        skis_length[i] = std::rand() % 100;
    }

    int arr[100] = { 0 };

    for (int i = 0; i < n; i++)
    {
        arr[skis_length[i]]++;
    }

    int total = 0;
    int fl;
    if (k % 2 == 0)
    {
        if (arr[k / 2] != 0)
        {
            total += arr[k / 2] * (arr[k / 2] - 1);
        }
        fl = k / 2;
    }
    else
    {
        fl = (k / 2) + 1;
    }

    for (int i = 1, j = k - 1; i < fl; i++, j--)
    {
        total += arr[i] * arr[j];
    }

    // порядок не важен
    cout << total / 2 << endl;

    return 0;
}
