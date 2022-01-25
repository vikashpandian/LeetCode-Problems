#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool validMountainArray(vector<int>& arr)
{
    if (arr.size() < 3) return false;
    bool inc = false, dec = false;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] == arr[i - 1]) return false;
        if (arr[i] > arr[i - 1])
        {
            inc = true;
            if (dec) return false;
        }
        else
        {
            dec = true;
            if (!inc) return false;
        }
    }
    return inc && dec;
}

int main(void)
{

	return 0;
}