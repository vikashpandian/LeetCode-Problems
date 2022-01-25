#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int findShortestSubArray(vector<int>& nums)
{
	unordered_map<int, vector<int>> counts;
	int degree = 1;
	int res = 1;
	for (int i = 0; i < nums.size(); i++)
	{
		if (counts.count(nums[i]))
		{
			counts[nums[i]][0]++;
		}
		else
		{
			counts[nums[i]] = { 1, i };
		}
		if (counts[nums[i]][0] == degree)
		{
			res = min(res, i - counts[nums[i]][1] + 1);
		}
		else if (counts[nums[i]][0] > degree)
		{
			degree = counts[nums[i]][0];
			res = i - counts[nums[i]][1] + 1;
		}
	}
	return res;
}

int main(void)
{
	vector<int> nums = { 5,1,2,2,3,1,4,2 };
	cout << findShortestSubArray(nums);
	return 0;
}