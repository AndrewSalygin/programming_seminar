#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <tuple>
#include <Windows.h>

double EPS = 10e-8;
using namespace std;

typedef tuple<string, string, string, int, vector<int>, double> tuple_student;
typedef vector<tuple_student> tuple_students;
typedef vector<tuple_student*> tuple_students_ptr;

bool comparing(tuple_student group1, tuple_student group2)
{
    if (get<5>(group1) != get<5>(group2))
    {
        return get<5>(group1) + EPS < get<5>(group2);
    }
    if (get<3>(group1) != get<3>(group2))
    {
        return get<3>(group1) < get<3>(group2);
    }
    if (get<0>(group1) != get<0>(group2))
    {
        return get<0>(group1) > get<0>(group2);
    }
    if (get<1>(group1) != get<1>(group2))
    {
        return get<1>(group1) > get<1>(group2);
    }
    if (get<2>(group1) != get<2>(group2))
    {
        return get<2>(group1) > get<2>(group2);
    }
}

void sort_insertion(tuple_students_ptr& group)
{
    tuple_student stud1;
    tuple_student stud2;

    for (int i = 1; i < group.size(); i++)
    {
        stud1 = *group[i];

        for (int j = i; j > 0; j--)
        {
            stud2 = *group[j - 1];
            // finding element placement
            if (comparing(stud1, stud2))
            {
                break;
            }

            swap(group[j - 1], group[j]);
        }

    }
}

int main()
{
    srand(time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string surnames[6] = { "Рыбаков", "Никифоров", "Иванова", "Сысоев", "Одинцова", "Ковалёва" };
    string names[6] = { "Максим", "Семен", "Виктория", "Лев", "Анжела", "Эдда" };
    string midnames[6] = { "Петрович", "Филатович", "Васильевна", "Альвианович",
                                "Игоревна", "Авксентьевна" };
    int years[6] = { 2001, 2002, 2002, 2001, 2001, 2001 };
    int mark;
    tuple_students students;
    tuple_students_ptr students_ptr;

    for (int i = 0; i < 6; i++)
    {
        vector<int> marks;
        double average_mark = 0;
        for (int i = 0; i < 5; i++)
        {
            mark = rand() % 4 + 2;
            marks.push_back(mark);
            average_mark += mark;
        }
        average_mark /= 5;
        tuple_student student = make_tuple(surnames[i], names[i], midnames[i], years[i], marks, average_mark);
        students.push_back(student);
    }
    for (int i = 0; i < 6; i++)
    {
        students_ptr.push_back(&students[i]);
    }

    sort_insertion(students_ptr);

    for (int i = 0; i < students_ptr.size(); i++)
    {
        tuple_student student = *students_ptr[i];
        cout << get<0>(*students_ptr[i]) << ' ' << get<1>(*students_ptr[i]) << ' ' <<
            get<2>(*students_ptr[i]) << ' ' << get<3>(*students_ptr[i]) << ' ' <<
            get<5>(*students_ptr[i]) << '\n';
    }

    return 0;
}
