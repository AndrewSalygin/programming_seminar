#include <iostream>

using namespace std;

template <typename T>
T *create_array(int n)
{
    T *arr = new T[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    return arr;
}

int main()
{
    cout << "Введите размер массива (n):" << endl;
    int n;
    cin >> n;

    cout << "Введите элементы массива:" << endl;
    string *arr_str = create_array<string>(n);

    delete [] arr_str;
    return 0;
}


