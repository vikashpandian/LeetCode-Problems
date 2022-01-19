#include <iostream>
#include <vector>
#include <string>
#include <map>

#define MAX(a,b) (a>b ? a:b)
#define MIN(a,b) (a<b ? a:b)

using namespace std;

vector<int> plusOne(vector<int>& digits) {
	for (int i = digits.size(); i--; )
		if (++digits[i] %= 10) return digits;
	digits.insert(digits.begin(), 1);
	return digits;
}

int main() {
	vector<int> digits = {9,9,9,9};
	plusOne(digits);
	return 0;
}
