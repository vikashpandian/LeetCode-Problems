#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
{
    int n = nums1.size(), res = 0;
    unordered_map<int, int> dp;
    for (int i : nums1)
    {
        for (int j : nums2)
        {
            dp[i + j]++;
        }
    }
    for (int i : nums3)
    {
        for (int j : nums4)
        {
            int val = -i - j;
            if (dp.count(val))
            {
                res += dp[val];
            }
        }
    }
    return res;
}

int main(void)
{

	return 0;
}