#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
class RandomizedSet {
    vector<int> nums;
    unordered_map<int, int> randmap;
public:
    RandomizedSet() {
        //nums.reserve(2e5 + 5);
    }

    bool insert(int val) {
        if (randmap.count(val)) return false;
        nums.push_back(val);
        randmap[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!randmap.count(val)) return false;
        int a = nums.back(), b = randmap[val];
        randmap[a] = b;
        nums[b] = a;
        nums.pop_back();
        randmap.erase(val);
        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
};
*/

class RandomizedSet {
    int nums[int(2e5 + 5)], sz;
    unordered_map<int, int> randmap;
public:
    RandomizedSet() : sz(0) {

    }

    bool insert(int val) {
        if (randmap.count(val)) return false;
        nums[sz] = val;
        randmap[val] = sz++;
        return true;
    }

    bool remove(int val) {
        if (!randmap.count(val)) return false;
        int a = nums[--sz], b = randmap[val];
        randmap[a] = b;
        nums[b] = a;
        randmap.erase(val);
        return true;
    }

    int getRandom() {
        return nums[rand() % sz];
    }
};

int main(void)
{

	return 0;
}