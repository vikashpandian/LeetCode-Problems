#include <iostream>
#include <vector>
#include <set>

using namespace std;

int kConcatenationMaxSum(const vector<int>& nums, int k) {
	long long l = 0, r = 0, lMax = 0, rMax = 0, n = nums.size() - 1, sub = 0, subMax = 0;
	for (int i = 0; i <= n; i++) {
		l += nums[i];
		sub = sub>0?max(sub + nums[i], l):nums[i];
		subMax = max(subMax, sub);
		r += nums[n - i];
		lMax = max(l, lMax);
		rMax = max(r, rMax);
	}
	set<long long> vals{ k * l,lMax,rMax,subMax };
	if (k > 1) vals.insert({ rMax + (k - 1) * l ,lMax + (k - 1) * l , rMax + (k - 2) * l + lMax , lMax + rMax });
	return (*vals.rbegin()) % ((int)1e9 + 7);
}

int main(void) {
	vector<int> nums{ -5,4,-4,-3,5,-3 };
	cout << kConcatenationMaxSum(nums,2);
	return 0;
}
