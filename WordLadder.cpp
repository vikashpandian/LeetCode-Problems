#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>

using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> words(wordList.begin(), wordList.end());
    queue<string> wordq;
    wordq.push(beginWord);
    int seqLen = 0;
    while (!wordq.empty()) {
        seqLen++;
        int sz = wordq.size();
        while (sz--) {
            string word = wordq.front();
            wordq.pop();
            for (char& c : word) {
                char t = c;
                for (int i = 0; i < 26; i++) {
                    c = 'a' + i;
                    if (words.count(word)) {
                        if (word == endWord) return seqLen;
                        wordq.push(word);
                        words.erase(word);
                    }
                }
                c = t;
            }
        }
    }

    return 0;
}

int main(void)
{

	return 0;
}