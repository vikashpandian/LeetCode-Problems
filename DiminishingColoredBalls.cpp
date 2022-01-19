#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(vector<int>& inventory, int orders)
{
	int mod = 1e9 + 7;
	long n = inventory.size(), result = 0;
	sort(inventory.begin(), inventory.end());

	for (int i = n - 1; i >= 0; i--)
	{
		long x = inventory[i] - (i ? inventory[i - 1] : 0);
		if (!x)
		{
			continue;
		}
		long count = n - i, offset = 0;
		if (count * x > orders)
		{
			offset = orders % count;
			x = orders / count;
		}
		orders -= count * x + offset;
		result += count * (x * (2 * inventory[i] - x + 1)) / 2 + offset * (inventory[i] - x);
		result %= mod;
		if (count < 1)
		{
			break;
		}
	}
	return result;
}

int main(void)
{
	vector<int> inventory = { 2,7,7,7,9 };
	int orders = 9;
	cout << maxProfit(inventory, orders);
	return 0;
}