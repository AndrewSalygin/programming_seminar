#include <iostream>

using namespace std;

void g(int n, int spaces)
{
    // Кол-во рядов елки
    int i = 0;

    // Целевое кол-во звезд в ряду
    int i_point = 1;

    while (i <= n)
    {
        // Выводим пробелы перед звездочками
        for (int sp = spaces; sp > 0; sp--)
        {
            cout << ' ';
        }

        // Выводим звездочки
        for (int i_work = 0; i_work < i_point; i_work++)
        {
            cout << '*';
        }
        cout << '\n';

        // Увеличиваем кол-во звезд
        i_point += 2;

        // Уменьшаем локальное кол-во пробелов
        spaces--;

        // Переходим на другой ряд
        i++;
    }
}

void f(int n)
{
    // Кол-во отступов для нового треугольника
    // Не изменяется при последующих вызовах
    // функции f(n - 1)
    static int spaces = n;

    if (n > 0)
    {
        // Заходим вглубь
        f(n - 1);

        // Начинаем выводить
        g(n, spaces);
    }
}

int main()
{
    f(5);
    return 0;
}

