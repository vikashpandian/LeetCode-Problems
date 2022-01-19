#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

bool checkInclusion(string& s1, string& s2)
{
	if (s2.length() < s1.length())
	{
		return false;
	}
	int chars[26] = { 0 };
	for (char ch : s1)
	{
		chars[ch - 'a']++;
	}
	for (int i = 0, j = 0, count = s1.size(); j < s2.length();)
	{
		if (chars[s2[j++] - 'a']-- > 0)
		{
			count--;
		}
		if (!count)
		{
			return true;
		}
		if (j - i == s1.size() && chars[s2[i++] - 'a']++ >= 0)
		{
			count++;
		}
	}
	return false;
}

int main(void)
{
	string s1 = "boa", s2 = "eidbaooo";
	cout << checkInclusion(s1, s2);
	return 0;
}