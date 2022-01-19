#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    string output = strs[0];
    for (int i = 1; i < strs.size(); i++) {
        int pos = 0;
        for (; pos < strs[i].length() && pos < output.length() && output[pos] == strs[i][pos]; pos++) {
        }
        output = output.substr(0, pos);
    }
    return output;
}

int main() {
    //vector<string> strs = {"florida","flower","flight"};

    vector<string> strs = { "flower","flow","flight" };

    cout << longestCommonPrefix(strs);

    return 0;
}