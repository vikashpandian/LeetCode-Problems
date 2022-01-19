#include <iostream>
#include <vector>
#include <map>

using namespace std;

int findPairs(vector<int>& nums, int k) {
	if (k < 0) return 0;
	map<int, int> values;
	int count = 0;
	for (int i : nums)
	{
		values[i] += 1;
	}
	for (auto& keyValue : values)
	{
		if ((k == 0 && keyValue.second > 1) || (k > 0 && values.count(keyValue.first + k)))
		{
			count++;
		}
	}
	return count;
}

int main(void) {
	vector<int> nums = { 1,2,3,4,5 };
	cout << findPairs(nums, 2);
	return 0;
}