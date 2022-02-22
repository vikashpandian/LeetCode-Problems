#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int brightestPosition(vector<vector<int>>& lights)
{
    int n = lights.size();
    vector<pair<int, int>> b(2 * n);

    for (int i = 0; i < n; i++)
    {
        b[i] = { lights[i][0] - lights[i][1], 1 };
        b[i + n] = { lights[i][0] + lights[i][1] + 1, -1 };
    }

    sort(b.begin(), b.end());

    int max_brightness = 0, brightness = 0, res = 0;
    for (auto& val : b)
    {
        brightness += val.second;
        if (brightness > max_brightness)
        {
            max_brightness = brightness;
            res = val.first;
        }
    }
    return res;
}

int main(void)
{

	return 0;
}