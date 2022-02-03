#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

/*
vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    map<vector<int>, vector<string>> cache;
    for (string& s : strs)
    {
        vector<int> pattern(26);
        for (char c : s)
        {
            pattern[c - 'a']++;
        }
        cache[pattern].push_back(s);
    }
    vector<vector<string>> res;
    for (auto& v : cache)
        res.push_back(v.second);
    return res;
}
*/

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    map<string, vector<string>> cache;
    for (string& s : strs)
    {
        int pattern[26] = {};
        for (char c : s)
        {
            pattern[c - 'a']++;
        }
        string pat;
        for (int i = 0; i < 26; i++)
        {
            if (pattern[i])
            {
                pat += string(pattern[i], i + 'a');
            }
        }
        cache[pat].push_back(s);
    }
    vector<vector<string>> res;
    res.reserve(cache.size());
    for (auto& v : cache)
        res.push_back(move(v.second));
    return res;
}

int main(void)
{

	return 0;
}