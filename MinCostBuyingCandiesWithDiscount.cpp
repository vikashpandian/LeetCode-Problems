#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumCost(vector<int>& cost)
{
    sort(cost.begin(), cost.end(), greater<int>());
    int sum = 0, n = cost.size();
    for (int i = 0; i < n; i++)
    {
        if (i % 3 != 2)
        {
            sum += cost[i];
        }
    }
    return sum;
}

int main(void)
{

	return 0;
}