#include <iostream> 
#include <vector>
#include <list>
#include <fstream>
#include <algorithm>
using namespace std;

// Проверка на простоту числа
bool isPrime(unsigned long a)
{
    unsigned long i;
    if (a == 2)
        return true;
    if (a == 0 || a == 1 || a % 2 == 0)
        return false;
    for (i = 3; i * i <= a && a % i; i += 2);
    return i * i > a;
}

int main() 
{
    ifstream in("input.txt");
    vector<int> a1;
    vector<int> a2;
    list<int> b1;
    list<int> b2;

    int num;
    // заносим элементы
    while (in >> num)
    {
        a1.push_back(num);
        a2.push_back(num);
        b1.push_back(num);
        b2.push_back(num);
    }

    // VECTOR
    // перекидываем простые числа в другой вектор 
    // и удаляем их из исходного

    cout << "Задайте i элемента:" << '\n';

    int elem_i;
    cin >> elem_i;
    if (elem_i < 0 || elem_i >= a1.size())
    {
        return false;
    }

    if (a1.size() != 0)
    {
        // Позиция элемента, который должен быть первым
        auto mid = a1.begin() + elem_i;

        auto first = a1.begin();
        auto nextElem = mid;

        // Пока не дошли до заданного места
        while (first != nextElem)
        {
            // Меняем элементы и сдвигаемся вправо
            swap(*first++, *nextElem++);

            // Если элементы кончились, то заканчиваем
            if (nextElem == a1.end())
            {
                nextElem = mid;
            } 
            // Если дошли до заданного места левым итератором
            else if (first == mid)
            {
                mid = nextElem;
            }
        }

        for (auto i : a1)
        {
            cout << i << ' ';
        }

        cout << '\n';
    }

    if (a2.size() != 0)
    {
        rotate(a2.begin(), a2.begin() + elem_i, a2.end());

        for (auto i : a2)
        {
            cout << i << ' ';
        }

        cout << '\n';
    }
    
    // LIST
    if (b1.size() != 0)
    {
        auto it = b1.begin();
        for (int i = 0; i < elem_i; i++)
        {
            it++;
        }
        // Позиция элемента, который должен быть первым
        auto mid = it;

        auto first = b1.begin();
        auto nextElem = mid;

        // Пока не дошли до заданного места
        while (first != nextElem)
        {
            // Меняем элементы и сдвигаемся вправо
            swap(*first++, *nextElem++);

            // Если элементы кончились, то заканчиваем
            if (nextElem == b1.end())
            {
                nextElem = mid;
            }
            // Если дошли до заданного места левым итератором
            else if (first == mid)
            {
                mid = nextElem;
            }
        }

        for (auto i : b1)
        {
            cout << i << ' ';
        }

        cout << '\n';
    }
    
    if (b2.size() != 0)
    {
        auto it = b2.begin();
        for (int i = 0; i < elem_i; i++)
        {
            it++;
        }
        // Позиция элемента, который должен быть первым
        auto mid = it;

        rotate(b2.begin(), it, b2.end());

        for (auto i : b2)
        {
            cout << i << ' ';
        }

        cout << '\n';
    }
    
    in.close();
    return 0;
}