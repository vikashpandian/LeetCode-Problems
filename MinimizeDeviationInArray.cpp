#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int minimumDeviation(vector<int>& nums)
{
    priority_queue<int> maxheap;
    int minval = INT_MAX, range = INT_MAX;

    for (int& num : nums)
    {
        maxheap.push(num & 1 ? num *= 2 : num);
        minval = min(minval, num);
    }

    while (!(maxheap.top() & 1))
    {
        range = min(range, maxheap.top() - minval);
        int val = maxheap.top() >> 1;
        minval = min(minval, val);
        maxheap.push(val);
        maxheap.pop();
    }

    return min(range, maxheap.top() - minval);
}

int main(void)
{

	return 0;
}