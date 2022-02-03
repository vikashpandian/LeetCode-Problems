#include <iostream>
#include <vector>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    int m = nums1.size(), n = nums2.size(), cnt = 0, pos = (m + n) / 2;
    int l1 = 0, l2 = 0, r1 = m - 1, r2 = n - 1, mid1, mid2;
    while (true)
    {
        mid1 = l1 + (r1 - l1) / 2, mid2 = l2 + (r2 - l2) / 2;
        if (nums1[mid1] <= nums2[mid2])
        {
            cnt += mid1 - l1;
            l1 = mid1;
            r2 = mid2;
        }
        else
        {
            cnt += mid1 - l1;
            l2 = mid2;
            r1 = mid1;
        }
        if (cnt == pos) return 0;
    }
    return -1;
}

int main() {
    vector<int> nums1 = { 1,2,3,4,5 };
    vector<int> nums2 = { 1,4,7,8,9 };
    findMedianSortedArrays(nums1, nums2);
    return 0;
}