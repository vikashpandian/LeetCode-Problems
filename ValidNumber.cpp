#include <iostream>
#include <vector>

using namespace std;

bool checkInt(string& s, int& pos) {
	int start = pos;
	while (isdigit(s[pos]) && pos < s.length()) pos++;
	return start == pos ? false : true;
}

bool checkNumber(string& s, int& pos) {
	if (s[pos] == '+' || s[pos] == '-')
		if (++pos == s.length()) return false;
	int start = pos;
	checkInt(s, pos);
	if (pos != s.length() && s[pos] == '.')
		if (!checkInt(s, ++pos) && start + 1 == pos) return false;
	return start == pos ? false : true;
}

bool isNumber(string s) {
	if (s.empty()) return false;
	if (s.length() == 1) return isdigit(s.at(0));
	int i = 0;
	if (checkNumber(s, i)) {
		if (i == s.length()) return true;
		if ((s[i] == 'e' || s[i] == 'E') && ++i != s.length())
			if (((s[i] == '+' || s[i] == '-') && ++i != s.length()), checkInt(s, i) && i == s.length()) return true;
	}
	return false;
}

int main(void) {
	string n;
	while (cin >> n)
		cout << isNumber(n) << "\n\n";
	return 0;
}