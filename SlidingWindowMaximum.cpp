#include <iostream>
#include <vector>
#include <deque>

using namespace std;

//Monotonic Queue Solution
vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
    vector<int> result;
    deque<int> values;
    for (int i = 0; i < nums.size(); i++)
    {
        if (!values.empty() && values.front() == i - k)
        {
            values.pop_front();
        }
        while (!values.empty() && nums[i] > nums[values.back()])
        {
            values.pop_back();
        }
        values.push_back(i);
        if (i >= k - 1)
        {
            result.push_back(nums[values.front()]);
        }
    }
    return result;
}

int main(void)
{

    return 0;
}