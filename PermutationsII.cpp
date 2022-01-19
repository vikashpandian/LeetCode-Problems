#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "utils.h"

using namespace std;
/*
// Sort and Eliminate Solution
void permuteRecursive(vector<vector<int>>& res, vector<int> nums, int pos) {
    if (pos == nums.size() - 1) {
        res.push_back(nums);
        return;
    }
    for (int i = pos; i < nums.size(); i++) {
        if (i == pos || nums[i] != nums[pos]) {
            swap(nums[i], nums[pos]);
            permuteRecursive(res, nums, pos + 1);
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    permuteRecursive(res, nums, 0);
    return res;
}
*/

void permute(vector<vector<int>>& res, vector<int> nums, int pos) {
    if (pos == nums.size() - 1) {
        res.push_back(nums);
        return;
    }
    set<int> vals;
    for (int i = pos; i < nums.size(); i++) {
        if (vals.insert(nums[i]).second) {
            swap(nums[i], nums[pos]);
            permute(res, nums, pos + 1);
            swap(nums[i], nums[pos]);
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    permute(res, nums, 0);
    return res;
}

int main() {
    vector<int> nums = { 1,1,2,3};
    auto res = permuteUnique(nums);
    print2dMatrix(res);

    return 0;
}