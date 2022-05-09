#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream in("input.txt");

    string s;
    in >> s;

    int n;
    in >> n;

    string tempRequest;

    string first;
    string second;
    for (int i = n - 1; i >= 0; i--)
    {
        in >> tempRequest;

        if (s[i] == tempRequest[0])
        {
            if (tempRequest[1] == '1')
            {
                first = tempRequest[0] + first;
            }
            else
            {
                second = tempRequest[0] + second;
            }
        }

        s.erase(s.length() - 1, 1);
        if (s.length() != 0)
        {
            cout << "Остались вагоны: " << s << '\n';
        }
        else
        {
            cout << "Вагонов не осталось\n";
        }
        
        cout << "В первом тупике: " << first << '\n';
        cout << "Во втором тупике: " << second << "\n\n";
    }

    in.close();
    
    return 0;
}

