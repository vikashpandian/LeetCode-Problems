#include <iostream>
#include <vector>
#include <string>

using namespace std;

string decodeString(string& s, int& i) {
	vector<string> stack;
	string result("");
	while (i < s.length() && s.at(i) != ']') {
		if (s.at(i) > ']') result += s.at(i++);
		else {
			int n = 0;
			while (s.at(i) <= '9') n = n * 10 + (s.at(i++) - '0');
			i++;
			string next = decodeString(s, i);
			i++;
			while (n--) result += next;
		}
	}
	return result;
}

string decodeString(string s) {
	int i = 0;
	return decodeString(s, i);
}

int main(void) {
	string pattern;
	while (cin >> pattern)
		cout << decodeString(pattern) << "\n\n";
	return 0;
}