#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int romanToInt(string s)
{
    /*
    unordered_map<char, int> m;
    m.reserve(7);
    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    */

    unordered_map<char, int> m =
    { {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000} };

    int res = 0, n = s.length();
    res += m[s[n - 1]];
    for (int i = n - 2; i >= 0; i--)
    {
        if (m[s[i]] < m[s[i + 1]])
            res -= m[s[i]];
        else
            res += m[s[i]];
    }
    return res;
}

int main(void)
{

	return 0;
}