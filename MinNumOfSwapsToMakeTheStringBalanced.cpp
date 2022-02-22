#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

/*
// Using a Stack
int minSwaps(string s)
{
    stack<int> st;
    int mismatch = 0;
    for (char c : s)
    {
        if (c == '[')
        {
            st.push(c);
        }
        else
        {
            if (st.empty())
                mismatch++;
            else
                st.pop();
        }
    }
    return (mismatch + 1) >> 1;
}
*/

// Simulating stack operations
int minSwaps(string s)
{
    int st_size = 0;
    for (char c : s)
    {
        if (c == '[')
            st_size++;
        else if (st_size)
            st_size--;
    }
    return (st_size + 1) >> 1;
}

int main(void)
{

	return 0;
}