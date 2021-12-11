#include <iostream>

using namespace std;

int main()
{
    int num;
    int mult = 1;
    do
    {
        cin >> num;
        if (num % 10 == 0 && num != 0)
        {
            mult *= num;
        }
    } while (num % 13 != 0);
    if (mult == 1)
    {
        cout << "Таких чисел не было" << endl;
    }
    else
    {
        cout << mult << endl;
    }

    return 0;
}

