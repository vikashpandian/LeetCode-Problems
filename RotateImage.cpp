#include <iostream>
#include <vector>

using namespace std;

/*
void rotate(vector<vector<int>>& mx, int l, int sz) {
	if (sz < 2) return;
	int r = sz + l - 1;
	swap(mx[l][l], mx[r][l]);
	swap(mx[l][r], mx[r][r]);
	swap(mx[l][r], mx[r][l]);
	for (int i = l + 1; i < r; i++) {
		swap(mx[i][l], mx[l][r - i + l]);
		swap(mx[i][r], mx[r][r - i + l]);
	}
	for (int i = l + 1; i < r; i++) {
		swap(mx[i][l], mx[r - i + l][r]);
	}
	rotate(mx, l + 1, sz - 2);
}
*/

void rotate(vector<vector<int>>& mx, int l, int sz) {
	if (sz < 2) return;
	int r = sz + l - 1;
	for (int i = 0; i < sz - 1; i++) {
		swap(mx[l][l+i], mx[r-i][l]);
		swap(mx[l+i][r], mx[r][r-i]);
		swap(mx[l+i][r], mx[r-i][l]);
	}
	rotate(mx, l + 1, sz - 2);
}

void rotate(vector<vector<int>>& mx) {
	rotate(mx, 0, mx.size());
}

int main(void) {
	//vector<vector<int>> mx({ {1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25} });
	//vector<vector<int>> mx({ {1,2,3},{4,5,6},{7,8,9} });
	vector<vector<int>> mx({ {1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18},{19,20,21,22,23,24},{25,26,27,28,29,30},{31,32,33,34,35,36} });
	rotate(mx);
	for (auto& row : mx) {
		for (auto i : row)
			cout << "\t" << i;
		cout << endl;
	}

	return 0;
}