#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> letterCombinations(string digits)
{
    if (digits.empty()) return {};
    string pattern[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    vector<string> res = { "" };
    for (char digit : digits)
    {
        vector<string> buffer;
        string& p = pattern[digit - '0'];
        buffer.reserve(res.size() * p.length());
        for (char c : p)
        {
            for (string& s : res)
            {
                buffer.push_back(s + c);
            }
        }
        res = std::move(buffer);
    }
    return res;
}

int main(void)
{

	return 0;
}