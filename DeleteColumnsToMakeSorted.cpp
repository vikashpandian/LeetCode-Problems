#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minDeletionSize(vector<string>& strs)
{
    int m = strs.size(), n = strs[0].size(), cnt = 0;
    for (int j = 0; j < n; j++)
    {
        for (int i = 1; i < m; i++)
        {
            if (strs[i][j] < strs[i - 1][j])
            {
                cnt++;
                break;
            }
        }
    }
    return cnt;
}

int main(void)
{

	return 0;
}