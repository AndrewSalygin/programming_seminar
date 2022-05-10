#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream in("input.txt");

    string s;
    in >> s;

    string sList = s;
    list<char> List;
    for (int i = 0; i < s.size(); i++)
    {
        List.push_back(s[i]);
    }

    int n;
    in >> n;

    string tempRequest;

    list<char> firstList;
    list<char> secondList;
    for (int i = n - 1; i >= 0; i--)
    {
        in >> tempRequest;

        if (sList[i] == tempRequest[0])
        {
            if (tempRequest[1] == '1')
            {
                firstList.emplace(firstList.begin(), tempRequest[0]);
            }
            else
            {
                secondList.insert(secondList.begin(), tempRequest[0]);
            }
        }

        sList.erase(sList.length() - 1, 1);
        if (sList.length() != 0)
        {
            cout << "Остались вагоны: " << sList << '\n';
        }
        else
        {
            cout << "Вагонов не осталось\n";
        }

        cout << "В первом тупике: ";

        for (char i : firstList)
        {
            cout << i;
        }
            
        cout << '\n';

        cout << "Во втором тупике: ";

        for (char i : secondList)
        {
            cout << i;
        }

        cout << '\n';
    }



    in.close();

    return 0;
}