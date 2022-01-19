#include <iostream>
#include <vector>
#include "utils.h"

using namespace std;

// My solution
vector<vector<int>> updateMatrix(vector<vector<int>>& mx) {
	if (!mx.size()) return vector<vector<int>>();
	int m = mx.size(), n = mx[0].size(), r = m * n;
	vector<vector<int>> res(m, vector<int>(n, INT_MAX));
	//L - R & T - B
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!mx[i][j]) res[i][j] = 0;
			else {
				int top = (i > 0) ? res[i - 1][j] : r;
				int left = (j > 0) ? res[i][j - 1] : r;
				res[i][j] = min(top, left) + 1;
			}
		}
	}
	//R - L & B - T
	for (int i = m - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			if (!mx[i][j]) res[i][j] = 0;
			else {
				int bot = (i + 1 < m) ? res[i + 1][j] : r;
				int right = (j + 1 < n) ? res[i][j + 1] : r;
				res[i][j] = min(min(bot, right) + 1, res[i][j]);
			}
		}
	}
	return res;
}

// TODO - BFS

int main(void) {
	vector<vector<int>> mx = { {0,0,0},{0,1,0},{1,1,1} };
	auto out = updateMatrix(mx);
	print2dMatrix(out);
	return 0;
}
