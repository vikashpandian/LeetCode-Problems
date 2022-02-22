#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

/*
// Brute-Force
int sumSubarrayMins(vector<int>& arr)
{
    int n = arr.size();
    vector<long> dp(n);
    for (int i = 0; i < n; i++)
    {
        int minval = arr[i];
        for (int j = i; j < n; j++)
        {
            minval = min(minval, arr[j]);
            dp[j] += minval;
        }
    }
    long long sum = 0;
    for (int i : dp) sum += i;

    return sum % int(1e9 + 7);
}
*/

int sumSubarrayMins(vector<int>& arr)
{
    int n = arr.size();
    long sum = 0, l = 0, m = 0;
    stack<int> st;

    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && arr[st.top()] > (i == n ? 0 : arr[i]))
        {
            m = st.top(); st.pop();
            l = st.empty() ? -1 : st.top();
            sum = (sum + (long)arr[m] * (m - l) * (i - m)) % int(1e9 + 7);
        }
        st.push(i);
    }

    return sum;
}

int main(void)
{

	return 0;
}