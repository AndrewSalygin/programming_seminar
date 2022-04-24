#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n;
	cin >> n;
	queue<int> queue1;

	int min = 0;
	queue1.push(0);
	for (int i = 1; i < n; i++)
	{
		if (i < min)
		{
			min = i;
		}
		queue1.push(i);
	}
	for (int i = -1; i > -n; i--)
	{
		if (i < min)
		{
			min = i;
		}
		queue1.push(i);
	}
	queue<int> queue2;
	int k = 0;
	while (!queue1.empty())
	{
		if (k == 1)
		{
			queue2.push(min);
		}
		queue2.push(queue1.front());
		queue1.pop();
		k++;
	}
	while (!queue2.empty())
	{
		queue1.push(queue2.front());
		queue2.pop();
	}
	while (!queue1.empty())
	{
		cout << queue1.front() << ' ';
		queue1.pop();
	}
}