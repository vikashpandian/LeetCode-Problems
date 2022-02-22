#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums)
{
    int product = 1, p = 1, cnt = 0, n = nums.size();
    for (int num : nums)
    {
        if (product) product *= num;
        if (num) p *= num;
        else cnt++;
    }
    if (cnt > 1) p = 0;
    for (int i = 0; i < n; i++)
    {
        nums[i] = nums[i] ? product / nums[i] : p;
    }
    return nums;
}

int main(void)
{

	return 0;
}