#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Trie {
private:
    Trie *child[26];
    vector<int> words;
public:
    Trie()
    {
        memset(child, 0, sizeof(child));
    }

    void insert(const string& word, int pos)
    {
        Trie* curPtr = this;
        for (char i : word)
        {
            if (!curPtr->child[i - 'a'])
            {
                curPtr->child[i - 'a'] = new Trie();
            }
            curPtr = curPtr->child[i - 'a'];
            curPtr->words.push_back(pos);
        }
    }

    void search(const string& word, vector<string>& products, vector<vector<string>>& result)
    {
        Trie* curPtr = this;
        for (int i = 0; i < word.length() && curPtr; i++)
        {
            if (curPtr = curPtr->child[word[i] - 'a'])
            {
                for (int j = 0, sz = min(3, int(curPtr->words.size())); j < sz; j++)
                {
                    result[i].push_back(products[curPtr->words[j]]);
                }
            }
        }
    }

    ~Trie()
    {
        for (int i = 0; i < 26; i++)
        {
            if (child[i])
            {
                delete child[i];
            }
        }
    }
};

/*
// Trie Solution
vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord)
{
    vector<vector<string>> result(searchWord.size(), vector<string>{});
    sort(products.begin(), products.end());
    Trie* trie = new Trie();
    for (int i = 0; i < products.size(); i++)
    {
        trie->insert(products[i], i);
    }
    trie->search(searchWord, products, result);
    return result;
}
*/

vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord)
{
    vector<vector<string>> result(searchWord.size(), vector<string>{});
    sort(products.begin(), products.end());
    string word = "";
    auto it = products.begin();
    for (int i = 0; i < searchWord.length(); i++)
    {
        word += searchWord[i];
        it = lower_bound(it, products.end(), word);

        for (int j = 0, sz = min(3, products.end() - it); j < sz; j++)
        {
            string& str = *(it + j);
            if (str.rfind(word, 0))
            {
                break;
            }
            result[i].push_back(str);
        }
    }
    return result;
}

int main(void) {
    vector<string> products  = { "mobile", "mouse", "moneypot", "monitor", "mousepad" };
    string searchWord = "mouse";
    suggestedProducts(products, searchWord);
	return 0;
}