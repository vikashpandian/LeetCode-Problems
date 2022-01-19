#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int totalFruit(vector<int>& fruits)
{
	int n = fruits.size();
	if (n < 3)
	{
		return n;
	}

	pair<int, int> one = { fruits[0], 0 }, two = {-1, -1};
	int start = 0, maxSize = 1;

	for (int i = 1; i < n; i++)
	{
		if (fruits[i] == one.first)
		{
			one.second = i;
		}
		else if (fruits[i] == two.first)
		{
			two.second = i;
		}
		else
		{
			auto& temp = one.second < two.second ? one : two;
			temp.first = fruits[i];
			start = temp.second + 1;
			temp.second = i;
		}
		maxSize = max(maxSize, i - start + 1);
	}
	return maxSize;
}

int main(void)
{
	vector<int> fruits = { 3,3,3,1,2,1,1,2,3,3,4 };
	cout << totalFruit(fruits);
	return 0;
}
