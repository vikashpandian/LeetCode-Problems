#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

long long minimumRemoval(vector<int>& beans) {
    long long n = beans.size();
    sort(beans.begin(), beans.end());
    /*
    // Tried with a similar approach (To Be Fixed)
    int dp[n], rev[n];
    dp[0] = beans[0];
    rev[n-1] = beans[n-1];
    for(int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + beans[i];
    }
    for(int i = n - 2; i >= 0; i--) {
        rev[i] = rev[i+1] + beans[i];
    }
    for(int i = 0; i < n; i++)
    {
        rev[i] = rev[i] - (beans[i]*(n-i));
    }
    int min1 = INT_MAX, min2 = INT_MAX;
    for(int i = 0; i < n;i++) {
        min1=min(min1, dp[i]+rev[n - 1 - i]);
    }
    return min1;
    */

    long long sum = accumulate(beans.begin(), beans.end(), 0LL), res = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        res = min(res, sum - (n - i) * beans[i]);
    }
    return res;
}

int main(void)
{

	return 0;
}