#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
int majorityElement(vector<int>& nums)
{
    unordered_map<int, int> freq;
    int tgt = nums.size() / 2 + 1;
    for (int num : nums)
    {
        if (++freq[num] == tgt)
            return num;
    }
    return 0;
}
*/

int majorityElement(vector<int>& nums)
{
    int major = nums[0], cnt = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (cnt == 0) major = nums[i];
        cnt += (nums[i] == major) ? 1 : -1;
    }
    return major;
}

int main(void)
{

	return 0;
}