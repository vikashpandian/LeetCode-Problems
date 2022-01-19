#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& mx, int tgt) {
	int m = mx.size() - 1, n = mx[0].size() - 1, r = m, c = 0;
	if (tgt <mx[0][0] || tgt >mx[m][n]) return false;
	while (c <= n && r >= 0) {
		if (mx[r][c] == tgt) return true;
		mx[r][c] < tgt ? c++ : r--;
	}
	return false;
}

// TODO: Approach from other directions

int main(void) {
	vector<vector<int>> mx = { {1,4},{2,5} };
	cout << searchMatrix(mx, 2);
	return 0;
}