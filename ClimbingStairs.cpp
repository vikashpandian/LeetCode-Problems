#include <iostream>
#include <vector>

using namespace std;

/*
int climbStairs(int n) {
    int res = 0;
    for (int twos = n / 2, ones = n % 2; twos >= 0; twos--, ones += 2) {
        if (!twos || !ones)
            res += 1;
        else {
            double val = 1;
            for (double i = (twos > ones ? twos : ones) + 1, j = 1; i <= twos + ones; i++, j++)
                val *= (i / j);
            res += val;
        }
    }
    return res;
}
*/

int climbStairs(int n) {
    int a = 1, b = 1;
    while (--n)
        a = (b += a) - a;
    return b;
}

int main() {
    int n;
    while (cin >> n) {
        cout << climbStairs(n) << "\n\n";
    }
    return 0;
}
