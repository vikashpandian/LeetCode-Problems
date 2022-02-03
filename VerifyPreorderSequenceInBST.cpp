#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool verifyPreorder(vector<int>& p)
{
    vector<int> s;
    int min_val = INT_MIN;
    for (int num : p)
    {
        if (num < min_val)
        {
            return false;
        }
        while (!s.empty() && s.back() < num)
        {
            min_val = s.back();
            s.pop_back();
        }
        s.push_back(num);
    }
    return true;
}

int main(void)
{

	return 0;
}