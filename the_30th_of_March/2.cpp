#include <iostream>

using namespace std;

void sort(string *a, int n)
{
    string temp;
    int temp_max_index;
    bool flag;
    for (int i = 0; i < n - 1; i++) 
    {
        flag = false;
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                temp_max_index = j;
                flag = true;
            }
        }
        if (flag)
        {
            temp = a[temp_max_index];
            a[temp_max_index] = a[i];
            a[i] = temp;
        }
    }
}

int main() {
    int n;
    cin >> n;

    string *a = new string[n];

    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }

    sort(a, n);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << ' ';
    }

    return 0;
}