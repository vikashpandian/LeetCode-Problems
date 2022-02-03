#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
// Doesn't Work. Have to correct a lot and not the best approach
int countBinarySubstrings(string s)
{
    int cnt = 1, res = 0, z = 0, o = 0;
    bool isZ = !(s[0] - '0');
    isZ ? z++ : o++;
    for (int i = 1; i < s.length(); i++)
    {
        if (isZ ^ (s[i] - '0'))
        {
            isZ ? z++ : o++;
            cnt++;
        }
        else
        {
            isZ ? o++ : z++;
            if (!--cnt)
            {
                cnt = isZ ? o : z;
                isZ ? z = 0 : o = 0;
                isZ = !isZ;
            }
            res++;
        }
    }
    return res;
}
*/

int countBinarySubstrings(string s)
{
    int prev = 0, cur = 1, res = 0;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == s[i - 1]) cur++;
        else
        {
            res += min(prev, cur);
            prev = cur;
            cur = 0;
        }
    }
    return res + min(prev, cur);
}


int main(void)
{
    cout << countBinarySubstrings("00110011");
    //cout << countBinarySubstrings("10101");
	return 0;
}