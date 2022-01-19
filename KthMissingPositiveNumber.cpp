#include <iostream>
#include <vector>

using namespace std;

int findKthPositive(vector<int>& arr, int k) {
	int num = 0, cnt = 0, off = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] != i + off + 1) {
			off = arr[i] - i - 1;
			cnt = off;
			num = arr[i] - 1;
			if (cnt == k) return num;
			if (cnt > k) return num - cnt + k;
		}
	}
	return arr.back() - cnt + k;
}

int main(void) {
	vector<int> nums = { 2,3,4,7,11 };
	cout << findKthPositive(nums, 5);

	return 0;
}