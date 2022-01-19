#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
// Recursive Solution
long long compute(vector<vector<int>>& questions, int pos, vector<long long>& dp)
{
	if (pos >= questions.size()) return 0;
	if (dp[pos]) return dp[pos];

	int pts = questions[pos][0], jump = questions[pos][1];
	return dp[pos] = max(compute(questions, pos + 1, dp), pts + compute(questions, pos + jump + 1, dp));
}

long long mostPoints(vector<vector<int>>& questions)
{
	vector<long long> dp(questions.size(), 0);
	return compute(questions, 0, dp);
}
*/

// Clever Solution
long long mostPoints(vector<vector<int>>& questions)
{
	long long dp[200001] = { 0 };

	for (int i = questions.size() - 1; i >= 0; i--)
	{
		int pts = questions[i][0], jump = questions[i][1];
		dp[i] = max(dp[i + 1], pts + dp[i + jump + 1]);
	}
	return dp[0];
}

int main(void)
{

	return 0;
}