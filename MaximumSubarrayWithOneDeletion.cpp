#include <iostream>
#include <vector>

using namespace std;

/*
int maxSum(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    int curSum = nums[0] > 0 ? nums[0] : 0, sum = nums[0], negCnt = nums[0] < 0, delVal = (nums[0] < 0) ? nums[0] : 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0) {
            if (negCnt++) curSum += max(delVal, nums[i]);
            delVal = min(delVal, nums[i]);
        }
        else {
            if (curSum > 0) curSum += nums[i];
            else curSum = nums[i], negCnt = 0, delVal = 0;
        }
        sum = max(curSum, sum);
    }
    return sum;
}
*/

int maxSum(vector<int>& nums) {
    int noDeletion = nums[0], oneDeletion = nums[0], sum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        oneDeletion = max(oneDeletion + nums[i], noDeletion);
        noDeletion = max(noDeletion,0) + nums[i];
        sum = max(sum, max(oneDeletion, noDeletion));
    }
    return sum;
}

int main() {
    //vector<int> nums = { 8,1,2,-1,-2,3,5 };
    //vector<int> nums = { -1,-2,-3 };
    //vector<int> nums = { 1,-4,-5,-2,5,0,-1,2 };
    vector<int> nums = {11, -10, -11, 8, 7, -6, 9, 4, 11, 6, 5, 0};
    cout << maxSum(nums) << endl;

    return 0;
}
