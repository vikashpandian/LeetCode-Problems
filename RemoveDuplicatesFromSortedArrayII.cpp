#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
// 2-Pass Solution
int removeDuplicates(vector<int>& nums)
{
    int n = nums.size(), res = 0;
    for (int i = 1, cnt = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1])
        {
            if (++cnt > 2)
            {
                nums[i - 1] = 1e5;
                res++;
            }
        }
        else
        {
            cnt = 1;
        }
    }
    int cnt = 0;
    for (int i = 1; i + cnt < n; i++)
    {
        while (i + cnt < n - 1 && nums[i + cnt] == 1e5) cnt++;
        swap(nums[i], nums[i + cnt]);
    }
    return n - res;
}
*/

int removeDuplicates(vector<int>& nums)
{
    if (nums.size() < 3) return nums.size();
    int pos = 2;
    for (int i = 2; i < nums.size(); i++)
    {
        if (nums[i] > nums[pos - 2])
        {
            nums[pos] = nums[i];
            pos++;
        }
    }
    return pos;
}

int main(void)
{
    vector<int> nums = { 1,1,1,2,2,3 };
    cout << removeDuplicates(nums);
	return 0;
}