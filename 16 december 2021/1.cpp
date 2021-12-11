#include <iostream>

using namespace std;

int **create_array(int n, int m)
{
    int **arr = new int*[n];
    for (int i = 0; i < n; i++)
    {
        int *arr_m = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> arr_m[j];
        }
        arr[i] = arr_m;
    }
    return arr;
}

void delete_array(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete [] arr[i];
    }
    delete [] arr;
}

int main()
{
    cout << "Введите размерность (кол-во строк, столбцов):" << endl;
    int n, m;
    cin >> n >> m;
    cout << "Введите значения массива:" << endl;
    int **arr = create_array(n, m);

    cout << "Позиции чётных элементов:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] % 2 == 0)
            {
                cout << '[' << i << ']' << '[' << j << ']' << endl;
            }
        }
    }

    delete_array(arr, n);

    return 0;
}

