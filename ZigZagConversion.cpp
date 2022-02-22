#include <iostream>
#include <vector>
#include <string>

using namespace std;

string convert(string s, int n)
{
    if (n == 1) return s;
    int m = n - 2, inc = n + m, l = s.length();
    string res;
    for (int i = 0; i < n; i++, inc -= 2)
    {
        if (i == n - 1) inc = n + m;
        for (int j = i, k = 0; j < l; k++)
        {
            res += s[j];
            j += (!(k & 1) || !i || i == n - 1) ? inc : (n + m - inc);
        }
    }
    return res;
}

string convert(string s, int n) {

}

int main() {

    return 0;
}