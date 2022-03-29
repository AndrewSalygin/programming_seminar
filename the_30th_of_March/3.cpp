#include <iostream>

using namespace std;

int compare_string_length(string a, string b) {
    if (a.length() < b.length())
    {
        return 1;
    }
    else if (a.length() > b.length())
    {
        return -1;
    }
    else
    {
        return 0;
    }
}

void sort(string *a, int n)
{
    string temp;
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++)
        {
            if (compare_string_length(a[i], a[j]) == 1)
            {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
            else if (compare_string_length(a[i], a[j]) == 0)
            {
                if (a[i] < a[j])
                {
                    temp = a[j];
                    a[j] = a[i];
                    a[i] = temp;
                }
            }
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