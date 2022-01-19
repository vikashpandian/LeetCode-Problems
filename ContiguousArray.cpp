#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findMaxLength(vector<int>& nums) {
	if (!nums.size()) return 0;
	unordered_map<int, int> pos;
	pos.insert({ 0, -1 });
	int sum = 0, maxLen = 0;
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i] ? 1 : -1;
		auto it = pos.find(sum);
		if (it != pos.end()) maxLen = max(i - it->second, maxLen);
		else pos.insert({ sum, i });
	}
	return maxLen;
}

int main(void) {
	vector<int> nums = {0,1,0};
	cout << findMaxLength(nums) << "\t";
	return 0;
}