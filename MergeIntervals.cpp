#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    if (intervals.size() <= 1) return intervals;
    vector<vector<int>> result;
    sort(intervals.begin(), intervals.end());
    result.push_back(intervals.front());

    for (int i = 1; i < intervals.size(); i++)
    {
        if (result.back().back() >= intervals[i].front())
        {
            result.back().back() = max(result.back().back(), intervals[i].back());
        }
        else
        {
            result.push_back(intervals[i]);
        }
    }
    return result;
}

int main(void)
{
	vector<vector<int>> intervals({ {1, 3},{2, 6},{8, 10},{15, 18} });
	auto result = merge(intervals);
	return 0;
}