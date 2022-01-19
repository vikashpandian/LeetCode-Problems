#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int consecutiveNumbersSum(int n)
{
	int count = 1;
	for (int i = 2; n / i >= double(i) / 2; i++)
	{
		int rem = n % i;
		if (i % 2)
		{
			if (rem == 0)
			{
				count++;
			}
		}
		else if (rem == i >> 1)
		{
			count++;
		}
	}
	return count;
}

int main(void)
{
	cout << consecutiveNumbersSum(15);
	return 0;
}