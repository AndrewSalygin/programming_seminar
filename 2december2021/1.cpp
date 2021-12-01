#include <iostream>

using namespace std;

double **create_array(int &n)
{
    double **arr = new double *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new double[4];
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Введите координаты первой точки " <<
        i << "-ого отрезка:" << endl;
        for (int j = 0; j < 2; j++)
        {
            cin >> arr[i][j];
        }

        cout << "Введите координаты второй точки " <<
        i << "-ого отрезка:" << endl;
        for (int j = 2; j < 4; j++)
        {
            cin >> arr[i][j];
        }
    }
    return arr;
}

void delete_array(double **arr, int &n)
{
    for (int i = 0; i < n; i++)
    {
        delete [] arr[i];
    }
    delete [] arr;
}

void change_names(string* s)
{
    for (int i = 0; i < 3; i++)
    {
        s[i][s[i].length() - 1] = 'х';
    }
    s[3] = "точек";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cin >> n;

    double **arr = create_array(n);

    double center_x;
    double center_y;

    int k_lines[4] = {0};
    string s[4] = {"вертикальный", "горизонтальный", "наклонный", "точка"};

    for (int i = 0; i < n; i++)
    {
        if ((arr[i][0] == arr[i][2]) &&
            (arr[i][1] != arr[i][3]))
        {
            cout << "Отрезок " << i + 1 << "-й: " << s[0] << endl;
            k_lines[0]++;
        }
        else if ((arr[i][0] != arr[i][2]) &&
                (arr[i][1] == arr[i][3]))
        {
            cout << "Отрезок " << i + 1 << "-й: " << s[1] << endl;
            k_lines[1]++;
        }
        else if ((arr[i][0] == arr[i][2]) &&
            (arr[i][1] == arr[i][3]))
        {
             cout << "Отрезок " << i + 1 << "-й: это " << s[3] << endl;
            k_lines[3]++;
        }
        else
        {
            center_x = arr[i][0] + (arr[i][2] - arr[i][0]) / 2;
            center_y = arr[i][1] + (arr[i][3] - arr[i][1]) / 2;

            cout << "Отрезок " << i + 1 << "-й: " << s[2] << endl;
            cout << "Середина отрезка: (" << center_x << ';' <<
            center_y << ')' << endl;
            k_lines[2]++;
        }
    }

    change_names(s);
    for (int i = 0; i < 4; i++)
    {
        cout << "Количество " << s[i] << ": " << k_lines[i] << endl;
    }

    delete_array(arr, n);
    return 0;
}


