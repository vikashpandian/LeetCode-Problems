#include <iostream>
#include <vector>

#define MAX(a,b) (a>b ? a:b)
#define MIN(a,b) (a<b ? a:b)

using namespace std;

int reverse(int x) {
    long out = 0;
    do {
        out = out * 10 + x % 10;
    } while (x /= 10);
    if (out < INT_MIN || out > INT_MAX)
        return 0;
    return out;
}

int main() {
    int num = 0;
    while (true) {
        cin >> num;
        cout << reverse(num) << endl;
    }

    return 0;
}
