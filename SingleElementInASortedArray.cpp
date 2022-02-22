#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
int singleNonDuplicate(vector<int>& nums)
{
    int n = nums.size(), l = 0, r = n - 1;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        int of = (mid - l) & 1 ? -1 : 1;
        if (nums[mid - of] == nums[mid])
        {
            r = mid - (of < 0 ? 1 : 2);
        }
        else if (nums[mid + of] == nums[mid])
        {
            l = mid + (of < 0 ? 1 : 2);
        }
        else
        {
            return nums[mid];
        }
    }
    return nums[l];
}
*/

int singleNonDuplicate(vector<int>& nums)
{
    int n = nums.size(), l = 0, r = n - 1;
    while (l < r)
    {
        int mid = l + (r - l) / 2;
        if (mid & 1) mid--;
        if (nums[mid] == nums[mid + 1])
        {
            l = mid + 2;
        }
        else
        {
            r = mid;
        }
    }
    return nums[l];
}

int main(void)
{

	return 0;
}