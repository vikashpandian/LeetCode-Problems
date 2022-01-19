#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
//map
int lengthOfLongestSubstringKDistinct(string s, int k)
{
	unordered_map<char, int> charStore;
	int maxLen = 0;
	for (int i = 0, j = 0; i <= j; i++)
	{
		while (j < s.length())
		{
			if (charStore.size() == k && !charStore.count(s[j]))
			{
				//j++;
				break;
			}
			charStore[s[j++]]++;
		}
		maxLen = max(maxLen, j - i);
		if (!--charStore[s[i]])
		{
			charStore.erase(s[i]);
		}
	}
	return maxLen;
}
*/


int lengthOfLongestSubstringKDistinct(string s, int k)
{
	unordered_map<char, int> charStore;
	int maxLen = 0;
	for (int i = 0, j = -1; i < s.length(); i++)
	{
		charStore[s[i]]++;
		while (charStore.size() > k)
		{
			if (!--charStore[s[++j]])
			{
				charStore.erase(s[j]);
			}
		}
		maxLen = max(maxLen, i - j);
	}
	return maxLen;
}


/*
int lengthOfLongestSubstringKDistinct(string s, int k)
{
	int chars[255] = {}, maxLen = 0, count = 0;
	for (int i = 0, j = -1; i < s.length(); i++)
	{
		count += chars[s[i]]++ == 0;
		while (count > k)
		{
			count -= --chars[s[++j]] == 0;
		}
		maxLen = max(maxLen, i - j);
	}
	return maxLen;
}
*/

int main(void)
{
	string s = "sdayhgfdseafdjhajshgdgffshs";
	cout << lengthOfLongestSubstringKDistinct(s, 6);
	return 0;
}

