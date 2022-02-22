#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

pair<int, int> getPos(int pos, int n) 
{
    pos--;
    int x = n - 1 - pos / n;
    int y = pos % n;
    y = (x + (n & 1 ? 1 : 0)) & 1 ? y : n - 1 - y;
    return { x, y };
}

int snakesAndLadders(vector<vector<int>>& board) 
{
    int moves = 0, n = board.size(), gridsz = n * n;
    queue<int> q;
    q.push(1);
    /*
    bool visited[gridsz + 1];
    fill_n(visited, gridsz + 1, false);
    */
    vector<bool> visited(gridsz + 1);
    visited[1] = true;
    while (!q.empty()) 
    {
        int sz = q.size();
        while (sz--) 
        {
            int pos = q.front();
            q.pop();
            int maxpos = 0;
            for (int i = 1; i <= 6; i++) 
            {
                if (visited[pos + i]) continue;
                if (pos + i == gridsz) return moves + 1;

                auto val = getPos(pos + i, n);
                int topos = board[val.first][val.second];

                if (topos == -1) 
                {
                    maxpos = pos + i;
                }
                else if (!visited[topos]) 
                {
                    if (topos == gridsz) return moves + 1;
                    q.push(topos);
                    visited[pos + i] = true;
                }
            }
            if (maxpos)
            {
                q.push(maxpos);
                visited[maxpos] = true;
            }
        }
        moves++;
    }
    return -1;
}

int main(void)
{

	return 0;
}