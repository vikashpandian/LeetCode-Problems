#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
int maximumUnits(vector<vector<int>>& boxTypes, int truckSize)
{
    int res = 0;
    sort(boxTypes.begin(), boxTypes.end(), [](auto& a, auto& b) { return a[1] > b[1]; });
    for (auto& box : boxTypes)
    {
        if (truckSize <= 0) break;
        res += min(box[0], truckSize) * box[1];
        truckSize -= box[0];
    }
    return res;
}
*/

int maximumUnits(vector<vector<int>>& boxTypes, int truckSize)
{
    int bucket[1005] = {}, l = 0, r = 0, res = 0;
    for (auto& box : boxTypes)
    {
        bucket[box[1]] += box[0];
        r = max(r, box[1]);
        l = min(l, box[1]);
    }

    for (int i = r; i >= l; i--)
    {
        if (bucket[i])
        {
            res += min(bucket[i], truckSize) * i;
            truckSize -= bucket[i];
            if (truckSize <= 0) break;
        }
    }
    return res;
}

int main(void)
{

	return 0;
}