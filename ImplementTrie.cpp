#include <iostream>
#include <string>

using namespace std;

class Trie {
private:
    Trie *child[26];
    bool isEOFWord;
public:
    Trie() {
        memset(child, 0, sizeof(child));
        isEOFWord = false;
    }

    void insert(const string& word) {
        Trie* curPtr = this;
        for (char i : word) {
            if (!curPtr->child[i - 'a']) {
                curPtr->child[i - 'a'] = new Trie();
            }
            curPtr = curPtr->child[i - 'a'];
        }
        curPtr->isEOFWord = true;
    }

    bool search(const string& word) {
        Trie* curPtr = find(word);
        return curPtr && curPtr->isEOFWord;
    }

    bool startsWith(const string& prefix) {
        return find(prefix);
    }

    ~Trie() {
        for (int i = 0; i < 26; i++)
        {
            if (child[i])
            {
                delete child[i];
            }
        }
    }
private:
    Trie* find(const string& word) {
        Trie* curPtr = this;
        for (char i : word) {
            curPtr = curPtr->child[i - 'a'];
            if (!curPtr) break;
        }
        return curPtr;
    }
};

int main(void) {
    Trie* trie = new Trie();
	return 0;
}