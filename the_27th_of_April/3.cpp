#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	int n;
	cin >> n;
	stack<int> stack1;
	queue<int> queue1;

	for (int i = 0; i < n; i++)
	{
		if (i % 2 != 0)
		{
			stack1.push(i);
		}
		else
		{
			queue1.push(i);
		}
	}
	while (!queue1.empty())
	{
		cout << queue1.front() << ' ';
		queue1.pop();
	}
	while (!stack1.empty())
	{
		cout << stack1.top() << ' ';
		stack1.pop();
	}
}