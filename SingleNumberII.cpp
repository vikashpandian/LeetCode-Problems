#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
    int sum = 0, norSum = 0;
    for (int num : nums)
        sum += num, norSum = (~norSum) & (~num);
    return norSum;
}

int main() {
    vector<int> nums = { 0, 1, 0, 1, 0, 1, 99};
    cout << singleNumber(nums);

    return 0;
}
