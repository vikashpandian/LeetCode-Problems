#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
int subarraySum(vector<int>& nums, int k) {
    if (nums.empty()) return 0;
    int count = 0, sum = 0, prevLen = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = prevLen; j < nums.size(); j++) {
            sum += nums[j];
            if (sum >= k) {
                if (sum == k) count++;
                sum -= nums[i];
                if (sum == k) count++;
                prevLen = j + 1;
                break;
            }
        }
    }
    return count;
}
*/

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> sumMap;
    sumMap.insert({ 0, 1 });
    int sum = 0, out = 0;
    for (int num : nums) {
        sum += num;
        if (sumMap.count(sum - k) > 0) out += sumMap[sum - k];
        auto it = sumMap.find(sum);
        if (it != sumMap.end()) it->second++;
        else sumMap.insert({ sum,1 });
    }
    return out;
}

int main(void) {
    vector<int> nums = { 1,2,3,1,-1,1,-1,3 };
    cout << subarraySum(nums,3) << endl;

    return 0;
}
