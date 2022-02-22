#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fixedPoint(vector<int>& arr)
{
    int n = arr.size(), l = 0, r = n - 1, res = -1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (arr[mid] < mid) l = mid + 1;
        else if (arr[mid] > mid) r = mid - 1;
        else
        {
            res = mid;
            r = mid - 1;
        }
    }
    return res;
}

int main(void)
{

	return 0;
}