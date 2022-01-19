#include <iostream>
#include <vector>

using namespace std;

bool isValid(string s) {
    vector<char> stack;
    for (char brace : s) {
        if (!stack.empty() && (brace - stack.back() == 1 || brace - stack.back() == 2))
            stack.pop_back();
        else
            stack.push_back(brace);
    }
    return stack.empty();
}

int main() {
    string braces("[]{}()[]{}");
    cout << isValid(braces);
    return 0;
}