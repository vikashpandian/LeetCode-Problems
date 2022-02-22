#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <list>

using namespace std;

class FirstUnique
{
    unordered_map<int, list<int>::iterator> vals;
    list<int> valq;
public:
    FirstUnique(vector<int>& nums)
    {
        while (!valq.empty()) valq.clear();

        for (int num : nums)
        {
            add(num);
        }
    }

    int showFirstUnique()
    {
        if (valq.empty()) return -1;
        return valq.front();
    }

    void add(int val)
    {
        if (vals.count(val))
        {
            if (vals[val] == valq.end()) return;
            valq.erase(vals[val]);
            vals[val] = valq.end();
        }
        else
        {
            valq.push_back(val);
            vals[val] = --(valq.end());
        }
    }
};

int main(void)
{

	return 0;
}