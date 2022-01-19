#include <iostream>
#include <vector>

using namespace std;

int divide(int dividend, int divisor) {
	if (dividend == INT_MIN && divisor == -1) return INT_MAX;
	int a = abs(dividend), b = abs(divisor), out = 0;
	while (a >= b) {
		int n = 0;
		for (; a - (b << n) >= 0; n++);
		a -= b << --n, out += 1 << n;
	}
	return (dividend < 0) == (divisor < 0) ? out : -out;
}

int main(void) {
	int a, b;
	while (cin >> a >> b)
		cout << divide(a, b);
	return 0;
}