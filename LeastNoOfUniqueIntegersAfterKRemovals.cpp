#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

int findLeastNumOfUniqueInts(vector<int>& arr, int k)
{
    unordered_map<int, int> freq;
    for (int i : arr)
    {
        freq[i]++;
    }
    map<int, int> rev_freq;
    for (auto kp : freq)
    {
        rev_freq[kp.second]++;
    }
    int res = 0;
    for (auto kp : rev_freq)
    {
        if (k)
        {
            if (kp.second * kp.first <= k)
            {
                k -= kp.second * kp.first;
            }
            else
            {
                res += ceil(float(kp.second) - float(k / kp.first));
                k = 0;
            }
        }
        else
        {
            res += kp.second;
        }
    }
    return res;
}

int main(void)
{
    vector<int> arr = { 2, 4, 1, 8, 3, 5, 1, 3 };
    cout << findLeastNumOfUniqueInts(arr, 3);
	return 0;
}