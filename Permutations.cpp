#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    permutRecursive(res, nums, 0);
    return res;
}

void permutRecursive(vector<vector<int>>& res, vector<int>& nums, int pos) {
    if (pos == nums.size()) {
        res.push_back(nums);
        return;
    }
    for (int i = pos; i < nums.size(); i++) {
        swap(nums[pos], nums[i]);
        permutRecursive(res, nums, pos + 1);
        swap(nums[pos], nums[i]);
    }
}

int main() {
    vector<int> nums = { 5,1,3,2,0 };
    cout << "";

    return 0;
}