#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int coinChange(vector<int>& coins, int amount)
{
	int n = coins.size();
	vector<int> dp(amount + 1, amount + 1);
	dp[0] = 0;
	for (int i = 1; i <= amount; i++)
	{
		for (int coin : coins)
		{
			if (i >= coin)
			{
				dp[i] = min(dp[i], dp[i - coin] + 1);
			}
		}
	}
	return dp.back() == amount + 1 ? -1 : dp.back();
}

int main(void)
{

	return 0;
}