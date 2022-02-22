#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dirs[5] = { 0, -1, 0, 1, 0 };

void dfs(vector<vector<int>>& image, int r, int c, int color, int newColor)
{
    image[r][c] = newColor;

    for (int i = 0; i < 4; i++)
    {
        int x = r + dirs[i], y = c + dirs[i + 1];
        if (x < image.size() && x >= 0 && y < image[0].size() && y >= 0
            && image[x][y] == color)
        {
            dfs(image, x, y, color, newColor);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
{
    if (image[sr][sc] == newColor) return image;
    dfs(image, sr, sc, image[sr][sc], newColor);
    return image;
}

int main(void)
{

	return 0;
}