#include <iostream>

using namespace std;

const string TWO = "Две";
const string THREE = "Три";
const string FOUR = "Четыре";

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Выберите числитель или знаменатель (1 или 2): ";
    int choice;
    do
    {
        cin >> choice;
    } while (choice != 1 && choice != 2);

    cout << "Выберите день недели (1..7): ";
    int num = 0;
    do
    {
        cin >> num;
    } while (num < 1 || num > 7);

    string a;
    switch (num)
    {
        case 1: a = TWO; break;
        case 2: a = THREE; break;
        case 3: a = FOUR; break;
        case 4: a = (choice == 1) ? TWO : THREE; break;
        case 5: a = (choice == 1) ? THREE : TWO; break;
        default: a = "Выходной";
    }
    cout << a << endl;
    return 0;
}