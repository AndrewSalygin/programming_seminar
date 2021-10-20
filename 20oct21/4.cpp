#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n < 0)
    {
        cout << "Нет таких значений";
        return 0;
    }

    int pred_min = -1;
    int i = 0;

    while (i < n && pred_min <= 0)
    {
        cin >> pred_min;
        ++i;
    }

    if (i == n)
    {
        // Не нашли положительного значения
        if (pred_min <= 0)
        {
            cout << "Нет таких значений";
        }
        // Только один элемент
        else
        {
            cout << "Минимальное значение: " << pred_min << '\n';
            cout << "Второго по минимальности значения нет" << '\n';
        }
        return 0;
    }

    int min = -1;
    while (i < n && min <= 0)
    {
        cin >> min;
        // Значения pred_min и min должны быть различны
        if (pred_min == min)
        {
            min = -1;
        }
        ++i;
    }

    int mem;

    // Определяем какое из введённых значений - минимально
    if (pred_min < min && min > 0)
    {
        mem = min;
        min = pred_min;
        pred_min = mem;
    }

    if (i == n)
    {
        // Если только один элемент
        if (min <= 0)
        {
            cout << "Минимальное значение: " << pred_min << '\n';
            cout << "Второго по минимальности значения нет" << '\n';
        }
        // Нашлось два различных элемента
        else
        {
            cout << "Минимальное значение: " << min << '\n';
            cout << "Второе по минимальности значение: " << pred_min << '\n';
        }
        return 0;
    }

    int num;
    for (i; i < n; ++i)
    {
        cin >> num;
        if (num > 0)
        {
            if (num < pred_min)
            {
                if (num < min)
                {
                    pred_min = min;
                    min = num;
                }
                else
                {
                    pred_min = num;
                }
            }
        }
    }
    cout << "Минимальное значение: " << min << '\n';
    cout << "Второе по минимальности значение: " << pred_min << '\n';
    return 0;
}

