#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

/*
// O(N^2) Solution
long long subArrayRanges(vector<int>& nums)
{
    int n = nums.size();
    if (n < 2) return 0;
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        int min_no = nums[i], max_no = nums[i];
        for (int j = i + 1; j < n; j++)
        {
            min_no = min(min_no, nums[j]);
            max_no = max(max_no, nums[j]);
            sum += max_no - min_no;
        }
    }
    return sum;
}
*/

long long subArrayRanges(vector<int>& nums)
{
    int n = nums.size();
    long long res = 0;
    stack<int> s;
    for (int i = 0; i <= n; i++)
    {
        while (!s.empty() && nums[s.top()] > (i == n ? INT_MIN : nums[i]))
        {
            int j = s.top(); s.pop();
            int k = s.empty() ? -1 : s.top();
            res -= (long)nums[j] * (i - j) * (j - k);
        }
        s.push(i);
    }
    s = stack<int>();
    for (int i = 0; i <= n; i++)
    {
        while (!s.empty() && nums[s.top()] < (i == n ? INT_MAX : nums[i]))
        {
            int j = s.top(); s.pop();
            int k = s.empty() ? -1 : s.top();
            res += (long)nums[j] * (i - j) * (j - k);
        }
        s.push(i);
    }
    return res;
}

int main(void)
{

	return 0;
}