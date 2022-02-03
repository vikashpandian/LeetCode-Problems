#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> countBits(int n)
{
    vector<int> res(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int val = i, cnt = 0;
        cnt += val % 2 + res[val / 2];
        res[i] = cnt;
        //res[i] = res[i >> 1] + (i & 1);
    }
    return res;
}

int main(void)
{

	return 0;
}