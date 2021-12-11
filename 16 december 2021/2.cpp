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

    int max_negative, max_negative_i, max_negative_j, sum;
    for (int j = 0; j < m; j++)
    {
        cout << "Сумма всех отрицательных в " << j << " столбце: ";
        max_negative = 0;
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i][j] < 0)
            {
                sum += arr[i][j];
                if (arr[i][j] < max_negative)
                {
                    max_negative = arr[i][j];
                    max_negative_i = i;
                    max_negative_j = j;
                }
            }
        }
        cout << sum << endl;
        if (max_negative == 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << "Позиция максимального отрицательного элемента: " <<
            '[' << max_negative_i << ']' << '[' << max_negative_j << ']' << endl;
        }
    }

    delete_array(arr, n);

    return 0;
}

