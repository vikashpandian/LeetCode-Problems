#include <iostream>
#include <vector>

using namespace std;


int numberOfArithmeticSlices(vector<int>& nums) {
    if (nums.size() < 3) return 0;
    int prev = nums[1] - nums[0], cur = 0, cnt = 0, cont = 0;
    for (int i = 2; i < nums.size(); i++) {
        cur = nums[i] - nums[i - 1];
        if (cur == prev) cont++;
        else {
            if (cont) cnt += (cont * (cont + 1)) / 2;
            cont = 0, prev = cur;
        }
    }
    if (cont) cnt += (cont * (cont + 1)) / 2;
    return cnt;
}



/*
int numberOfArithmeticSlices(vector<int>& nums) {
    if (nums.size() < 3) return 0;
    int prev = nums[1] - nums[0], cur = 0, cnt = 0, cont = 0;
    for (int i = 2; i < nums.size(); i++) {
        cur = nums[i] - nums[i - 1];
        if (cur == prev) cnt += ++cont;
        else cont = 0, prev = cur;
    }
    return cnt;
}
*/

int main() {
    //vector<int> nums = { 1,1,1,1,9,1,1,1,1 };
    vector<int> nums = { 1,1,1,1,1,1,1,1 };
    cout << numberOfArithmeticSlices(nums);
    return 0;
}