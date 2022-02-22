#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumElementAfterDecrementingAndRearranging(vector<int>& arr)
{
    sort(arr.begin(), arr.end());
    int prev = 1, n = arr.size();
    arr[0] = 1;
    for (int i = 1; i < n; i++)
    {
        /*
        if (arr[i] == prev) continue;
        arr[i] = prev + 1;
        prev = arr[i];
        */
        prev = min(prev + 1, arr[i]);
    }
    return prev;
}

int main(void)
{

	return 0;
}