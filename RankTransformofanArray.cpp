#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> arrayRankTransform(vector<int>& arr)
{
	vector<int> s_arr = arr;
	sort(s_arr.begin(), s_arr.end());
	unordered_map<int, int> ranks;
	for (int i : s_arr)
	{
		ranks.emplace(i, ranks.size() + 1);
	}
	for (int i = 0; i < arr.size(); i++)
	{
		s_arr[i] = ranks[arr[i]];
	}
	return s_arr;
}

int main(void)
{

	return 0;
}