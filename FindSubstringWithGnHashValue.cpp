#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int hash_val(string& s, int l, int p, int m, int k, vector<long>& dp)
{
    long val = 0, pom = p % m;
    if (!dp[l])
    {
        long po = 1;
        for (int i = l; i < l + k; i++)
        {
            val += long(s[i] - 'a' + 1) * po;
            po *= pom;
        }
        dp[l + 1] = val;
    }
    else
        dp[l + 1] = ((dp[l] - (s[l - 1] - 'a' + 1)) / pom) + (s[l + k - 1] - 'a' + 1) * pow(pom, k - 1);
    return dp[l + 1] % m;
}

string subStrHash(string s, int p, int m, int k, int h)
{
    int n = s.length();
    vector<long> dp(n + 1);
    for (int i = 0; i < n; i++)
    {
        if (i + k < n && hash_val(s, i, p, m, k, dp) == h)
        {
            return s.substr(i, k);
        }
    }
    return "";
}

int main(void)
{
    string s = "xmmhdakfursinye";
    cout << subStrHash(s, 96, 45, 15, 21);
	return 0;
}