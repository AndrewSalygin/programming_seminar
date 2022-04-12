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
    for (int i = 10; i < 20; i++)
    {
        a.push_back(i);
    }
    for (int i = 0; i < a.get_size(); i++)
    {
        cout << a[i] << ' ';
    }

    cout << '\n';
    a.insert_after(0, 15);

    for (int i = 0; i < a.get_size(); i++)
    {
        cout << a[i] << ' ';
    }
    return 0;
}
