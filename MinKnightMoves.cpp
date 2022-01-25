#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int minKnightMoves(int x, int y)
{
	int dir[9] = { 2,1,-2,1,2,-1,-2,-1,2 };
	bool visited[607][607] = {};
	queue<pair<int, int>> q({ {0,0} });
	//x = abs(x);
	//y = abs(y);
	int moves = 0;
	while (!q.empty())
	{
		int sz = q.size();
		while (sz--)
		{
			auto pos = q.front();
			q.pop();
			if (x == pos.first && y == pos.second)
			{
				return moves;
			}

			for (int i = 0; i < 8; i++)
			{
				int next_x = pos.first + dir[i];
				int next_y = pos.second + dir[i + 1];

				if (!visited[next_x + 302][next_y + 302])
				{
					visited[next_x + 302][next_y + 302] = true;
					q.push({ next_x, next_y });
				}
			}
		}
		moves++;
	}
	return moves;
}

int main(void)
{

	return 0;
}