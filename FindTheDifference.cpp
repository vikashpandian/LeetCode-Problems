#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char findTheDifference(string s, string t)
{
    int val = 0;
    for (int i = 0; i < s.length(); i++)
    {
        val += (t[i] - s[i]);
    }
    val += t.back();
    return char(val);
}

/*
// Bit-Operation Version
char findTheDifference(string s, string t)
{
    char val = 0;
    for (int i = 0; i < s.length(); i++)
    {
        val ^= (t[i] ^ s[i]);
    }
    val ^= t.back();
    return val;
}
*/

int main(void)
{

	return 0;
}