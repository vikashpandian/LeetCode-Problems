#include <iostream>
#include <vector>

#define MAX(a,b) (a>b ? a:b)
#define MIN(a,b) (a<b ? a:b)

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int count = 0;
    for (int num : nums) {
        if (num != val)
            nums[count++] = num;
    }
    return count;
}

int main() {
    vector<int> nums = { 0, 0, 1, 1, 5, 2, 2, 3, 3, 4 };
    cout << removeElement(nums, 5) << endl;
    for (int num : nums)
        cout << num << "\t";
    return 0;
}
