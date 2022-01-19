#include <iostream>
#include <vector>

using namespace std;

/*
//DP - Method
int lengthOfLIS(const vector<int>& nums) {
	int n = nums.size(), maxCnt = 1;
	vector<int> dp(n, 1);
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
		}
		maxCnt = max(maxCnt, dp[i]);
	}
	return maxCnt;
}
*/

//Binary Search
int lengthOfLIS(const vector<int>& nums) {
	vector<int> seq{nums[0]};
	for (int i = 1; i < nums.size(); i++) {
		auto it = lower_bound(seq.begin(), seq.end(), nums[i]);
		if (it == seq.end()) seq.push_back(nums[i]);
		else *it = nums[i];
	}
	return seq.size();
}

int main(void) {
	vector<int> nums{0,1,0,3,2,3};
	cout << lengthOfLIS(nums);
	return 0;
}