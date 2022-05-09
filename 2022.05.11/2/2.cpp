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
    if (a1.size() != 0)
    {
        vector<int> a1_copy;
        auto iter = a1.begin();
        while (iter != a1.end())
        {
            if (isPrime(*iter))
            {
                a1_copy.push_back(*iter);
                iter = a1.erase(iter);
            }
            else
            {
                iter++;
            }
        }

        // добавляем их в начало, причем с конца копии vector
        // так как первое простое находится в конце копии vector
        for (int i = a1_copy.size() - 1; i >= 0; i--)
        {
            a1.emplace(a1.begin(), a1_copy[i]);
        }

        for (int i : a1)
        {
            cout << i << ' ';
        }
        cout << '\n';
    }

    if (a2.size() != 0)
    {
        // копия вектора (заполняем нулями)
        vector<int> a2_copy(a2.size(), 0);

        // копируем элементы в копию вектора
        // находим итератор последнего незаполненного элемента в копии вектора
        auto it = copy_if(a2.begin(), a2.end(), a2_copy.begin(), isPrime);

        // копируем не простые числа в копию вектора
        copy_if(a2.begin(), a2.end(), it, [a2_copy](int a) 
        {
            return find(a2_copy.begin(), a2_copy.end(), a) == a2_copy.end();
        });

        // выводим результат
        for (int i : a2_copy)
        {
            cout << i << ' ';
        }

        cout << '\n';
    }
    
    // LIST
    if (b1.size() != 0)
    {
        auto it_begin = b1.begin();
        for (auto it = b1.begin(); it != b1.end();)
        {
            if (isPrime(*it))
            {
                b1.insert(it_begin, *it);
                it = b1.erase(it);
            }
            else
            {
                it++;
            }
        }
        
        // выводим результат
        for (int i : b1)
        {
            cout << i << ' ';
        }

        cout << '\n';
    }

    if (b2.size() != 0)
    {
        // копия листа (заполняем нулями)
        list<int> b2_copy(b2.size(), 0);

        // копируем элементы в копию листа
        // находим итератор последнего незаполненного элемента в копии листа
        auto it = copy_if(b2.begin(), b2.end(), b2_copy.begin(), isPrime);

        // копируем не простые числа в копию листа
        copy_if(b2.begin(), b2.end(), it, [b2_copy](int b)
            {
                return find(b2_copy.begin(), b2_copy.end(), b) == b2_copy.end();
            });

        // выводим результат
        for (int i : b2_copy)
        {
            cout << i << ' ';
        }

        cout << '\n';
    }

    in.close();
    return 0;
}