#include <iostream>
#include <vector>
#include <string>

using namespace std;

string getHint(string secret, string guess) {
    vector<int> s(10, 0);
    int bull = 0, cow = 0;
    for (int i = 0; i < secret.length(); i++) {
        if (secret[i] == guess[i]) bull++;
        else {
            if (s[secret[i] - '0']++ < 0) cow++;
            if (s[guess[i] - '0']-- > 0) cow++;
        }
    }
    return to_string(bull) + "A" + to_string(cow) + "B";
}

int main() {
    string s, g;
    while (cin >> s && cin >> g)
        cout << getHint(s, g);

    return 0;
}
