#include <iostream>
#include <vector>

using namespace std;

/*
bool isPalindrome(int x) {
    if (x < 0) return false;
    if (x < 10) return true;
    int fast = x, half = 0;
    while (fast) {
        if (fast > 9)
            half = half * 10 + x % 10;
        x /= 10, fast /= 100;
    }
    return x == half;
}
*/

bool isPalindrome(int x) {
    if (x < 0 || (x && x % 10 == 0)) return false;
    if (x < 10) return true;
    int half = 0;
    while (half < x) {
        half = half * 10 + x % 10;
        x /= 10;
    }
    return (x == half || x == half / 10);
}

int main() {
    cout << isPalindrome(997899);
    return 0;
}