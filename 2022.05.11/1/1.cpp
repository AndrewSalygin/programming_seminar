#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int printer(int i) {
    cout << i << ", ";
    return i * 10;
}
int main() {
    int a[] = { 1, 2, 3, 4 };
    vector<int> v(a, a + 4);

    /*
    for_each является не модифицирующим алгоритмом; 
    transform – модифицирующий алгоритм. 
    При этом в for_each можно использовать ссылки для модификации 
    элементов, но это не соответствует принципам STL.

    for_each игнорирует возвращаемое значение операции; 
    transform присваивает возвращаемое значение последовательным 
    элементам в выходном диапазоне.
    
    */

    // Не модифицирует
    for_each(v.begin(), v.end(), [](int a) { return -a; });
    for_each(v.begin(), v.end(), printer);     

    cout << '\n';

    // Модифицирует
    transform(v.begin(), v.end(), v.begin(), [](int a) { return -a; });
    // Меняет значение при выводе (так как есть return в функции printer)
    transform(v.begin(), v.end(), v.begin(),  printer);  

    cout << '\n';

    // Выводим измененные значения
    for_each(v.begin(), v.end(), printer);
    return 0;
}