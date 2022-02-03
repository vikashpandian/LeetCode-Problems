#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rob(vector<int>& nums)
{
    int dp[405] = {}, n = nums.size();
    for (int i = n - 1; i >= 0; i--)
    {
        dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
    }
    return dp[0];
}

int main(void)
{

	return 0;
}