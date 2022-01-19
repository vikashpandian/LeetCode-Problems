#include <iostream>
#include <vector>
#include <map>

using namespace std;

int start = 0, maxLength = 1;

string longestPalindrome(string s)
{
	const int n = s.length();
	vector<vector<bool>> dp(n, vector<bool>(n));
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i; j < n; j++)
		{
			dp[i][j] = (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1]));

			if (dp[i][j] && j - i + 1 > maxLength)
			{
				start = i;
				maxLength = j - i + 1;
			}
		}
	}
	return s.substr(start, maxLength);
}

/*
map<pair<int, int>, bool> memo;

bool isPalindrome(string& s, int start, int end)
{
	if (memo.count({ start, end }))
	{
		return memo[{start, end}];
	}
	for (int i = start, j = end; i < end - (end - start) / 2; i++, j--)
	{
		if (s[i] != s[j])
		{
			memo.insert({{start, end}, false });
			return false;
		}
	}
	memo.insert({ {start, end}, false });
	return true;
}

void _longestPalindrome(string& s, int start, int end)
{
	if (end - start + 1 > maxLength)
	{
		if (isPalindrome(s, start, end))
		{
			l = start;
			maxLength = end - start + 1;
			return;
		}
		_longestPalindrome(s, start, end - 1);
		_longestPalindrome(s, start + 1, end);
	}
}

string longestPalindrome(string s)
{
	_longestPalindrome(s, 0, s.length() - 1);
	return s.substr(l, maxLength);
}
*/

int main(void)
{
	string word = "ABCESEEEFS";

	return 0;
}