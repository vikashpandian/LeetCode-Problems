#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string removeKdigits(string num, int k)
{
    int n = num.size();
    if (n == k) return "0";
    int rem = n - k;
    string st;
    for (int i = 0; i < n; i++)
    {
        while (st.size() && st.back() > num[i] && k)
        {
            st.pop_back();
            k--;
        }
        st.push_back(num[i]);
    }
    st.erase(rem);
    int pos = st.find_first_not_of('0');
    auto res = pos > st.size() ? "0" : st.substr(pos);
    return res;
}

int main(void)
{

	return 0;
}