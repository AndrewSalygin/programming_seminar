#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main()
{
    std::srand(std::time(nullptr));
    int n, k;
    n = 10000;
    k = std::rand();

    int *skis_length = new int[n];
    int *skis_pars = new int[n];
    for (int i = 0; i < n; i++)
    {
        skis_length[i] = std::rand();
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (skis_length[i] + skis_length[j] == 2)
            {

                skis_pars[i]++;
            }
        }
    }

    return 0;
}


