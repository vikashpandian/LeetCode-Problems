#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
// Using HashMap
long long wonderfulSubstrings(string word)
{
    long long sum = 0;
    unordered_map<int, int> count;
    unordered_set<char> seen;
    int mask = 0;
    count[0] = 1;

    for (char ch : word)
    {
        mask ^= 1 << (ch - 'a');
        seen.insert(ch);

        for (char s : seen)
        {
            sum += count[mask ^ (1 << (s - 'a'))];
        }
        sum += count[mask]++;
    }

    return sum;
}
*/

long long wonderfulSubstrings(string word)
{
    long long sum = 0;
    int count[1024] = {};
    int mask = 0;
    count[0] = 1;

    for (char& ch : word)
    {
        mask ^= 1 << (ch - 'a');

        for (int i = 0; i < 10; i++)
        {
            sum += count[mask ^ (1 << i)];
        }
        sum += count[mask]++;
    }

    return sum;
}

int main(void)
{

	return 0;
}