#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool detectCapitalUse(string word)
{
	for (int i = 1; i < word.length(); i++)
	{
		if (isupper(word[i]) != isupper(word[1]) || (islower(word[0]) && isupper(word[i])))
			return false;
	}
	return true;
}

int main(void)
{
	for (int i = 0; i <= 255; i++)
	{
		cout << i << " " << char(i) << endl;
	}
	cout << detectCapitalUse("Vikash");
	return 0;
}