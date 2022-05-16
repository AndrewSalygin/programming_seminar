#include <iostream>
#include <set>
#include <unordered_set>
#include <fstream>
#include <algorithm>
#include <string>
#include <Windows.h>

using namespace std;

void fillAlphabet(set<char> &alphabet)
{
    for (char i = 'a'; i <= 'z'; i++)
    {
        alphabet.insert(i);
    }
}

bool isUpper(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] < 'A' || s[i] > 'Z')
        {
            return false;
        }
    }
    return true;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    set<char> alphabet;

    fillAlphabet(alphabet);

    ifstream in("input.txt");
    ofstream out("output.txt");

    set<string> words;
    unordered_set<string> wordsUn;

    string s;
    while (in >> s)
    {
        words.insert(s);
        wordsUn.insert(s);
    }

    set<string> resultWords;
    copy_if(begin(words), end(words), inserter(resultWords, begin(resultWords)), isUpper);

    set<char> resultsLetters;
    for (string i : resultWords)
    {
        for (int j = 0; j < i.size(); j++)
        {
            resultsLetters.insert(i[j]);
        }
    }

    for (char i : resultsLetters)
    {
        out << i << ' ';
    }

    out << '\n';

    set<string> resultWordsUn;
    copy_if(begin(wordsUn), end(wordsUn), inserter(resultWordsUn, begin(resultWordsUn)), isUpper);

    set<char> resultsLettersUn;
    for (string i : resultWordsUn)
    {
        for (int j = 0; j < i.size(); j++)
        {
            resultsLettersUn.insert(i[j]);
        }
    }

    for (char i : resultsLettersUn)
    {
        out << i << ' ';
    }

    in.close();
    out.close();

    return 0;
}

