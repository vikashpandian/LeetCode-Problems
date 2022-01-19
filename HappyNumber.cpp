#include <iostream>
#include <map>
#include <set>

using namespace std;

set<int> nums;

int computeSum(int n) {
    int val = 0;
    while (n) {
        int num = n % 10;
        val += num * num;
        n /= 10;
    }
    return val;
}

bool isHappy(int n) {
    while (!nums.count(n)) {
        nums.insert(n);
        n = computeSum(n);
        if (n == 1) return true;
    }
    return false;
}

int main() {
    int n = 0;
    while (1) {
        cin >> n;
        cout << isHappy(n) << endl;
    }
    return 0;
}