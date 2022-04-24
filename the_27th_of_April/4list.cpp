#include <iostream>
#include <list>

using namespace std;

int main()
{
	int n;
	cin >> n;
	list<int> list1;

	int min = 0;
	list1.push_back(0);
	for (int i = 1; i < n; i++)
	{
		if (i < min)
		{
			min = i;
		}
		list1.push_back(i);
	}
	for (int i = -1; i > -n; i--)
	{
		if (i < min)
		{
			min = i;
		}
		list1.push_back(i);
	}

	list<int>::iterator it = list1.begin();
	it++;
	list1.insert(it, min);

	for (list<int>::iterator i = list1.begin(); i!= list1.end(); i++)
	{
		cout << *i << ' ';
	}
}