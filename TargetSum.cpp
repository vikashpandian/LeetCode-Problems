#include <iostream>
#include <vector>
#include <unordered_map>
#include "utils.h"

using namespace std;

/*
int count(vector<int>& nums, int pos, int sum, int s, vector<unordered_map<int,int>>& memo) {
    if (pos < nums.size()) {
        auto it = memo[pos].find(sum);
        if (it != memo[pos].end()) return it->second;
        return memo[pos][sum] = count(nums, pos + 1, sum + nums[pos], s, memo) + count(nums, pos + 1, sum - nums[pos], s, memo);
    }
    return sum == s ? 1 : 0;
}

int findTargetSumWays(vector<int>& nums, int S) {
    vector<unordered_map<int, int>> memo(nums.size());
    return count(nums, 0, 0, S, memo);
}
*/

int subSum(vector<int>& nums, int s) {
    /*
    vector<int> dp(s + 1, 0);
    dp[0] = 1;
    for (int i : nums) {
        for (int j = s; j >= i; j--) dp[j] += dp[j - i];
    }
    return dp[s];
    */
    vector<vector<int>> dp(nums.size(), vector<int>(s + 1, 0));
    for (int i = 0; i < nums.size(); i++) dp[i][0] = 1;
    for (int i = 1; i < nums.size(); i++) {
        for (int j = s; j >= nums[i]; j--) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - nums[i]];
        }
        print2dMatrix(dp);
    }
    return dp[nums.size() - 1][s];
}

int findTargetSumWays(vector<int>& nums, int S) {
    int sum = 0;
    for (int i : nums) sum += i;
    return (sum < S || ((sum + S) & 1)) ? 0 : subSum(nums, (sum + S) >> 1);
}

int main()
{
    vector<int> nums{ 1,2,3,4 };
    //vector<int> nums2{ 2, 7, 11, 15 };

    cout << findTargetSumWays(nums, 4);

    return 0;
}