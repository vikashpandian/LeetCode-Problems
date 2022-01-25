#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

long long maxRunTime(int n, vector<int>& batteries)
{
	long long sum = accumulate(batteries.begin(), batteries.end(), 0LL);
	sort(batteries.begin(), batteries.end(), greater<long long>());
	int len = batteries.size(), i = 0;
	for (; i < len && batteries[i] > sum / (n - i); sum -= batteries[i], i++);
	return sum / (len - i);
}

int main(void)
{

	return 0;
}