#include <iostream>
#include <vector>

using namespace std;

int mySqrt(int x) {
	if (x < 2) return x;
	int l = 1, r = x, mid = 0;
	while (l < r) {
		mid = r - (r - l) / 2;
		if (mid > x / mid) r = mid - 1;
		else {
			if (mid + 1 > x / (mid + 1)) return mid;
			l = mid;
		}
	}
	return l;
}

int main(void) {
	int a;
	while (cin >> a)
		cout << mySqrt(a) << "\n\n";
	return 0;
}