#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int n;
	cin >> n;
	stack<int> stack1;

	int min = 0;
	stack1.push(0);
	for (int i = 1; i < n; i++)
	{
		if (i < min)
		{
			min = i;
		}
		stack1.push(i);
	}
	for (int i = -1; i > -n; i--)
	{
		if (i < min)
		{
			min = i;
		}
		stack1.push(i);
	}
	stack<int> stack2;
	while (!stack1.empty())
	{
		if (stack1.size() == 1)
		{
			stack2.push(min);
		}
		stack2.push(stack1.top());
		stack1.pop();
	}
	while (!stack2.empty())
	{
		stack1.push(stack2.top());
		stack2.pop();
	}
	while (!stack1.empty())
	{
		cout << stack1.top() << ' ';
		stack1.pop();
	}
}