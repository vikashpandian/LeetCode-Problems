#include <iostream>
#include <vector>
#include <string>
#include <map>

#define MAX(a,b) (a>b ? a:b)
#define MIN(a,b) (a<b ? a:b)

using namespace std;

char compute(char sum, char& carry) {
	sum += (carry - '0');
	if (sum == '0') {
		carry = '0';
		return '0';
	}
	else if (sum == '1') {
		carry = '0';
		return '1';
	}
	else if (sum == '2') {
		carry = '1';
		return '0';
	}
	else {
		carry = '1';
		return '1';
	}
}

string addBinary(string a, string b) {
	string output;
	char carry = '0';
	for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; i--, j--) {
		if (i >= 0 && j >= 0) output.push_back(compute(a[i] + b[j] - '0', carry));
		else output.push_back(compute(i >= 0 ? a[i] : b[j], carry));
	}
	if (carry == '1') output.push_back('1');
	reverse(output.begin(), output.end());
	return output;
}

int main() {
	string a = "1111";
	string b = "11111";
	cout << addBinary(a, b);
	return 0;
}
