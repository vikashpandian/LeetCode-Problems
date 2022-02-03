#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int threeSumSmaller(vector<int>& nums, int target)
{
    sort(nums.begin(), nums.end());
    int n = nums.size(), cnt = 0;
    for (int i = 0; i < n - 2; i++)
    {
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum < target)
            {
                cnt += r - l++;
                //while(++l < r && nums[l] == nums[l - 1]);
            }
            else
            {
                //while(l < --r && nums[r] == nums[r + 1]);
                r--;
            }
        }
        //while(i < n - 1 && nums[i] == nums[i + 1]) i++;
    }
    return cnt;
}

int main(void)
{

	return 0;
}