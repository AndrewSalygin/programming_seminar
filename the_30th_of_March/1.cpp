#include <iostream>

using namespace std;

int min_index_element(int *a, int n)
{
    int min_index = 0;
    int min_value = a[min_index];

    for (int i = 1; i < n; i++)
    {
        if (a[i] < min_value) 
        {
            min_value = a[i];
            min_index = i;
        }
    }
    
    return min_index;
}

void erase(int *a, int &n, int current_index)
{
    for (int i = current_index; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }

    n--;
}

int main()
{
    int n;
    cin >> n;
    
    int n_changing = n;

    int *a = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int min_index;
    for(int i = 0; i < n; i++)
    {
        min_index = min_index_element(a, n_changing);
        cout << a[min_index] << ' ';
        erase(a, n_changing, min_index);
    }

    return 0;
}