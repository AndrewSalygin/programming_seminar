#include <iostream>

using namespace std;

template <typename T>
class SimpleVector
{
    int size = 0;
    int count_of_element = 0;
    T *arr;
public:
    void push_back(int elem);
    ~SimpleVector();

    T operator[](int index)
    {
        if (index >= size) {
            cout << "Error";
            exit(0);
        }
        return arr[index];
    }
};

template <typename T>
SimpleVector<T>::~SimpleVector()
{
    delete [] arr;
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
        new_arr = new T[2*size];
        size = 2*size;
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
}

int main()
{
    SimpleVector<int> a;
    for (int i = 0; i < 10; i++)
    {
        a.push_back(i);
    }
    for (int i = 0; i < 10; i++)
    {
        cout << a[i];
    }
    return 0;
}
