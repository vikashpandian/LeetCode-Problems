#include <iostream>
#include <vector>

using namespace std;

/*
//Initial Solution
int minPathSum(vector<vector<int>>& grid) {
	int m = grid.size(), n = grid.at(0).size();
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int best = 0;
			if (i && j) best = min(grid[i - 1][j], grid[i][j - 1]);
			else best = i ? grid[i - 1][j] : (j ? grid[i][j - 1] : 0);
			grid[i][j] += best;
		}
	}
	return grid[m - 1][n - 1];
}
*/

//Checks Optimized Solution
int minPathSum(vector<vector<int>>& grid) {
	int m = grid.size(), n = grid.at(0).size();
	for (int i = 1; i < m; i++)
		grid[i][0] += grid[i - 1][0];
	for (int i = 1; i < n; i++)
		grid[0][i] += grid[0][i-1];
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
		}
	}
	return grid[m - 1][n - 1];
}

int main(void) {
	vector<vector<int>> grid({ {1,2,3},{4,5,6},{7,8,9} });
	cout << minPathSum(grid);
	return 0;
}