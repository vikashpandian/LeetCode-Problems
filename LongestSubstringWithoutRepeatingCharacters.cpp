#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/*
int lengthOfLongestSubstring(const string& str) {
    if (str.empty()) return 0;
    unordered_set<char> distChars{ str[0] };
    int maxCnt = 1, l = 0;
    for (int i = 1; i < str.length(); i++) {
        while (distChars.count(str[i]))
            distChars.erase(str[l++]);
        distChars.insert(str[i]);
        maxCnt = max(maxCnt, i - l + 1);
    }
    return maxCnt;
}
*/


//Best Solution
int lengthOfLongestSubstring(const string& str) {
    if (str.empty()) return 0;
    unordered_map<char, int> distChars{{str[0],0}};
    int maxCnt = 1, l = 0;
    for (int i = 1; i < str.length(); i++) {
        auto it = distChars.find(str[i]);
        if (it != distChars.end()) {
            if (it->second >= l) l = it->second + 1;
            it->second = i;
        }
        else
            distChars.insert({ str[i], i });
        maxCnt = max(maxCnt, i - l + 1);
    }
    return maxCnt;
}

/*
int lengthOfLongestSubstring(const string& str) {
    if (str.empty()) return 0;
    vector<int> chars(255, -1);
    int maxCnt = 0, l = 0;
    for (int i = 0; i < str.length(); i++) {
        if (chars[str[i]] >= l) l = chars[str[i]] + 1;
        chars[str[i]] = i;
        maxCnt = max(maxCnt, i - l + 1);
    }
    return maxCnt;
}
*/

/*
* Best Time
int lengthOfLongestSubstring(const string& str) {
    if (str.empty()) return 0;
    int chars[255];
    memset(chars, -1, sizeof(chars));
    int maxCnt = 0, l = 0;
    for (int i = 0; i < str.length(); i++) {
        if (chars[str[i]] >= l) l = chars[str[i]] + 1;
        chars[str[i]] = i;
        maxCnt = max(maxCnt, i - l + 1);
    }
    return maxCnt;
}
*/

int main(void) {
    string str;
    while (cin >> str)
        cout << lengthOfLongestSubstring(str) << "\n\n";

    return 0;
}