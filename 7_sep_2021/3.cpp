#include <iostream>

using namespace std;

int main()
{
    cout << "Enter a value: ";
    int a;
    cin >> a;
    (a == 0) ? cout << "Zero" : (a > 0) ? cout << "Positive\n" : cout << "Negative\n";

    return 0;
}