#include <iostream>

using namespace std;

int main()
{
    int min1, min2, buf, n;
    min1 = min2 = -1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> buf;
        if (buf <= 0) {
            continue;
        }
        switch (i) {
        case 0:
            min1 = buf;
            break;
        case 1:
            if (min1 < buf) {
                min2 = buf;
            }
            else {
                min2 = min1;
                min1 = buf;
            }
            break;
        default:
            if (buf < min2) {
                if (buf < min1) {
                    min2 = min1;
                    min1 = buf;
                }
                else {
                    min2 = buf;
                }
            }
        }
    }
    if (min1 == -1) {
        cout << "Недостаточно данных";
    }
    else if (min2 == -1) {
        cout << min1 << endl;
        cout << "Второго нет";
    }
    else {
        cout << min1 << " " << min2;
    }
}

