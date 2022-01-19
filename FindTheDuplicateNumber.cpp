#include <iostream>
#include <vector>

using namespace std;

/*
// Works only for a specific set of inputs
int findDuplicate(vector<int>& nums) {
	int sum = 0, maxNum = 0, n = nums.size();
	for (int num : nums) sum += num, maxNum = max(maxNum, num);
	for (int i = maxNum + 1; i <= nums.size(); i++) sum += i;
	return (sum - (n * (n + 1)) / 2) / (n - maxNum);
}
*/

/*
// Finding Cycle
int findDuplicate(vector<int>& nums) {
	int i = nums[0], ii = nums[i];
	while (i != ii) {
		i = nums[i];
		ii = nums[nums[ii]];
	}
	ii = 0;
	while (i != ii) {
		i = nums[i];
		ii = nums[ii];
	}
	return i;
}
*/

//Pigeon Hole Principle
int findDuplicate(vector<int>& nums) {
	int l = 1, r = nums.size() - 1;
	while (l < r) {
		int m = l + (r - l) / 2, cnt = 0;
		for (int num : nums) cnt += num <= m;
		cnt <= m ? l = m + 1 : r = m;
	}
	return l;
}


int main(void) {
	vector<int> nums{1,2,3,5,5,5,6};
	cout << findDuplicate(nums);
	return 0;
}
