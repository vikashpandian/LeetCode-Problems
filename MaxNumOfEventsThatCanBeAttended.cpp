#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int maxEvents(vector<vector<int>>& events)
{
    int n = events.size();
    if (n < 2) return n;
    sort(events.begin(), events.end());
    int day = 0, cnt = 0, i = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    while (q.size() || i < n)
    {
        if (q.empty())
        {
            day = events[i][0];
        }
        while (i < n && events[i][0] <= day)
        {
            q.push(events[i++][1]);
        }
        q.pop();
        day++, cnt++;
        while (q.size() && q.top() < day)
        {
            q.pop();
        }
    }
    return cnt;
}

int main(void)
{

	return 0;
}