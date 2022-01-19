#include <iostream>
#include <vector>

using namespace std;

/*
//The method I came up with. Not the best
void moveZeroes(vector<int>& nums) {
	if (nums.size() == 1) return;
	int n = nums.size();
	for (int i = 0, j = 1; j < n; i++, j++) {
		if (!nums[i]) {
			while (j < n && nums[j] == 0) j++;
			if (j == n) return;
			swap(nums[j], nums[i]);
		}
	}
}
*/

void moveZeroes(vector<int>& nums) {
	int j = 0;
	for (int& i : nums) {
		if (!i) j++;
		else if (j) swap(i, *(&i - j));
	}
}

int main(void) {
	vector<int> nums = {0,1,0,3,12,0,0};
	moveZeroes(nums);
	for (int n : nums) cout << n << "\t";
	return 0;
}