#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numberOfWays(string c)
{
    int n = c.length(), s = 0, p = 0, mod = 1e9 + 7;
    long long res = 1;
    for (int i = 0, prev = 0; i < n; i++)
    {
        if (c[i] == 'S')
        {
            if (++s > 2 && s % 2)
            {
                res = (res * (i - prev)) % mod;
            }
            prev = i;
        }
    }
    if (s % 2) res = 0;
    return s ? res : 0;
}

int main(void)
{

	return 0;
}