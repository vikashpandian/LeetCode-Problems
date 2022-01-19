#include <iostream>
#include <vector>

using namespace std;

int minSwaps(vector<int>& data)
{
	int n = data.size();
	for (int i = 1; i < n; i++)
	{
		data[i] = data[i] + data[i - 1];
	}
	int winLen = data[n - 1];
	if (winLen <= 1)
	{
		return 0;
	}
	int maxCount = data[winLen - 1];
	for (int i = winLen; i < n; i++)
	{
		maxCount = max(maxCount, data[i] - data[i - winLen]);
	}
	return winLen - maxCount;
}

int main(void)
{
	vector<int> data = {1,0,1,0,1};
	cout << minSwaps(data);
	return 0;
}
