#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int removeCoveredIntervals(vector<vector<int>>& iv)
{
    sort(iv.begin(), iv.end());
    int cnt = 1;
    int l = iv[0][0], r = iv[0][1];
    for (int i = 1; i < iv.size(); i++)
    {
        if (iv[i][0] > l && iv[i][1] > r)
        {
            cnt++;
            l = iv[i][0];
        }
        r = max(r, iv[i][1]);
    }
    return cnt;
}

int main(void)
{

	return 0;
}