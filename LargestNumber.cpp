#include <iostream>
#include <vector>
#include <string>

using namespace std;

void partition(vector<string>& nums, int start, int end) {
    if (start < end) {
        int j = start;
        for (int i = start; i < end; i++) {
            if (nums[i] + nums[end] > nums[end] + nums[i])
                swap(nums[i], nums[j++]);
        }
        swap(nums[j], nums[end]);
        partition(nums, start, j - 1);
        partition(nums, j + 1, end);
    }
}

void quickSort(vector<string>& nums) {
    partition(nums, 0, nums.size() - 1);
}

string largestNumber(vector<int>& nums) {
    vector<string> largestNum;
    for (int num : nums)
        largestNum.push_back(to_string(num));
    quickSort(largestNum);
    string out;
    for (string num : largestNum)
        out += num;
    return out;
}

int main() {
    vector<int> nums = { 3, 30, 34, 5, 9 };
    cout << largestNumber(nums);

    return 0;
}