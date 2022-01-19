#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// BFS-Solution (Queue Implementation)
int orangesRotting(vector<vector<int>>& grid)
{
	int dir[5] = { 1, 0, -1, 0, 1 }, fresh = 0, rows = grid.size(), cols = grid[0].size();
	queue<vector<int>> rotten;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (grid[i][j] == 2)
			{
				rotten.push({ i,j });
			}
			else if (grid[i][j] == 1)
			{
				fresh++;
			}
		}
	}

	int days = -1;
	for (int sz = 0; !rotten.empty(); days++)
	{
		sz = rotten.size();
		while (sz--)
		{
			for (int i = 0; i < 4; i++)
			{
				int row = rotten.front()[0] + dir[i];
				int col = rotten.front()[1] + dir[i + 1];
				if (row >= 0 && row < rows && col >= 0 && col < cols && grid[row][col] == 1)
				{
					grid[row][col] = 2;
					rotten.push({ row, col });
					fresh--;
				}
			}
			rotten.pop();
		}
	}
	if (fresh)
	{
		return -1;
	}
	if (days == -1)
	{
		return 0;
	}
	return days;
}

int main(void)
{

	return 0;
}