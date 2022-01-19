#include <iostream>

using namespace std;

int addDigits(int num) {
    return 1 + (num - 1) % 9;
}

int main() {
    int n;
    while (cin >> n) {
        cout << addDigits(n) << "\n\n";
    }
    return 0;
}
