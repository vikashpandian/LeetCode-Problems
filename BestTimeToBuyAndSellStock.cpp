#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& prices)
{
    int small = 1e6, res = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        small = min(small, prices[i - 1]);
        res = max(prices[i] - small, res);
    }
    return res;
}

int main(void)
{

	return 0;
}