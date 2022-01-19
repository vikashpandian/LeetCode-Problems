#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

/*
//Brute-Force
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
{
	for (int i = 0; i < nums.size() - 1; i++)
	{
		for (int j = i + 1; j <= i + k && j < nums.size(); j++)
		{
			if (abs(long(nums[i]) - long(nums[j])) <= t)
			{
				return true;
			}
		}
	}
	return false;
}
*/

/*
//O(N log K) Solution with set operations
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
{
	set<long> window;
	for (int i = 0; i < nums.size(); i++)
	{
		if (i > k)
		{
			window.erase(nums[i - k - 1]);
		}
		auto pos = window.lower_bound(long(nums[i]) - t);

		if (pos != window.end() && *pos - nums[i] <= t)
		{
			return true;
		}
		window.insert(nums[i]);
	}
	return false;
}
*/

//Bucket Solution O(N)
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
{
	int n = nums.size();
	if (n == 0 || k < 0 || t < 0) return false;

	unordered_map<int, int> buckets;

	for (int i = 0; i < n; i++)
	{
		int bucket_val = floor(float(nums[i]) / (long(t) + 1));

		if (buckets.count(bucket_val)
			|| buckets.count(bucket_val - 1) && long(nums[i]) - buckets[bucket_val - 1] <= t
			|| buckets.count(bucket_val + 1) && long(buckets[bucket_val + 1]) - nums[i] <= t)
		{
			return true;
		}

		buckets.insert({ bucket_val, nums[i] });

		if (buckets.size() > k)
		{
			int delete_val = floor(float(nums[i - k]) / (long(t) + 1));
			buckets.erase(delete_val);
		}
	}
	return false;
}

int main(void)
{
	vector<int> nums = { 1, 2, 3, 1 };
	int k = 3, t = 0;
	cout << containsNearbyAlmostDuplicate(nums, k, t);
	return 0;
}
