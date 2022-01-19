#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
//Has minor issues
int leastBricks(vector<vector<int>>& wall) {
	int h = wall.size();
	if (h == 1) return wall[0].size() > 1 ? 0 : 1;
	int n = 0;
	for (int i : wall[0]) n += i;
	vector<int>	fqDist(n, 0);
	for (int i = 0; i < h; i++) {
		int sum = 0;
		for (int j = 0; j < wall[i].size() - 1; j++) {
			sum += wall[i][j];
			fqDist[sum] += 1;
			if (j == h - 1 && fqDist[sum] == h) return 0;
		}
	}
	int maxVal = 0;
	for (int i : fqDist) {
		if (i > maxVal) maxVal = i;
	}
	return h - maxVal;
}
*/

int leastBricks(vector<vector<int>>& wall) {
	int h = wall.size();
	if (h == 1) return wall[0].size() > 1 ? 0 : 1;
	map<int, int> fqDist;
	int minHt = h;
	for (auto& row : wall) {
		int l = 0;
		for (int i = 0; i < row.size() - 1; i++) {
			l += row[i];
			minHt = min(minHt, h - ++fqDist[l]);
			if (!minHt) return 0;
		}
	}
	return minHt;
}

int main(void) {
	vector<vector<int>> wall = { {1,2,2,1},{3,1,2},{1,3,2},{2,4},{3,1,2},{1,3,1,1} };
	cout << leastBricks(wall);
	return 0;
}
