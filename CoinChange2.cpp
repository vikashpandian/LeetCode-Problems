#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int change(int amount, vector<int>& coins)
{
    //vector<int> dp(amount + 1);
    int* dp = new int[amount + 1]();
    dp[0] = 1;
    for (int coin : coins)
    {
        for (int i = coin; i <= amount; i++)
        {
            dp[i] += dp[i - coin];
        }
    }
    int res = dp[amount];
    delete[] dp;
    return res;
}

int main(void)
{

	return 0;
}