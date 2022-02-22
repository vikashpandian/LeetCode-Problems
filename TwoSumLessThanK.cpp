#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/*
//Two-Pointer Solution
int twoSumLessThanK(vector<int>& nums, int k)
{
    sort(nums.begin(), nums.end());
    int val = nums[0], maxsum = -1;
    for (int i = 1, j = nums.size(); i < nums.size();)
    {
        if (val + nums[i] < k)
        {
            maxsum = max(maxsum, val + nums[i++]);
        }
        else j--;
    }
    return maxsum;
}
*/

int twoSumLessThanK(vector<int>& nums, int k)
{
    int maxsum = -1;
    bool vals[1005] = {};

    for (int num : nums)
    {
        if (vals[num] && num << 1 < k)
            maxsum = max(maxsum, num << 1);
        vals[num] = true;
    }

    for (int i = 1, j = 1000; i < j; )
    {
        if (!vals[j] || i + j >= k) j--;
        else
        {
            if (vals[i])
            {
                maxsum = max(maxsum, i + j);
            }
            i++;
        }
    }
    return maxsum;
}

/*
// Set based solution
int twoSumLessThanK(vector<int>& nums, int k)
{
    set<int> vals;
    vals.insert(nums[0]);
    int maxval = INT_MIN;
    for (int i = 1; i < nums.size(); i++)
    {
        int tofind = k - nums[i] - 1;
        auto it = vals.upper_bound(tofind);
        if (it != vals.begin())
        {
            maxval = max(*(--it) + nums[i], maxval);
        }
        vals.insert(nums[i]);
    }

    return maxval == INT_MIN ? -1 : maxval;
}
*/

int main(void)
{

	return 0;
}