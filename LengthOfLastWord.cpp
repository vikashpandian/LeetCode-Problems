#include <iostream>
#include <vector>

using namespace std;

int lengthOfLastWord(string& s) {
    int i = s.length() - 1, len = 0;
    for (; i >= 0 && s[i] == ' '; i--);
    for (; i >= 0 && s[i] != ' '; i--, len++);
    return len;
}

int main(void) {
    string zz;
    while (cin >> zz) cout << lengthOfLastWord(zz);
    return 0;
}