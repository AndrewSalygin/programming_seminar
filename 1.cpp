#include <iostream>

using namespace std;

template <typename T>
class SimpleVector
{
    int size = 0;
    T *arr;
public:
    void push_back(int elem);

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
void SimpleVector<T>::push_back(int num)
{
    T *new_arr = new T[size + 1];
    for (int i = 0; i < size; i++)
    {
        new_arr[i] = arr[i];
    }
    new_arr[size] = num;
    this->size++;
    arr = new_arr;
}

int main()
{
    SimpleVector<int> a;

    return 0;
}
