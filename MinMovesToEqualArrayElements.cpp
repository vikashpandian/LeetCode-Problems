#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
int minMoves(vector<int>& nums)
{
    int min_num = INT_MAX, n = nums.size();
    long sum = 0;
    for (int num : nums)
    {
        sum += num;
        min_num = min(min_num, num);
    }
    return sum - min_num * n;
}
*/

int minMoves(vector<int>& nums)
{
    int min_num = INT_MAX, n = nums.size();
    for (int num : nums)
    {
        min_num = min(min_num, num);
    }
    int res = 0;
    for (int num : nums)
    {
        res += num - min_num;
    }
    return res;
}

int main(void)
{

	return 0;
}