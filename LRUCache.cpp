#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
    int sz;
    list<int> lru;
    unordered_map<int, pair<int, list<int>::iterator>> cache;

public:
    LRUCache(int capacity) : sz(capacity)
    {
    }

    void update(int key)
    {
        if (cache.count(key))
        {
            lru.erase(cache[key].second);
        }
        lru.push_front(key);
    }

    int get(int key)
    {
        if (!cache.count(key))
        {
            return -1;
        }
        update(key);
        cache[key].second = lru.begin();
        return (cache[key].first);
    }

    void put(int key, int value)
    {
        if (cache.size() == sz && !cache.count(key))
        {
            cache.erase(lru.back());
            lru.pop_back();
        }
        update(key);
        cache[key] = { value, lru.begin() };
    }
};

int main(void)
{

    return 0;
}