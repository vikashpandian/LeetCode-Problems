#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class HitCounter
{
public:
    int timestamps[300], hits[300];
    HitCounter()
    {
        fill_n(timestamps, 300, 0);
        fill_n(hits, 300, 0);
    }

    void hit(int timestamp)
    {
        if (timestamps[timestamp % 300] != timestamp)
        {
            timestamps[timestamp % 300] = timestamp;
            hits[timestamp % 300] = 1;
            return;
        }
        hits[timestamp % 300]++;
    }

    int getHits(int timestamp)
    {
        int cnt = 0;
        for (int i = 0; i < 300; i++)
        {
            if (timestamp - timestamps[i] < 300)
            {
                cnt += hits[i];
            }
        }
        return cnt;
    }
};

int main(void)
{

	return 0;
}