#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numberOfArrays(vector<int>& differences, int lower, int upper)
{
    long long sum = 0, res = 0, minval = 0, maxval = 0;
    for (int num : differences)
    {
        sum += num;
        minval = min(sum, minval);
        maxval = max(sum, maxval);
    }
    res = (upper - maxval) - (lower - minval) + 1;
    return res > 0 ? res : 0;
}

int main(void)
{

	return 0;
}