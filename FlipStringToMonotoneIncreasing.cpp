#include <iostream>
#include <vector>

using namespace std;

/*
int minFlipsMonoIncr(string s)
{
	int flips = 0, ones = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '0')
		{
			if (!ones)
			{
				continue;
			}
			flips++;
		}
		else
		{
			ones++;
		}
		flips = min(flips, ones);
	}
	return flips;
}
*/

int minFlipsMonoIncr(string s)
{
	int flips = 0, ones = 0;
	for (char c : s)
	{
		flips = min(flips + '1' - c, ones += c - '0');
	}
	return flips;
}

int main(void)
{
	string s = "001100";

	return 0;
}