#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int titleToNumber(string pattern)
{
    int res = 0;
    for (char ch : pattern)
    {
        res = res * 26 + (ch - 'A' + 1);
    }
    return res;
}

int main(void)
{

	return 0;
}