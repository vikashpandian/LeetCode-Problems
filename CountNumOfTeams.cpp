#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Solving this by looking at the middle soldier in a team
// And then find smaller and larger ratings in the left and right side
// Time Complexity: O(N^2) Quadratic Time Complexity
int numTeams(vector<int>& rating)
{
    int n = rating.size(), cnt = 0;

    for (int i = 1; i < n - 1; i++)
    {
        int lsmall = 0, llarge = 0;
        int rsmall = 0, rlarge = 0;
        for (int j = 0; j < n; j++)
        {
            if (j == i) continue;
            if (rating[j] < rating[i])
            {
                if (j < i) lsmall++;
                else rsmall++;
            }
            else
            {
                if (j < i) llarge++;
                else rlarge++;
            }
        }
        cnt += lsmall * rlarge + llarge * rsmall;
    }
    return cnt;
}

int main(void)
{

	return 0;
}