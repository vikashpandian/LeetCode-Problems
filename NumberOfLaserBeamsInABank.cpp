#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numberOfBeams(vector<string>& bank)
{
    int prev = 0, res = 0;
    for (string& row : bank)
    {
        int cnt = 0;
        for (char& ch : row)
        {
            if (ch == '1') cnt++;
        }
        if (cnt)
        {
            res += prev * cnt;
            prev = cnt;
        }
    }
    return res;
}

int main(void)
{

	return 0;
}