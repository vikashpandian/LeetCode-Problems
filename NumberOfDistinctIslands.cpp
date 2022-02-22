#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int dirs[5] = { 0,-1,0,1,0 };
char p[4] = { 'a','b','c','d' };

/*
// Sinking the islands
void dfs(vector<vector<int>>& grid, int x, int y, int m, int n, string& pattern)
{
    for (int i = 0; i < 4; i++)
    {
        int xpos = x + dirs[i], ypos = y + dirs[i + 1];
        if (xpos >= 0 && xpos < m && ypos >= 0 && ypos < n && grid[xpos][ypos])
        {
            grid[xpos][ypos] = 0;
            pattern += p[i];
            dfs(grid, xpos, ypos, m, n, pattern);
        }
        else
        {
            pattern += "e";
        }
    }
}

int numDistinctIslands(vector<vector<int>>& grid)
{
    int m = grid.size(), n = grid[0].size();
    unordered_set<string> patterns;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j])
            {
                grid[i][j] = 0;
                string pattern = "";
                dfs(grid, i, j, m, n, pattern);
                patterns.insert(pattern);
            }
        }
    }
    return patterns.size();
}
*/

// Using visited Array
void dfs(vector<vector<int>>& grid, int x, int y, int m, int n, vector<vector<bool>>& visited, string& pattern)
{
    for (int i = 0; i < 4; i++)
    {
        int xpos = x + dirs[i], ypos = y + dirs[i + 1];
        if (xpos >= 0 && xpos < m && ypos >= 0 && ypos < n && !visited[xpos][ypos] && grid[xpos][ypos])
        {
            visited[xpos][ypos] = true;
            pattern += p[i];
            dfs(grid, xpos, ypos, m, n, visited, pattern);
        }
        else
        {
            pattern += "e";
        }
    }
}

int numDistinctIslands(vector<vector<int>>& grid)
{
    int m = grid.size(), n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n));
    unordered_set<string> patterns;
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] && !visited[i][j])
            {
                visited[i][j] = true;
                string pattern = "";
                dfs(grid, i, j, m, n, visited, pattern);
                patterns.insert(pattern);
                //cnt++;
            }
        }
    }
    // cout << cnt;
    return patterns.size();
}

int main(void)
{

	return 0;
}