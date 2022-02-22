#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n)
{
    vector<int> res(n + 1);
    for (auto& booking : bookings)
    {
        res[booking[0] - 1] += booking[2];
        res[booking[1]] -= booking[2];
    }
    /*
    int sum = 0;
    for(int &num : res)
    {
        num = sum += num;
    }
    */
    for (int i = 1; i < n; i++)
    {
        res[i] += res[i - 1];
    }
    res.pop_back();
    return res;
}

int main(void)
{

	return 0;
}