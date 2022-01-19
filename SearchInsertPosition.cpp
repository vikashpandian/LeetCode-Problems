#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target, int start, int end) {
    if (start > end)
        return start;
    int mid = (start + end) / 2;
    if (nums[mid] < target) 
        return searchInsert(nums, target, mid + 1, end);
    else
        return searchInsert(nums, target, start, mid - 1);
}

int searchInsert(vector<int>& nums, int target) {
    return searchInsert(nums, target, 0, nums.size() - 1);
}

int main() {
    vector<int> nums = { 1, 3, 5, 6 };
    int target = 7;

    cout << searchInsert(nums, target);

    return 0;
}