#include <iostream>
#include <vector>

using namespace std;

/*
int missingNumber(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        while (nums[i] < nums.size() && nums[i] != i)
            swap(nums[i], nums[nums[i]]);
    }
    for (int i = 0; i < nums.size(); i++)
        if (nums[i] != i) return i;
    return nums.size();
}
*/

int missingNumber(vector<int>& nums) {
    int out = nums.size();
    for (int i = 0; i < nums.size(); i++) {
        out ^= i;
        out ^= nums[i];
    }
    return out;
}

int main() {
    vector<int> nums = { 5,1,3,2,0 };
    cout << missingNumber(nums);

    return 0;
}
