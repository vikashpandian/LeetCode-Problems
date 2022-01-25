#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
//Creating Range vector
int minTaps(int n, vector<int>& ranges)
{
	vector<vector<int>> r(n + 1, vector<int>(2));
	for (int i = 0; i <= n; i++)
	{
		r[i][0] = max(i - ranges[i], 0);
		r[i][1] = min(i + ranges[i], n);
	}
	sort(r.begin(), r.end());

	int res = 0, start = 0, end = 0;
	for (int i = 0; start < n; res++)
	{
		while (i <= n && r[i][0] <= start)
		{
			end = max(end, r[i++][1]);
		}
		if (start == end)
		{
			return -1;
		}
		start = end;
	}
	return res;
}
*/

//Further optimizing the range vector
int minTaps(int n, vector<int>& ranges)
{
	vector<int> r(n + 1);
	for (int i = 0; i <= n; i++)
	{
		if (!ranges[i]) continue;
		int idx = max(i - ranges[i], 0);
		r[idx] = max(i + ranges[i], r[idx]);
	}

	int res = 0, start = 0, end = 0;
	for (int i = 0; start < n; res++)
	{
		while (i <= n && i <= start)
		{
			end = max(end, r[i++]);
		}
		if (start == end)
		{
			return -1;
		}
		start = end;
	}
	return res;
}

int main(void)
{

	return 0;
}