#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string tictactoe(vector<vector<int>>& moves)
{
    int n = moves.size(), rows[3] = {}, cols[3] = {}, diag1 = 0, diag2 = 0, of = 1;
    for (auto& move : moves)
    {
        if ((abs(rows[move[0]] += of) == 3 || abs(cols[move[1]] += of) == 3) ||
            (move[0] == move[1] && abs(diag1 += of) == 3) ||
            (move[0] == 2 - move[1] && abs(diag2 += of) == 3)) return of < 0 ? "B" : "A";
        of *= -1;
    }
    return n < 9 ? "Pending" : "Draw";
}

int main(void)
{

	return 0;
}