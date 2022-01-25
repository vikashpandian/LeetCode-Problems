#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<string> findWords(vector<string>& words)
{
	vector<string> result;
	vector <unordered_set<char>> rows = { { 'q','w','e','r','t','y','u','i','o','p' },
		{ 'a','s','d','f','g','h','j','k','l' }, { 'z','x','c','v','b','n','m' } };

	for (string& word : words)
	{
		for (auto& row : rows)
		{
			int i = 0;
			while (i < word.size() && row.count(char(tolower(word[i]))))
			{
				if (++i == word.size())
				{
					result.push_back(word);
				}
			}
			if (i) break;
		}
	}
	return result;
}

int main(void)
{
	vector<string> words = {"Hello", "Alaska", "Dad", "Peace"};
	findWords(words);
	return 0;
}