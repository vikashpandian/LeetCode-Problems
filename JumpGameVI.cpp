#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

/*
// Greedy Approach I tried (Not Correct)
int maxResult(vector<int>& nums, int k)
{
	int n = nums.size();
	long sum = nums[0];
	for (int i = 1, j; i < n; i = j)
	{
		int max_no = INT_MIN, max_pos = 0;
		for (j = i; j < min(i + k, n); j++)
		{
			if (nums[j] > 0)
			{
				sum += nums[j++];
				break;
			}
			if (nums[j] >= max_no)
			{
				max_no = nums[j];
				max_pos = j;
			}
			if (j == i + k - 1 || j == n)
			{
				sum += max_no;
				j = max_pos + 1;
				break;
			}
		}
	}
	return sum;
}
*/

/*
// Bottom-Up Brute force DP
int maxResult(vector<int>& nums, int k)
{
	int n = nums.size();
	vector<int> dp(n, INT_MIN);
	dp[0] = nums[0];
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= k && i >= j; j++)
		{
			dp[i] = max(dp[i], dp[i - j] + nums[i]);
		}
	}
	return dp.back();
}
*/

int maxResult(vector<int>& nums, int k)
{
	int n = nums.size();
	vector<int> dp(n);
	deque<int> q{ 0 };
	dp[0] = nums[0];
	for (int i = 1; i < n; i++)
	{
		if (i - k > q.front())
		{
			q.pop_front();
		}
		dp[i] = dp[q.front()] + nums[i];
		while (!q.empty() && dp[q.back()] <= dp[i])
		{
			q.pop_back();
		}
		q.push_back(i);
	}
	return dp.back();
}

int main(void)
{
	vector<int> nums = { 1,-5,-20,4,-1,3,-6,-3 };
	int k = 2;
	cout << maxResult(nums, k);
	return 0;
}