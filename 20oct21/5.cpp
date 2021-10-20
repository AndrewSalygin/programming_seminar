#include <iostream>

using namespace std;

int main()
{
    int num;
    int k = 0;
    do
    {
        cin >> num;
        if (num % 2 != 0)
        {
            ++k;
        }
    } while (num != 0);
    cout << "Количество нечётных - " << k;
    return 0;
}

