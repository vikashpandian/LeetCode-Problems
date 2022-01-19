#include <iostream>
#include <vector>

using namespace std;

class Cell
{
public:
	int chars[26] = { 0 }, count = 0;
};

int uniqueLetterString(string s)
{
	int n = s.length(), result = 0;
	int contribution[26] = { 0 }, prev_pos[26] = { 0 };

	for (int i = 0, cur_val = 0; i < n; i++)
	{
		int ch = s[i] - 'A';
		cur_val -= contribution[ch];
		contribution[ch] = i - prev_pos[ch] + 1;
		cur_val += contribution[ch];
		prev_pos[ch] = i + 1;
		result += cur_val;
	}
    return result;
}

int main(void)
{

	return 0;
}