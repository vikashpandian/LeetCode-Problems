#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
int numberOfSubarrays(vector<int>& nums, int k)
{
    int n = nums.size(), res = 0;
    unordered_map<int, pair<int, int>> pos;
    pos[0] = { -1,-1 };
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] & 1) cnt++;
        if (pos.count(cnt)) pos[cnt].second = i;
        else pos[cnt] = { i,i };
    }
    for (int i = k; pos.count(i); i++)
    {
        res += (pos[i - k].second - pos[i - k].first + 1) * (pos[i].second - pos[i].first + 1);
    }
    return res;
}
*/

int numberOfSubarrays(vector<int>& nums, int k)
{
    int n = nums.size(), res = 0;
    vector<pair<int, int>> pos(n + 1, { -5, -5 });
    pos[0] = { -1,-1 };
    for (int i = 0, cnt = 0; i < n; i++)
    {
        if (nums[i] & 1) cnt++;
        if (pos[cnt].first != -5) pos[cnt].second = i;
        else pos[cnt] = { i,i };
    }
    for (int i = k; i <= n && pos[i].first != -5; i++)
    {
        res += (pos[i - k].second - pos[i - k].first + 1) * (pos[i].second - pos[i].first + 1);
    }
    return res;
}

int main(void)
{

	return 0;
}