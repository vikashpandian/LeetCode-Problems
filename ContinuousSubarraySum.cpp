#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
    if (nums.size() < 2) return false;
    unordered_set<int> sums;
    int sum = 0, prev = 0;
    for (int num : nums) {
        prev = sum, sum += num;
        if (k) sum %= k;
        if (sums.count(sum)) return true;
        else sums.insert(prev);
    }
    return false;
}

int main() {
    //vector<int> nums = { 1,3,5 };
    vector<int> nums = { 5,10,0,0 };
    cout << checkSubarraySum(nums, 0) << endl;

    return 0;
}