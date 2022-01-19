#include <iostream>
#include <vector>
#include <set>

using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    int sum = 0;
    double maxAvg = -2147483648;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (i > k - 2) 
            maxAvg = max(maxAvg, double(sum) / k), sum -= nums[i - k + 1];
    }
    return maxAvg;
}

int main() {
    //vector<int> nums = { 1,1,1,1,9,1,1,1,1 };
    vector<int> nums = { 1,12,-5,-6,50,3 };
    cout << findMaxAverage(nums, 4);
    return 0;
}
