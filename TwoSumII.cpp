#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> twoSum(vector<int>& nums, int tgt)
{
    auto r = nums.end() - 1, l = nums.begin();
    while (l < r)
    {
        int sum = *l + *r;
        if (sum == tgt)
        {
            return { l - nums.begin() + 1, r - nums.begin() + 1 };
        }
        if (sum < tgt)
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    return {};
}

int main(void)
{

	return 0;
}