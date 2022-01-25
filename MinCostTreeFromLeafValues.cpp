#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Find the smallest guy till the particular point, where a larger number enters the stack
int mctFromLeafValues(vector<int>& arr)
{
	vector<int> nums({ INT_MAX });
	int res = 0;
	for (int i : arr)
	{
		while (nums.back() <= i)
		{
			int val = nums.back();
			nums.pop_back();
			res += val * min(nums.back(), i);
		}
		nums.push_back(i);
	}
	for (int i = 2; i < nums.size(); i++)
	{
		res += nums[i] * nums[i - 1];
	}
    return res;
}

int main(void)
{

	return 0;
}