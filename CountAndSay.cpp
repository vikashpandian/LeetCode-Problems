#include <iostream>
#include <vector>
#include <string>

#define MAX(a,b) (a>b ? a:b)
#define MIN(a,b) (a<b ? a:b)

using namespace std;

string countAndSay(int n) {
	if (n == 1) return "1";
	string prev = countAndSay(n - 1);
	string output;
	int cnt = 0;
	char curChar = 0;
	for (char a : prev) {
		if (curChar != 0 && a != curChar) {
			output.append(to_string(cnt) + curChar);
			curChar = a;
			cnt = 1;
		}
		else {
			curChar = a;
			cnt++;
		}
	}
	output.append(to_string(cnt) + curChar);
	return output;
}

int main() {
	int n;
	cin >> n;
	cout << countAndSay(n);
	return 0;
}
