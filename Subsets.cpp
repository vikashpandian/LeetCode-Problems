#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
//Iterative Solution
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res = { {} };
    for (int num : nums) {
        int sz = res.size();
        while (sz--) {
            res.push_back(res[sz]);
            res.back().push_back(num);
        }
    }
    return res;
}
*/

void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& sub, int start) {
    res.push_back(sub);

    for (int i = start; i < nums.size(); i++) {
        sub.push_back(nums[i]);
        backtrack(nums, res, sub, i + 1);
        sub.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    res.reserve(1 << nums.size());
    vector<int> sub;
    sub.reserve(10);
    backtrack(nums, res, sub, 0);
    return res;
}

int main(void)
{

	return 0;
}