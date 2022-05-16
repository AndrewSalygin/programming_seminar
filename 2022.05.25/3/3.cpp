#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <numeric>
#include <Windows.h>

using namespace std;
/*
Дано N чисел и M запросов вида i, j.
Для каждого запроса выведите сумму всех чисел 
начиная от i - го до j - го включительно
(эффективно решить задачу поможет какой - то алгоритм).
*/
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    vector<int> a;
    
    ifstream in("input.txt");
    ofstream out("output.txt");

    int num;
    while (in.peek() != '\n')
    {
        in >> num;
        a.push_back(num);
    }

    int range_begin;
    int range_end;
    int sum;
    while (in >> range_begin)
    {
        in >> range_end;
        if ((range_begin >= 0) && (range_end < a.size()) && (range_begin <= range_end))
        {
            sum = accumulate(begin(a) + range_begin, begin(a) + range_end + 1, 0);
            out << sum << ' ';
        }
    }

    in.close();
    out.close();
    return 0;
}

