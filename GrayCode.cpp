#include <iostream>
#include <vector>

using namespace std;

/*
vector<int> grayCode(int n) {
    vector<int> code = { 0,1 };
    for (int i = 1, factor = 2; i < n; i++, factor *= 2)
        for (int j = factor - 1; j >= 0; j--)
            code.push_back(code[j] + factor);
    return code;
}
*/

vector<int> grayCode(int n) {
    vector<int> code;
    for (int i = 0; i < 1<<n; i++)
        code.push_back(i ^ (i >> 1));
    return code;
}

int main() {
    int n = 0;
    while (1) {
        cin >> n;
        for (int i : grayCode(n))
            cout << i << "\t";
        cout << "\n\n";
    }
    return 0;
}