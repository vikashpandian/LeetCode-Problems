#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string reorganizeString(string s)
{
    int freq[26] = {}, high = 0;
    for (char c : s)
    {
        if (++freq[c - 'a'] > freq[high])
            high = c - 'a';
    }
    if (freq[high] * 2 - 1 > s.length()) 
        return "";
    int i = 0, pos = 0;
    while (freq[high])
    {
        s[i] = high + 'a';
        i += 2;
        freq[high]--;
    }
    for (int j = 0; j < 26; j++)
    {
        while (freq[j]--)
        {
            if (i >= s.length()) i = 1;
            s[i] = j + 'a';
            i += 2;
        }
    }

    return s;
}

int main(void)
{

	return 0;
}