#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/*
int minMeetingRooms(vector<vector<int>>& intervals)
{
    int n = intervals.size(), start_times[n], end_times[n];
    for (int i = 0; i < n; i++)
    {
        start_times[i] = intervals[i][0];
        end_times[i] = intervals[i][1];
    }
    sort(start_times, start_times + n);
    sort(end_times, end_times + n);
    int rooms = 0, end_i = 0;
    for (int i = 0; i < n; i++)
    {
        if (start_times[i] < end_times[end_i])
            rooms++;
        else
            end_i++;
    }
    return rooms;
}
*/

int minMeetingRooms(vector<vector<int>>& intervals)
{
    sort(intervals.begin(), intervals.end());
    int rooms = 1;
    priority_queue<int, vector<int>, greater<int>> end_times;
    end_times.push(intervals[0][1]);
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] < end_times.top())
            rooms++;
        else
            end_times.pop();
        end_times.push(intervals[i][1]);
    }
    return rooms;
}

int main(void)
{
    vector<vector<int>> intervals = { {1,5},{8,9},{8,9} };
    cout << minMeetingRooms(intervals);
	return 0;
}