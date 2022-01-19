#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int curSum = nums[0], maxSum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        curSum = max(curSum + nums[i], nums[i]);
        maxSum = max(curSum, maxSum);
    }
    return maxSum;
}

int main() {
    vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
    cout << maxSubArray(nums) << endl;

    return 0;
}
