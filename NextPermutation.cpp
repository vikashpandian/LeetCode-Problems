#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

inline int binarySearch(vector<int>& nums, int num, int l, int r) {
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (nums[mid] <= num) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}

void nextPermutation(vector<int>& nums) {
    int n = nums.size(), i = n - 2;
    if (n == 1) return;
    for (; i >= 0 && nums[i] >= nums[i + 1]; i--);
    reverse(nums.begin() + 1 + i, nums.end());
    if (i >= 0) swap(nums[i], nums[binarySearch(nums, nums[i], i + 1, n - 1)]);
}

int main() {
    //vector<int> nums{ 1,2,4,3 };
    //vector<int> nums{ 4,3,2,1 };
    vector<int> nums{ 1,6,0,9,6,6,5,3,2,1 };
    nextPermutation(nums);
    for(int i:nums) cout << i << "\t";

    return 0;
}
