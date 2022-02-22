#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k)
{
    int n = nums.size();
    unordered_map<int, int> freq;
    for (int num : nums)
    {
        freq[num]++;
    }
    vector<vector<int>> bucket(n + 1);

    for (auto& val : freq)
    {
        bucket[val.second].push_back(val.first);
    }

    vector<int> res;
    for (int i = n; i >= 1; i--)
    {
        if (bucket[i].size())
        {
            // res.insert(res.end(), bucket[i].begin(), bucket[i].end());
            move(bucket[i].begin(), bucket[i].end(), back_inserter(res));
        }
        if (res.size() == k) break;
    }
    return res;
}

int main(void)
{

	return 0;
}