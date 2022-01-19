#include <iostream>
#include <vector>

#define MAX(a,b) (a>b ? a:b)
#define MIN(a,b) (a<b ? a:b)

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int count = 0;
    if (nums.size()) {
        for (int i = count = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1])
                nums[count++] = nums[i];
        }
    }
    return count;
}

int main() {
    vector<int> nums = {};
    cout << removeDuplicates(nums) << endl;
    for (int num : nums)
        cout << num << "\t";
    return 0;
}
