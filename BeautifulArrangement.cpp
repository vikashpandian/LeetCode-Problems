#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
//Brute-Force Method

int c = 0;

void permute(vector<int>& nums, int pos = 0)
{
	if (pos == nums.size())
	{
		c++;
		return;
	}
	for (int i = pos; i < nums.size(); i++)
	{
		swap(nums[i], nums[pos]);
		if (!((pos + 1) % nums[pos]) || !(nums[pos] % (pos + 1)))
		{
			permute(nums, pos + 1);
		}
		swap(nums[i], nums[pos]);
	}
}

int countArrangement(int n)
{
	//int* nums = new int[n]();
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		nums[i] = i + 1;
	}
	permute(nums);
	return c;
}
*/

int c = 0;
bool seen[16] = {};

void dfs(int n, int pos = 1)
{
	if (pos > n)
	{
		c++;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!seen[i] && (!(i % pos) || !(pos % i)))
		{
			seen[i] = true;
			dfs(n, pos + 1);
			seen[i] = false;
		}
	}
}

int countArrangement(int n)
{
	dfs(n);
	return c;
}

int main(void)
{
	cout << countArrangement(10);
	return 0;
}