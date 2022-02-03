#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

/*
// DP-Solution
int countSubstrings(string s)
{
	int n = s.length(), res = 0;
	vector<vector<bool>> dp(n, vector<bool>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j >= 0; j--)
		{
			if(dp[i][j] = (s[i] == s[j] && (i - j >= 2 || dp[i - 1][j + 1]))) res++;
		}
	}
	return res;
}
*/

// DP-Solution Space Compressed
int countSubstrings(string s)
{
	int n = s.length(), res = 0;
	//vector<vector<bool>> dp(2, vector<bool>(n));
	bool dp[2][1000] = {};
	//fill_n(*dp, 2 * n, false);

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j >= 0; j--)
		{
			if (dp[i % 2][j] = (s[i] == s[j] && (i - j <= 2 || dp[(i - 1) % 2][j + 1]))) res++;
		}
	}
	return res;
}

vector<long> countAnagramPhrases(vector<string>& words, vector<string>& phrases)
{
    //map<vector<int>, int> anagrams;
    unordered_map<string, int> anagrams;
    for (string word : words)
    {
        vector<int> freq(26);
        for (char c : word)
        {
            freq[c - 'a']++;
        }
        string s;
        //anagrams[freq]++;
        for (int i = 0; i < freq.size(); i++)
        {
            if (freq[i])
            {
                s += string(char(i + 'a') + to_string(freq[i]) + "#");
            }
        }
        anagrams[s]++;
    }
    vector<long> output;
    for (string phrase : phrases)
    {
        long res = 1;
        vector<int> freq(26);
        for (int i = 0; i < phrase.size(); i++)
        {
            if (phrase[i] != ' ')
            {
                freq[phrase[i] - 'a']++;
            }
            if (phrase[i] == ' ' || i == phrase.size() - 1) {
                string s;
                //anagrams[freq]++;
                for (int i = 0; i < freq.size(); i++)
                {
                    if (freq[i])
                    {
                        s += char(i + 'a') + to_string(freq[i]) + "#";
                    }
                }
                if (anagrams.count(s))
                {
                    res *= anagrams[s];
                }
                for (int i = 0; i < 26; i++)
                {
                    freq[i] = 0;
                }
            }
        }
        output.push_back(res);
    }
    return output;
}

int main(void)
{
    vector<string> words = { "west", "has", "stew", "good", "it" };
    vector<string> phrases = { "west has good stew", "good stew" };
    auto out = countAnagramPhrases(words, phrases);
    for (auto num : out)
    {
        cout << num << "\n";
    }
	return 0;
}