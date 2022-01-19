#include <iostream>
#include <vector>
#include <algorithm>
#include "utils.h"

using namespace std;

typedef pair<int, int> p;

inline int binarySearch(vector<p>& nums, int num, int l, int r) {
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (nums[mid].first == num) return nums[mid].second;
		if (nums[mid].first < num) l = mid + 1;
		else r = mid - 1;
	}
	return nums[l].second;
}

vector<int> findRightInterval(vector<vector<int>>& intervals) {
	if (intervals.size() == 1) return {-1};
	vector<p> starts;
	vector<int> pos;
	for (int i = 0; i < intervals.size(); i++) starts.push_back({ intervals[i][0], i });
	sort(starts.begin(), starts.end());
	for (auto& i : intervals)
		(i[1] <= starts.back().first) ? pos.push_back(binarySearch(starts, i[1], 0, starts.size() - 1)) : pos.push_back(-1);
	return pos;
}

int main(void) {
	vector<vector<int>> intervals{ {3,4},{2,3},{1,2} };
	auto out = findRightInterval(intervals);
	for (auto i : out) cout << i << "\t";
	return 0;
}