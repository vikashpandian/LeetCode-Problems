#include <iostream>
#include <vector>

using namespace std;

vector<int> searchRange(vector<int>& nums, int target, int start, int end) {
    if (start <= end) {
        int mid = (start + end) / 2;
        if (target < nums[mid]) return searchRange(nums, target, start, mid - 1);
        else if (target > nums[mid]) return searchRange(nums, target, mid + 1, end);
        else {
            start = searchRange(nums, target, start, mid - 1)[0];
            end = searchRange(nums, target, mid + 1, end)[1];
            return { start != -1 ? start : mid , end < mid ? mid : end };
        }
    }
    return {-1, -1};
}

vector<int> searchRange(vector<int>& nums, int target) {
    return searchRange(nums, target, 0, nums.size() - 1);
}

int main() {
    vector<int> nums = {7,8,8,8,8,8,8,8,9};
    vector<int> out = searchRange(nums, 8);
    if (!out.empty())
        cout << out[0] << "\t" << out[1];
    return 0;
}