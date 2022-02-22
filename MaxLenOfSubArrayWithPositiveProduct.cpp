#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
elements      :   9    5    8    2    -6    4    -3    0    2    -5    15    10    -7    9    -2
positive_len  :   1    2    3    4     0    1     7    0    1     0     1     2     5    6     5
negative_len  :   0    0    0    0     5    6     2    0    0     2     3     4     3    4     7
*/

int getMaxLen(vector<int>& nums)
{
    int pos = 0, neg = 0, res = 0, n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            pos = neg = 0;
        }
        else if (nums[i] > 0)
        {
            pos++;
            if (neg) neg++;
        }
        else
        {
            swap(pos, neg);
            neg++;
            if (pos) pos++;
        }
        res = max(res, pos);
    }
    return res;
}

int main(void)
{

	return 0;
}