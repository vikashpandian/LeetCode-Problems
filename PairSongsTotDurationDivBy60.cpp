#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
//Map Solution
int numPairsDivisibleBy60(vector<int>& time)
{
	unordered_map<int, int> values;
	int res = 0;
	for (int i : time)
	{
		int cur = i % 60;
		int prev = cur ? 60 - cur : cur;
		if (values.count(prev))
		{
			res += values[prev];
		}
		values[cur]++;
	}
	return res;
}
*/

//Array Solution
int numPairsDivisibleBy60(vector<int>& time)
{
	int values[60] = {};
	int res = 0;
	for (int i : time)
	{
		int cur = i % 60;
		int prev = cur ? 60 - cur : cur;
		res += values[prev];
		values[cur]++;
	}
	return res;
}

int main(void)
{

	return 0;
}