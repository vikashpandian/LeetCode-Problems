#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int cnt = 0;

/*
void dfs(vector<string>& words, int prev, int pos, int c = 0)
{
	if (pos > words.size())
	{
		cnt = max(c, cnt);
	}
	for (int i = pos; i < words.size(); i++)
	{
		if (prev == -1 || words[i].length() == words[prev].length() + 1)
		{
			bool flag = false;
			for (int j = 0, k = 0; j < words[i].length(); j++, k++)
			{
				if(words[prev][k] == words[i][j])
			}
			dfs(words, i, pos + 1, c + 1);
		}
	}
}
*/

int longestStrChain(vector<string>& words)
{
	sort(words.begin(), words.end(), [](string& a, string& b) { return b.length() > a.length(); });
	unordered_map<string, int> dp;

	int longest_seq = 0;

	for (string& word : words)
	{
		int len = 1;
		for (int i = 0; i < word.length(); i++)
		{
			string prev = word.substr(0, i) + word.substr(i + 1);
			if (dp.count(prev))
			{
				len = max(len, dp[prev] + 1);
			}
		}
		dp[word] = len;
		longest_seq = max(longest_seq, len);
	}

	return longest_seq;
}

int main(void)
{

	return 0;
}