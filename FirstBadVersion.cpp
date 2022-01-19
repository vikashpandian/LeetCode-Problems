#include <iostream>
#include <vector>

using namespace std;

bool isBadVersion(int n) {
    return n >= 15 ? true : false;
}

int firstBadVersion(int n) {
    if (n == 1) return 1;
    int start = 1;
    while (start < n) {
        int mid = (start + n) / 2;
        if (isBadVersion(mid)) n = mid;
        else start = mid + 1;
    }
    return n;
}

int main() {
    int n;
    while (cin >> n) {
        cout << firstBadVersion(n) << "\n\n";
    }

    return 0;
}
