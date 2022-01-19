#include <iostream>
#include <vector>
#include <set>

using namespace std;

int thirdMax(vector<int>& nums) {
    set<long> vals;
    for (int& num : nums) {
        if (vals.insert(num).second && vals.size() > 3)
            vals.erase(vals.begin());
    }
    return vals.size() < 3 ? *vals.rbegin() : *vals.begin();
}

int main() {
    //vector<int> nums = { 1,1,1,1,9,1,1,1,1 };
    vector<int> nums = { 2,2,3,1 };
    cout << thirdMax(nums);
    return 0;
}
