#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

/*
// Solution using a set
int numKLenSubstrNoRepeats(string s, int k)
{
    if (k > s.length()) return 0;
    unordered_set<char> chars;
    int cnt = 0;
    for (int i = 0, l = 0; i < s.length(); i++)
    {
        while (chars.size() >= k || chars.count(s[i]))
        {
            chars.erase(s[l++]);
        }
        chars.insert(s[i]);
        if (chars.size() == k) cnt++;
    }
    return cnt;
}
*/

// Solution using an array runs in a better time
int numKLenSubstrNoRepeats(string s, int k)
{
    if (k > s.length()) return 0;
    bool chars[26] = {};
    int cnt = 0, sz = 0;
    for (int i = 0, l = 0; i < s.length(); i++)
    {
        while (sz == k || chars[s[i] - 'a'])
        {
            chars[s[l++] - 'a'] = false;
            sz--;
        }
        chars[s[i] - 'a'] = true;
        sz++;
        if (sz == k) cnt++;
    }
    return cnt;
}

int main(void)
{

	return 0;
}