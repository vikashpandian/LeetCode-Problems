#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isRobotBounded(string ins)
{
    int dir[5] = { 0, 1, 0, -1, 0 }; // NESW
    int x = 0, y = 0, cur_dir = 0;

    for (char c : ins)
    {
        if (c == 'L')
        {
            cur_dir = (cur_dir + 3) % 4;
        }
        else if (c == 'R')
        {
            cur_dir = (cur_dir + 1) % 4;
        }
        else
        {
            x += dir[cur_dir];
            y += dir[cur_dir + 1];
        }
    }
    return !x && !y || cur_dir;
}

int main(void)
{

	return 0;
}