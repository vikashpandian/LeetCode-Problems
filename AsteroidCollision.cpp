#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids)
{
    vector<int> st;
    st.reserve(asteroids.size());
    for (int i : asteroids)
    {
        while (!st.empty() && st.back() > 0 && st.back() < -i)
        {
            st.pop_back();
        }
        if (st.empty() || i > 0 || st.back() < 0)
        {
            st.push_back(i);
        }
        else if (!st.empty() && st.back() == -i)
        {
            st.pop_back();
        }
    }
    return st;
}

int main(void)
{

	return 0;
}