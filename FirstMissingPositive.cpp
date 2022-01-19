#include <iostream>
#include <vector>

using namespace std;

int firstMissingPositive(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++)
        while (nums[i] > 0 && nums[i] < nums.size() && nums[nums[i] - 1] != nums[i]) swap(nums[i], nums[nums[i] - 1]);
    for (int i = 0; i < nums.size(); i++) if (nums[i] != i + 1) return i + 1;
    return nums.size();
}

int main() {
    vector<int> nums = { 5,1,3,2,0 };
    cout << firstMissingPositive(nums);

    return 0;
}