#include <iostream>

using namespace std;

template <typename T>
class List
{
    static int count;
    struct Node
    {
        T inf;
        Node* next;
        Node(T x, Node* ref = nullptr) : inf(x), next(ref) {}
    }
    *first = nullptr, * last = nullptr;
public:
    void add(T x)
    {
        Node* item = new Node(x);
        if (last != nullptr)
            last->next = item;
        last = item;
        if (first == nullptr)
            first = last;
        count++;
    }
    List<T> create_new_list_front_elements(int num)
    {
        List new_list;
        if (num <= count)
        {
            Node* tmp = first;
            for (int i = 0; i < num; i++)
            {
                tmp = tmp->next;
            }
            for (Node* tmp2 = tmp; tmp2 != nullptr; tmp2 = tmp2->next)
            {
                new_list.add(tmp2->inf);
            }
        }
        
        return new_list;
    }

    void print()
    {
        for (Node* tmp = first; tmp != nullptr; tmp = tmp->next)
        {
            cout << tmp->inf << " ";
        }
        cout << '\n';
    }

    void doubleX(T x)
    {
        for (Node* tmp = first; tmp != nullptr; tmp = tmp->next)
        {
            if (tmp->inf == x)
            {
                Node* newItem = new Node(x, tmp->next);
                tmp->next = newItem;
                if (tmp == last)
                    last = tmp->next;
                tmp = tmp->next;
            }
        }

    }
};

template <typename T>
int List<T>::count = 0;

int main() {
    List<int> lst;
    lst.add(4);
    lst.add(5);
    lst.add(1);
    lst.print();
    lst.doubleX(1);
    lst.print();
    lst.add(10);
    lst.print();

    List<int> new_list = lst.create_new_list_front_elements(1);

    new_list.print();
    return 0;
}