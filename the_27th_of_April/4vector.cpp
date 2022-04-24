#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> vector1;

	int min = 0;
	vector1.push_back(0);
	for (int i = 1; i < n; i++)
	{
		if (i < min)
		{
			min = i;
		}
		vector1.push_back(i);
	}
	for (int i = -1; i > -n; i--)
	{
		if (i < min)
		{
			min = i;
		}
		vector1.push_back(i);
	}

	vector1.insert(next(vector1.begin(), 1), min);
	for (int i = 0; i < vector1.size(); i++)
	{
		cout << vector1[i] << ' ';
	}
}