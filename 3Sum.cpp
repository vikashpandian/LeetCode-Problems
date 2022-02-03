#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_set>

using namespace std;

/*
vector<vector<int>> threeSum(vector<int>& nums) {
    map<int, int> pve, nve;
    int zeros = 0;
    for (int i : nums) {
        if (i < 0) {
            auto it = nve.find(i);
            if (it != nve.end()) it->second++;
            else nve.insert(i, 1);
        }
        else if (i == 0) ++zeros;
        else {
            auto it = pve.find(i);
            if (it != pve.end()) it->second++;
            else pve.insert(i, 1);
        }
    }
    for (int i = 0; i < pve.size(); i++) {
    }
}
*/

/*
inline int binarySearch(vector<int>& nums, int num, int l, int r) {
    if (num == nums[l]) return l;
    if (num == nums[r]) return r;
    while (l < r) {
        int mid = (l + r) / 2;
        if (nums[mid] == num) return mid;
        if (nums[mid] < num) l = mid + 1;
        else r = mid - 1;
    }
    return l;
}
*/

/*
inline int binarySearch(vector<int>& nums, int num, int l, int r) {
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (nums[mid] == num) return mid;
        if (nums[mid] < num) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    if (nums.size() < 3) return res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) break;
        int l = i + 1, r = nums.size() - 1;
        while (l < r) {
            int target = -(nums[i] + nums[l]), ltarget = -(nums[i] + nums[r]);
            if (target > nums[r]) {
                l = binarySearch(nums, ltarget, l, r - 1);
                //if (nums[l] < ltarget) l++;
            }
            else if (nums[r] > target) {
                r = binarySearch(nums, target, l + 1, r);
                //if (nums[r] > target) r--;
            }
            else {
                res.push_back({ nums[i],nums[l],nums[r] });
                while (++l < r && nums[l - 1] == nums[l]);
                while (l < --r && nums[r + 1] == nums[r]);
                continue;
            }
        }
        while (i < nums.size() - 1 && nums[i] == nums[i + 1]) i++;
    }
    return res;
}
*/


vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    if (nums.size() < 3) return res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) break;
        int l = i + 1, r = nums.size() - 1;
        while (l < r) {
            int target = -(nums[i] + nums[l]);
            //if (target < nums[l]) break;
            if (target > nums[r]) l++;
            else if (target < nums[r]) r--;
            else {
                res.push_back({ nums[i],nums[l],nums[r] });
                while (++l < r && nums[l - 1] == nums[l]);
                while (l < --r && nums[r + 1] == nums[r]);
            }
        }
        while (i < nums.size() - 1 && nums[i] == nums[i + 1]) i++;
    }
    return res;
}


/*
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    int n = nums.size();
    if (n < 3) return res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n && nums[i] <= 0; i++) {
        auto l = nums.begin() + i + 1, r = nums.end() - 1;
        while (l < r) {
            int ltarget = -(nums[i] + *l);
            if (ltarget <= *r)
            {
                if (*(r = lower_bound(l + 1, r + 1, ltarget) - 1) == ltarget)
                {
                    res.push_back({ nums[i], *l, ltarget });
                }
                l++;
            }
            int rtarget = -(nums[i] + *r);
            if (rtarget >= *l)
            {
                if (*(l = upper_bound(l, r, rtarget) - 1) == rtarget)
                {
                    res.push_back({ nums[i], rtarget, *r });
                }
                r--;
            }
        }
        while (i < n - 1 && nums[i] == nums[i + 1]) i++;
    }
    return res;
}
*/

/*
vector<vector<int>> threeSum(vector<int>& nums)
{
    int n = nums.size();
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n && nums[i] <= 0; i++)
    {
        unordered_set<int> vals;
        if (i && (nums[i] == nums[i - 1])) continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && (nums[j] == nums[j - 1])) continue;
            int target = -(nums[i] + nums[j]);
            if (vals.count(target))
            {
                res.push_back({ nums[i], target, nums[j] });
            }
            vals.insert(nums[j]);
        }
    }
    return res;
}
*/

int main()
{
    //vector<int> nums{ -1,-1,0,0,0,1,1,2,2,-2,-2,-3,-3,-1,-4,-4,5,5 };
    //vector<int> nums{ -5,0,0,0,0 };
    vector<int> nums{ -1,0,1,2,-1,-4 };
    //vector<int> nums{ 2, 7, 11, 15 };

    auto out = threeSum(nums);
    for (auto& i : out) {
        for (auto j : i) cout << j << "\t";
        cout << endl;
    }

    return 0;
}