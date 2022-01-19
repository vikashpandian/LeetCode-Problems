#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
vector<int> twoSum(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++)
            if (nums.at(i) + nums.at(j) == target)
                return vector<int>({ i,j });
    }

    return vector<int>({ 0,0 });
}
*/

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> memo{ {nums[0], 0} };
    for (int i = 1; i < nums.size(); i++) {
        int toFind = target - nums[i];
        if (memo.find(toFind) != memo.end()) return vector<int>{memo[toFind], i};
        memo[nums[i]] = i;
    }
    return vector<int>();
}

int main() {
    vector<int> nums({ 2, 7, 11, 15 });
    auto out = twoSum(nums, 9);

    for (auto i : out) cout << i << "\t";

    return 0;
}