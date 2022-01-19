#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int characterReplacement(string s, int k)
{
	int max_count = 0, chars[26] = { 0 }, j = 0;
	for (int i = 0; i < s.length(); i++)
	{
		max_count = max(max_count, ++chars[s[i] - 'A']);
		if (i - j + 1 > max_count + k)
		{
			--chars[s[j++] - 'A'];
		}
	}
	return s.length() - j;
}

int main(void)
{

	return 0;
}
