#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findAnagrams(string s, string p)
{
    vector<int> res;
    int n = s.length(), k = p.length();
    if (n < k) return res;
    vector<int> freq(26);
    for (char c : p)
    {
        freq[c - 'a']++;
    }
    vector<int> freq2(26);
    for (int i = 0; i < n; i++)
    {
        freq2[s[i] - 'a']++;
        if (i >= k - 1)
        {
            if (freq == freq2)
            {
                res.push_back(i - k + 1);
            }
            freq2[s[i - k + 1] - 'a']--;
        }
    }
    return res;
}

int main(void)
{

	return 0;
}