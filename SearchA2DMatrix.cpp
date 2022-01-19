#include <iostream>
#include <vector>

using namespace std;

/*
bool searchMatrix(vector<vector<int>>& mx, int tgt) {
	int m = mx.size() - 1, n = mx[0].size() - 1;
	if (tgt<mx[0][0] || tgt > mx[m][n]) return 0;
	int l = 0, r = m;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (mx[mid][0] == tgt) return true;
		if (mx[mid][0] < tgt) l = mid + 1;
		else r = mid - 1;
	}
	int i = r;
	l = 0, r = n;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (mx[i][mid] == tgt) return true;
		if (mx[i][mid] < tgt) l = mid + 1;
		else r = mid - 1;
	}
	return false;
}
*/

bool searchMatrix(vector<vector<int>>& mx, int tgt) {
	int m = mx.size(), n = mx[0].size();
	if (tgt<mx[0][0] || tgt > mx[m - 1][n - 1]) return 0;
	int l = 0, r = m * n - 1;
	while (l <= r) {
		int mid = (l + r) >> 1 , val = mx[mid / n][mid % n];
		if (val == tgt) return true;
		if (val < tgt) l = mid + 1;
		else r = mid - 1;
	}
	return false;
}

int main(void) {
	vector<vector<int>> mx = { {1,3,5,7},{10,11,16,20},{23,30,34,60} };
	cout << searchMatrix(mx, 33);

	return 0;
}