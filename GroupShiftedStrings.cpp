#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

/*
vector<vector<string>> groupStrings(vector<string>& strings)
{
    map<vector<int>, vector<string>> cache;
    for (int i = 0; i < strings.size(); i++)
    {
        string& word = strings[i];
        int n = word.length();
        vector<int> diff(n - 1);
        for (int j = 0; j < n - 1; j++)
        {
            diff[j] = (word[j + 1] - word[j] + 26) % 26;
            //diff[j] = !(diff[j] % 25) ? -(diff[j] / 25) : diff[j];
        }
        cache[diff].push_back(word);
    }
    vector<vector<string>> res;
    for (auto& pair : cache)
    {
        res.push_back(pair.second);
    }
    return res;
}
*/

vector<vector<string>> groupStrings(vector<string>& strings)
{
    unordered_map<string, vector<string>> cache;
    for (int i = 0; i < strings.size(); i++)
    {
        string& word = strings[i];
        int n = word.length();
        string s;
        for (int j = 0; j < n - 1; j++)
        {
            s += char((word[j + 1] - word[j] + 26) % 26 + 'a');
        }
        cache[s].push_back(word);
    }
    vector<vector<string>> res;
    for (auto& pair : cache)
    {
        res.push_back(pair.second);
    }
    return res;
}

int main(void)
{
    vector<string> strings({ "abc", "bcd", "acef", "xyz", "az", "ba", "a", "z" });
    groupStrings(strings);
	return 0;
}