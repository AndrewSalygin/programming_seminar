#include <iostream>
#include <vector>

using namespace std;

// Достаточно лишь конструктора по умолчанию
class MyClass {};

int main()
{
    vector<MyClass> a;

    MyClass b;

    a.push_back(b);
    
    return 0;
}

