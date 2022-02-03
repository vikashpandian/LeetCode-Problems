#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int connectSticks(vector<int>& sticks)
{
	int res = 0;
	priority_queue<int, vector<int>, greater<int>> q(sticks.begin(), sticks.end());
	while (q.size() > 1)
	{
		int sum = q.top();
		q.pop();
		res += sum += q.top();
		q.pop();
		q.push(sum);
	}
	return res;
}

int main(void)
{
	vector<int> sticks = { 1, 8, 3, 5 };
	cout << connectSticks(sticks);
	return 0;
}