#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dirs[5] = { -1, 0, 1, 0, -1 };

void dfs(vector<vector<char>>& grid, int x, int y)
{
    grid[x][y] = '0';
    for (int i = 0; i < 4; i++)
    {
        int x_pos = x + dirs[i], y_pos = y + dirs[i + 1];
        if (x_pos < grid.size() && x_pos >= 0 && y_pos >= 0 && y_pos < grid[0].size()
            && grid[x_pos][y_pos] == '1')
        {
            dfs(grid, x_pos, y_pos);
        }
    }
}

int numIslands(vector<vector<char>>& grid)
{
    int cnt = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == '1')
            {
                dfs(grid, i, j);
                cnt++;
            }
        }
    }
    return cnt;
}

int main(void)
{

	return 0;
}