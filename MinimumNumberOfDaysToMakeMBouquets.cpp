#include <iostream>
#include <vector>
#include <set>

using namespace std;

/*
//Never read this. Only an experiment.
int minDays(const vector<int>& b, int l, int m, int k, int days) {
	if (m == 0) 
		return days;
	long minVal = LONG_MAX;
	multiset<int> vals;
	for (int i = 0; (((m - 1) * k) <= (b.size() - (l + i + k))) && i < k && l + i + k < b.size(); i++) {
		if (i == 0) for (int j = 0; j < k; j++) vals.insert(b[l + j]);
		if (i) {
			vals.erase(b[l + i]);
			vals.insert(b[l + i + k - 1]);
		}
		long val = minDays(b, l + i + k, m - 1, k, max(days,*vals.rbegin()));
		if (val != -1) minVal = min(val, minVal);
	}
	return (minVal == LONG_MAX) ? -1 : minVal;
}

int minDays(const vector<int>& b, int m, int k) {
	return minDays(b, 0, m, k, INT_MIN);
}
*/

//Binary Search Solution
int minDays(const vector<int>& b, int m, int k) {
	if (m * k > b.size()) return -1;
	int l = 0, r = 1e9;
	while (l < r) {
		int mid = (l + r) >> 1, flow = 0, cnt = 0;
		for (int i : b) {
			if (i > mid) flow = 0;
			else if (++flow == k) {
				flow = 0;
				if (++cnt > m) break;
			}
		}
		if (cnt < m) l = mid + 1;
		else r = mid;
	}
	return l;
}

int main(void) {
	vector<int> b = { 1,10,3,10,2 };
	cout << minDays(b, 3, 1);
	return 0;
}