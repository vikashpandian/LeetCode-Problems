#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int getFood(vector<vector<char>>& grid)
{
    int m = grid.size(), n = grid[0].size();
    int dirs[5] = { -1, 0, 1, 0, -1 };
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(m, vector<bool>(n));
    //bool visited[m][n];
    //fill_n(*visited, m * n, false);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '*')
            {
                q.push({ i, j });
                visited[i][j] = 1;
                i = m;
                break;
            }
        }
    }

    int dist = 0;
    while (!q.empty())
    {
        int sz = q.size();
        dist++;
        while (sz--)
        {
            auto val = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int x = val.first + dirs[i];
                int y = val.second + dirs[i + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y])
                {
                    if (grid[x][y] == '#')
                    {
                        return dist;
                    }
                    if (grid[x][y] != 'X')
                    {
                        visited[x][y] = true;
                        q.push({ x, y });
                    }
                }
            }
        }
    }
    return -1;
}

int main(void)
{
    cout << ('z' - 'a' + 26) % 26 << ('b' - 'c' + 26) % 26;
	return 0;
}