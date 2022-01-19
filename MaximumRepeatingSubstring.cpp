#include <iostream>
#include <vector>

using namespace std;

/* Trial - Not correct
int maxRepeating(const string& sq, const string& w) {
	if (sq.length() < w.length()) return 0;
	int maxCnt = 0, cnt = 0;
	for (int i = 0; i <= sq.length() - w.length(); i++) {
		int j = 0;
		while (i < sq.length() && j < w.length() && sq[i] == w[j]) i++, j++;
		if (j == w.length()) {
			cnt++, i--;
			maxCnt = max(cnt, maxCnt);
		}
		else i-=j, cnt = 0;
	}
	return maxCnt;
}
*/

int maxRepeating(const string& sq, const string& w) {
	int cnt = 0;
	string copy = w;
	while (sq.find(copy) != string::npos) cnt++, copy += w;
	return cnt;
}

int main(void) {
	string sq, w;
	while (cin >> sq >> w)
		cout << maxRepeating(sq, w) << "\n\n";
	return 0;
}