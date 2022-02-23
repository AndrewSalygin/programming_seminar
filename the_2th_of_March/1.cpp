#include <iostream>
#include <vector>

using namespace std;

string generate_s(const int &n, string s = "")
{
    for (int i = 0; i < n; i++)
    {
        // добавляем единички или нулики
        s += to_string(((n % 2) + 1) % 2);
    }
    return s;
}

vector<string> rec(int n)
{
    // Создаём массив (тот самый 0)
    if (n == 0)
    {
        vector<string> vec;
        return vec;
    }

    // Блок вывода значений
    if (n > 0)
    {
        // идём заполнять массив (мы ограничены кол-вом
        // переменных, поэтому делаем так, чтобы при выполнении
        // рекурсии он игнорировал блок вывода значений
        vector<string> vec = rec(-n);

        // выводим массив
        for (int i = 0; i < n; i++)
        {
            cout << vec[i];
            cout << '\n';
        }

        // выводим с последнего нужного элемента
        for (int i = n - 2; i >= 0; i--)
        {
            cout << vec[i];
            cout << '\n';
        }
        return vec;
    }
    else
    {
        // Создаём массив (доходим до 0)
        vector<string> vec = rec(n + 1);

        // меняем знак на нормальный
        n = -n;

        // закидываем элементы в массив
        vec.push_back(generate_s(n));
        return vec;
    }
}

int main()
{
    rec(10);
    return 0;
}


