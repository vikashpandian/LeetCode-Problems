#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getModifiedArray(int length, vector<vector<int>>& updates)
{
    vector<int> result(length);

    for (auto& op : updates)
    {
        result[op[0]] += op[2];
        if (op[1] < length - 1)
        {
            result[op[1]] -= op[2];
        }
    }
    for (int i = 1; i < length; i++)
    {
        result[i] += result[i - 1];
    }
    return result;
}

int main(void)
{

    return 0;
}