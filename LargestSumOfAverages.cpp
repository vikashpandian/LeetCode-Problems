#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double partition(vector<int>& nums, int k, int pos, vector<vector<double>>& dp)
{
    if (dp[k][pos]) return dp[k][pos];
    int n = nums.size();
    double maxavg = -1, sum = 0;
    for (int i = pos; i < n - k; i++)
    {
        sum += nums[i];
        if (k > 0)
        {
            double val = partition(nums, k - 1, i + 1, dp);
            maxavg = max(maxavg, val + (sum / (i - pos + 1)));
        }
    }
    if (!k) maxavg = sum / (n - pos);
    dp[k][pos] = maxavg;
    return maxavg;
}

double largestSumOfAverages(vector<int>& nums, int k)
{
    int n = nums.size();
    vector<vector<double>> dp(k, vector<double>(n));
    return partition(nums, k - 1, 0, dp);
}

int main(void)
{
    vector<int> nums = { 9,1,2,3,9 };
    cout << largestSumOfAverages(nums, 3);
	return 0;
}