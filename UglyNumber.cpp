#include <iostream>
#include <vector>

using namespace std;

bool isUgly(int num) {
    if (num < 1) return false;
    if (num < 7) return true;
    vector<int> factors = { 2,3,5 };
    for(int factor : factors)
        while (num && !(num % factor)) num /= factor;
    return (num == 1) ? true : false;
}

int main() {
    int n;
    while (cin >> n) {
        cout << isUgly(n) << "\n\n";
    }
    return 0;
}
