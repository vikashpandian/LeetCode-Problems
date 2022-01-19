#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& mx) {
	vector<int> res;
	if (!mx.size()) return res;
	int m = mx.size() - 1, n = mx[0].size() - 1, k = 0, l = 0, i = k, j = -1, sz = mx.size() * mx[0].size();
	while (k <= m && l <= n) {
		while (j < n) res.push_back(mx[i][++j]);
		k++;
		while (i < m) res.push_back(mx[++i][j]);
		n--;
		if (res.size() == sz) break;
		while (j > l) res.push_back(mx[i][--j]);
		m--;
		while (i > k) res.push_back(mx[--i][j]);
		l++;
	}
	return res;
}

int main(void) {
	vector<vector<int>> matrix({ {1,2,3,11},{4,5,6,12},{7,8,9,13} });
	vector<int> out = spiralOrder(matrix);
	for (auto a : out)
		cout << a << "\t";
	return 0;
}