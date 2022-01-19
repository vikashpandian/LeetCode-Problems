#include <iostream>
#include <vector>

using namespace std;

double myPow(double x, long n) {
    if (!x && !n) return x;
    if (!n) return 1;
    if (x == 0 || x == 1) return x;
    if (n < 0) return 1 / myPow(x, -1 * n);
    if (n <= INT_MIN) return 0;
    if (n % 2) return x * myPow(x, n - 1);
    double halfPow = myPow(x, n / 2);
    return halfPow * halfPow;
}

int main() {
    while (1) {
        double n, p;
        cin >> n >> p;
        cout << myPow(n, p) << endl;
    }
    return 0;
}