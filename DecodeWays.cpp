#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
//Memoization
int numDecodings(string& s, int pos, unordered_map<int, int>& memo)
{
    if (memo.count(pos)) return memo[pos];

    int n = s.length();
    if (pos == n) return 1;

    int cur = s[pos] - '0';
    if (!cur) return 0;

    int cnt = numDecodings(s, pos + 1, memo);

    if (pos + 1 < n && (cur * 10 + s[pos + 1] - '0' <= 26))
        cnt += numDecodings(s, pos + 2, memo);

    memo[pos] = cnt;
    return  cnt;
}

int numDecodings(string s)
{
    unordered_map<int, int> memo;
    return numDecodings(s, 0, memo);
}
*/

// Tabulation Solution
int numDecodings(string s)
{
    int n = s.length();
    vector<int> dp(n + 1);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] != '0')
            dp[i] += dp[i - 1];
        if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + s[i - 1] - '0' <= 26))
            dp[i] += dp[i - 2];
    }
    return dp[n];
}

int main(void)
{

	return 0;
}