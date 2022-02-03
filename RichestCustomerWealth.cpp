#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

int maximumWealth(vector<vector<int>>& accounts)
{
	int max_val = 0;
	for(auto& row : accounts)
	{
		max_val = max(max_val, accumulate(row.begin(), row.end(), 0));
	}
	return max_val;
}

int main(void)
{
	return 0;
}