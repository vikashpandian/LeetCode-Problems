#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
class UnionFind
{
    int* id, * sz;
public:
    UnionFind(const int n)
    {
        id = new int[n]();
        sz = new int[n]();
        for (int i = 0; i < n; i++)
        {
            id[i] = i;
            sz[i] = 1;
        }
    }

    int find(int val)
    {

        int root = val;

        while (root != id[root])
        {
            root = id[root];
        }

        while (val != root)
        {
            int next = id[val];
            id[val] = root;
            val = next;
        }

        return root;
    }

    int unify(const int a, const int b)
    {
        int root1 = find(a);
        int root2 = find(b);
        if (root1 == root2)
        {
            return 0;
        }

        int smaller = sz[root1] < sz[root2] ? root1 : root2;
        int larger = sz[root1] < sz[root2] ? root2 : root1;
        sz[larger] += sz[smaller];
        id[smaller] = larger;
        sz[smaller] = 0;
        return sz[larger];
    }
};

int earliestAcq(vector<vector<int>>& logs, int n)
{
    if (logs.size() < n - 1) return -1;
    sort(logs.begin(), logs.end());
    UnionFind uf(n);
    for (auto& log : logs)
    {
        if (uf.unify(log[1], log[2]) == n)
        {
            return log[0];
        }
    }
    return -1;
}
*/

//int find(int uf[], int num)
int find(vector<int>& uf, int num)
{
    //return (uf[num] < 0) ? num : find(uf, uf[num]);
    if (uf[num] < 0) return num;
    return uf[num] = find(uf, uf[num]);
}

int earliestAcq(vector<vector<int>>& logs, const int n)
{
    if (logs.size() < n - 1) return -1;
    sort(logs.begin(), logs.end());
    vector<int> uf(n, -1);
    //int uf[n];
    //fill_n(uf, n, -1);
    for (auto& log : logs)
    {
        int a, b;
        if ((a = find(uf, log[1])) != (b = find(uf, log[2])))
        {
            int sz = uf[a] + uf[b];
            if (-sz == n) return log[0];
            if (uf[b] < uf[a])
            {
                swap(a, b);
            }
            uf[b] = a;
            uf[a] = sz;
        }
    }
    return -1;
}

int main(void)
{

	return 0;
}