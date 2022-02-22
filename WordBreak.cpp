#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool dfs(string& s, string word, int pos, unordered_set<string>& dict, vector<int>& memo)
{
    if (memo[pos] != -1) return memo[pos];
    for (int i = pos; i < s.length(); i++)
    {
        word += s[i];
        if (dict.count(word))
        {
            if (i == s.length() - 1 || dfs(s, "", i + 1, dict, memo))
                return memo[pos] = true;
        }
    }
    return memo[pos] = false;
}

bool wordBreak(string s, vector<string>& wordDict)
{
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<int> memo(s.length(), -1);
    return dfs(s, "", 0, dict, memo);
}

int main(void)
{

	return 0;
}