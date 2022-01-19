#include <iostream>
#include <vector>

#define MAX(a,b) (a>b ? a:b)
#define MIN(a,b) (a<b ? a:b)

using namespace std;

int myAtoi(string s) {
    int i = 0, sign = 1;
    long out = 0;
    for (; i < s.size() && s.at(i) == ' '; i++) {
    }
    if (i < s.size() && (s.at(i) == '+' || s.at(i) == '-'))
        sign = -1 * (s.at(i++) - ',');
    for (; i < s.size() && s.at(i) >= '0' && s.at(i) <= '9'; i++) {
        out = out * 10 + (s.at(i) - '0');
        if (sign * out < INT_MIN)
            return INT_MIN;
        if (sign * out > INT_MAX)
            return INT_MAX;
    }
    return out * sign;
}

int main() {
    string in;
    /*while (true) {
        cin >> in;
        cout << myAtoi(in) << endl;
    }*/

    string s("+789");
    cout << myAtoi(s);

    return 0;
}
