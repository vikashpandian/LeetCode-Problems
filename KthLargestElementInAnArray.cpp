#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& nums, int start, int end, int t) {
    if (start <= end) {
        int j = start;
        for (int i = start; i < end; i++) {
            if (nums[i] > nums[end])
                swap(nums[i], nums[j++]);
        }
        swap(nums[j], nums[end]);
        if (j == t) return nums[t];
        if (j > t) return partition(nums, start, j - 1, t);
        else return partition(nums, j + 1, end, t);
    }
    return 0;
}

void shuffle(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) swap(nums[i], nums[rand() % n]);
}

int findKthLargest(vector<int>& nums, int k) {
    shuffle(nums);
    return partition(nums, 0, nums.size() - 1, k - 1);
}

int main(void) {
    vector<int> nums{ 44, 55, 18, 23, 333, 82, 0, 23, -7, 3, -97, 5, 72, 31 };
    cout << findKthLargest(nums, 1);
    return 0;
}