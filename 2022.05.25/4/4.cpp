#include <iostream>
#include <set>
#include <fstream>
#include <algorithm>
#include <string>
#include <Windows.h>

using namespace std;
/*
Дано целое число. Найти 
а) все его цифры, 
б) все его чётные цифры, 
в) все его нечётные цифры, 
г) все цифры, которых в нём нет, 
д) все нечётные цифры, которых в нём нет. 
То же самое проделать со словом, записанным латинскими буквами, 
и его гласными и согласными буквами (условно считаем гласными 'aeiou').
*/

bool isEven(int num)
{
    return num % 2 == 0;
}

bool isOdd(int num)
{
    return num % 2 == 1;
}

void fillConsonants(set<char> &consonants)
{
    for (char i = 'a'; i <= 'z'; i++)
    {
        switch (i)
        {
        case 'a': case 'e': case 'i':
        case 'o': case 'u': break;
        default: consonants.insert(i);
        };
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    int num;
    cin >> num;

    set<int> digits;
    if (num == 0)
    {
        digits.insert(0);
    }
    else
    {
        while (num > 0)
        {
            digits.insert(num % 10);
            num /= 10;
        }
    }

    string word;
    cin >> word;
    set<char> letters;
    for (int i = 0; i < word.size(); i++)
    {
        letters.insert(word[i]);
    }

    set<char> vowels = { 'a', 'e', 'i', 'o', 'u' };
    set<char> consonants;

    fillConsonants(consonants);

    set<char> alphabet;

    merge(begin(vowels), end(vowels), begin(consonants), end(consonants), inserter(alphabet, begin(alphabet)));

    // NUMBERS
    // задача A
    for (int i : digits)
    {
        cout << i << ' ';
    }
    cout << '\n';

    // задача Б
    set<int> resultB;
    copy_if(begin(digits), end(digits), inserter(resultB, resultB.begin()), isEven);
    for (int i : resultB)
    {
        cout << i << ' ';
    }
    cout << '\n';

    // задача В
    set<int> resultC;
    copy_if(begin(digits), end(digits), inserter(resultC, resultC.begin()), isOdd);
    for (int i : resultC)
    {
        cout << i << ' ';
    }
    cout << '\n';

    // задача Г
    set<int> allDigits;
    for (int i = 0; i < 10; i++)
    {
        allDigits.insert(i);
    }

    set<int> resultD;
    set_difference(begin(allDigits), end(allDigits), begin(digits), end(digits), inserter(resultD, resultD.begin()));
    for (int i : resultD)
    {
        cout << i << ' ';
    }
    cout << '\n';

    // задача Д
    set<int> resultE;
    set_difference(begin(allDigits), end(allDigits), begin(digits), end(digits), inserter(resultE, resultE.begin()));

    for (auto it = resultE.begin(); it != resultE.end(); ) {
        if (*it % 2 == 0) 
        {
            resultE.erase(it++);
        }
        else 
        {
            ++it;
        }
    }
    for (int i : resultE)
    {
        cout << i << ' ';
    }
    cout << '\n';

    // WORDS
    // задача A
    for (char i : letters)
    {
        cout << i << ' ';
    }
    cout << '\n';

    // задача Б
    set<char> resultWordsB;
    set_intersection(begin(letters), end(letters), begin(vowels), end(vowels), inserter(resultWordsB, resultWordsB.begin()));
    for (char i : resultWordsB)
    {
        cout << i << ' ';
    }
    cout << '\n';

    // задача В
    set<char> resultWordsC;
    set_intersection(begin(letters), end(letters), begin(consonants), end(consonants), inserter(resultWordsC, resultWordsC.begin()));
    for (char i : resultWordsC)
    {
        cout << i << ' ';
    }
    cout << '\n';

    // задача Г
    set<char> resultWordsD;
    set_difference(begin(alphabet), end(alphabet), begin(letters), end(letters), inserter(resultWordsD, resultWordsD.begin()));
    for (char i : resultWordsD)
    {
        cout << i << ' ';
    }
    cout << '\n';

    // задача Д
    set<char> resultWordsE;
    set_difference(begin(consonants), end(consonants), begin(letters), end(letters), inserter(resultWordsE, resultWordsE.begin()));
    for (char i : resultWordsE)
    {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}

