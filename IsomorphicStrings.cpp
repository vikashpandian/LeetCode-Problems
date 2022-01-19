#include <iostream>
#include <map>

using namespace std;

/*
bool isIsomorphic(const string& s, const string& t) {
	if (s.length() == t.length()) {
		map<char, char> lMap, rMap;
		for (int i = 0; i < s.length(); i++) {
			auto it = rMap.find(t[i]);
			if (it == rMap.end())
				rMap.insert({ t[i], s[i] });
			else if (it->second != s[i]) return false;
			auto it = lMap.find(s[i]);
			if (it == lMap.end())
				lMap.insert({ s[i], t[i] });
			else if (it->second != t[i]) return false;
		}
		return true;
	}
	return false;
}
*/

bool isIsomorphic(const string& s, const string& t) {
	if (s.length() == t.length()) {
		int chars[512] = {0};
		for (int i = 0; i < s.length(); i++) {
			if (chars[s[i]] != chars[t[i] + 256]) return false;
			chars[s[i]] = chars[t[i] + 256] = i + 1;
		}
		return true;
	}
	return false;
}

int main(void) {
	string s, t;
	while (cin >> s >> t) cout << isIsomorphic(s, t) << "\n\n";
	return 0;
}