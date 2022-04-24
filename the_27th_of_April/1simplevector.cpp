#include <iostream>
#include <Windows.h>

using namespace std;

template <typename T>
class SimpleVector
{
    int size = 0;
    int count_of_element = 0;
    T* arr;
public:
    void push_back(int elem);
    int find(int num);
    void remove(int num);
    bool insert_before_pos(int num, int pos);
    bool insert_after_pos(int num, int pos);
    bool insert_after(int num, int list_num);
    int get_size();

    ~SimpleVector();

    T& operator[](int index)
    {
        if (index >= count_of_element) {
            cout << "Error";
            exit(0);
        }
        return arr[index];
    }
};

template <typename T>
SimpleVector<T>::~SimpleVector()
{
    delete[] arr;
}


template <typename T>
int SimpleVector<T>::get_size()
{
    return count_of_element;
}

template <typename T>
int SimpleVector<T>::find(int num)
{
    for (int i = 0; i < count_of_element; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return -1;
}

template <typename T>
void SimpleVector<T>::remove(int num)
{
    int position = find(num);
    if (position != -1)
    {
        for (int i = position; i < count_of_element - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        return;
    }
    cout << "\nЭлемент не найден\n";
}

template <typename T>
bool SimpleVector<T>::insert_after_pos(int num, int pos)
{
    if (pos == count_of_element)
    {
        push_back(num);
    }
    else if (pos < count_of_element && pos >= 0)
    {
        T* new_arr;
        if (count_of_element + 1 == size)
        {
            new_arr = new T[2 * size];
            size = 2 * size;
        }
        else
        {
            new_arr = new T[size];
        }

        for (int i = 0; i <= pos; i++)
        {
            new_arr[i] = arr[i];
        }

        new_arr[pos + 1] = num;
        count_of_element++;

        for (int i = pos + 2; i < count_of_element; i++)
        {
            new_arr[i] = arr[i - 1];
        }

        arr = new_arr;

        new_arr = nullptr;
    }
    else
    {
        return false;
    }
    return true;
}

template <typename T>
bool SimpleVector<T>::insert_before_pos(int num, int pos)
{
    if (pos != 0)
    {
        insert_after_pos(num, pos - 1);
    }
    else if (pos < count_of_element && pos == 0)
    {
        T* new_arr;
        if (count_of_element + 1 == size)
        {
            new_arr = new T[2 * size];
            size = 2 * size;
        }
        else
        {
            new_arr = new T[size];
        }

        new_arr[0] = num;
        count_of_element++;
        for (int i = 1; i < count_of_element; i++)
        {
            new_arr[i] = arr[i - 1];
        }
        arr = new_arr;

        new_arr = nullptr;
    }
    else
    {
        return false;
    }
    return true;
}

template <typename T>
bool SimpleVector<T>::insert_after(int num, int list_num)
{
    int pos = find(list_num);
    if (pos != -1)
    {
        insert_after_pos(num, pos);
        return true;
    }
    return false;
}

template <typename T>
void SimpleVector<T>::push_back(int num)
{
    T* new_arr;
    if (size == count_of_element && size == 0)
    {
        arr = new T[2];

        arr[0] = num;

        count_of_element++;
        size = 2;
        return;
    }
    else if (size == count_of_element + 1)
    {
        new_arr = new T[2 * size];
        size = 2 * size;
    }
    else
    {
        arr[count_of_element] = num;
        count_of_element++;
        return;
    }
    for (int i = 0; i < count_of_element; i++)
    {
        new_arr[i] = arr[i];
    }

    new_arr[count_of_element] = num;

    count_of_element++;
    arr = new_arr;

    new_arr = nullptr;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    SimpleVector<int> a;
    for (int i = 10; i < 11; i++)
    {
        a.push_back(i);
    }
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    for (int i = 4; i < 13; i++)
    {
        a.push_back(-i);
    }
    for (int i = 0; i < a.get_size(); i++)
    {
        cout << a[i] << ' ';
    }

    cout << '\n';

    int min = a[0];
    int minIndex = 0;
    for (int i = 1; i < a.get_size(); i++)
    {
        if (a[i] < min)
        {
            min = a[i];
            minIndex = i;
        }
    }

    // Для SimpleVector обе задачи (а) и (б) за O(n), так как
    // в (а) поиск минимального можно выполнить за O(n), вставку за O(n) 
    // (ну или O(1), если в конец (при условии, что память есть)) |=> O(n)
    // в (б) поиск отрицательного максимального за O(n),
    // замена за O(1) |=> O(n)
    a.insert_after_pos(0, minIndex);
    a.insert_before_pos(0, minIndex);
    
    if (a.get_size() % 2 != 0)
    {
        int maxNeg = a[0];
        bool flag = false;
        for (int i = 0; i < a.get_size(); i++)
        {
            if (a[i] < 0 && !flag)
            {
                maxNeg = a[i];
                flag = true;
            }
            if (a[i] < 0 && a[i] > maxNeg)
            {
                maxNeg = a[i];
            }
        }
        if (flag)
        {
            a[a.get_size() / 2] = maxNeg;
        }
        else
        {
            cout << '\n' << "ERROR" << '\n';
        }
    }
    else
    {
        cout << '\n' << "ERROR" << '\n';
    }

    for (int i = 0; i < a.get_size(); i++)
    {
        cout << a[i] << ' ';
    }
    return 0;
}