#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

// DFS Solution
void killPS(unordered_map<int, vector<int>>& ps, int id, vector<int>& res)
{
    res.push_back(id);
    if (!ps.count(id)) return;
    for (int ch : ps[id])
    {
        killPS(ps, ch, res);
    }
}

vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill)
{
    unordered_map<int, vector<int>> ps;

    for (int i = 0; i < ppid.size(); i++)
    {
        ps[ppid[i]].push_back(pid[i]);
    }

    vector<int> res;
    killPS(ps, kill, res);

    return res;
}

/*
// BFS Solution
vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill)
{
    unordered_map<int, vector<int>> ps;
    for (int i = 0; i < ppid.size(); i++)
    {
        ps[ppid[i]].push_back(pid[i]);
    }
    queue<int> q;
    q.push(kill);
    vector<int> res;
    while (!q.empty())
    {
        int to_kill = q.front();
        res.push_back(to_kill);
        q.pop();
        auto& ps_list = ps[to_kill];
        for (int ch : ps_list) q.push(ch);
    }
    return res;
}
*/

int main(void)
{

	return 0;
}