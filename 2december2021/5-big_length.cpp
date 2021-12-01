#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main()
{
    std::srand(std::time(nullptr));
    int n, k;
    n = 100;
    k = (std::rand() * 73) % 100000;
    cout << k << endl;

    int* skis_length = new int[n];
    for (int i = 0; i < n; i++)
    {
        skis_length[i] = (std::rand() * 73) % 100000;
    }

    int total = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            if (skis_length[i] + skis_length[j] == k)
            {
                total++;
            }
        }
    }
    cout << total;

    return 0;
}