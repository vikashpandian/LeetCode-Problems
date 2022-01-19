#include <iostream>
#include <vector>

using namespace std;

/* 
// Naive Method
int _minimumTotal(vector<vector<int>>& t, int m, int i) {
	return t[m][i] + (m < t.size() - 1 ? min(_minimumTotal(t, m + 1, i), _minimumTotal(t, m + 1, i + 1)) : 0);
}

int minimumTotal(vector<vector<int>>& t) {
	return _minimumTotal(t, 0, 0);
}
*/

// DP Approach
int minimumTotal(const vector<vector<int>>& t) {
	auto res(t.back());
	for (int i = t.size() - 2; i >= 0; i--) {
		for (int j = 0; j <= i; j++)
			res[j] = min(res[j], res[j + 1]) + t[i][j];
	}
	return res[0];
}

int main(void) {
	vector<vector<int>> triangle = { {2},{3,4},{6,5,7},{4,1,8,3} };
	cout << minimumTotal(triangle);
	return 0;
}