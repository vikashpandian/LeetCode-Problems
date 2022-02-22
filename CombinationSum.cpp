#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
void getSum(vector<int>& nums, int pos, int t, int sum, vector<int>& seq, vector<vector<int>>& res)
{
    if (pos >= nums.size()) return;
    if (sum < t)
    {
        getSum(nums, pos + 1, t, sum, seq, res);
        sum += nums[pos];
        seq.push_back(nums[pos]);
        if (sum == t) res.push_back(seq);
        getSum(nums, pos, t, sum, seq, res);
        seq.pop_back();
    }
}
*/

void combinationSum(vector<int>& nums, int pos, int t, int sum, vector<int>& seq, vector<vector<int>>& res)
{
    if (sum >= t)
    {
        if (sum == t) res.push_back(seq);
        return;
    }
    for (int i = pos; i < nums.size(); i++)
    {
        sum += nums[i];
        seq.push_back(nums[i]);
        combinationSum(nums, i, t, sum, seq, res);
        sum -= nums[i];
        seq.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& nums, int t)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> seq;
    //getSum(nums, 0, t, 0, seq, res);
    combinationSum(nums, 0, t, 0, seq, res);
    return res;
}

int main(void)
{
    vector<int> nums = { 2,3,6,7 };
    auto res = combinationSum(nums, 7);
	return 0;
}