#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*
bool exist(unordered_map<int, unordered_set<int>>& dp, int row, int col, vector<vector<char>>& board, string word)
{
	int m = board.size();
	int n = board[0].size();
	int idx1D = row * n + col;
	int len = word.length();
	if (dp.count(idx1D) && (dp.at(idx1D)).count(len))
	{
		return false;
	}
	if (board[row][col] == word.front())
	{
		if (word.length() == 1)
		{
			return true;
		}
		vector<int> xDir = { 1, -1, 0, 0 };
		vector<int> yDir = { 0, 0, 1, -1 };
		char temp = board[row][col];
		board[row][col] = '0';
		for (int i = 0; i < xDir.size(); i++)
		{
			if ((row + xDir[i] >= 0) && (col + yDir[i] >= 0) && (row + xDir[i] < m) && (col + yDir[i] < n))
			{
				if (exist(dp, row + xDir[i], col + yDir[i], board, word.substr(1, word.length())))
				{
					return true;
				}
			}
		}
		board[row][col] = temp;
	}
	if (dp.find(idx1D) != dp.end())
	{
		dp.at(idx1D).insert(len);
	}
	else
	{
		dp.insert({ idx1D,  { len } });
	}
	return false;
}

bool exist(vector<vector<char>>& board, string word)
{
	unordered_map<int, unordered_set<int>> dp;
	if (!word.empty())
	{
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				if (exist(dp, i, j, board, word))
				{
					return true;
				}
			}
		}
	}
	return false;
}
*/

bool exist(int row, int col, vector<vector<char>>& board, string& word, vector<int>& xDir, vector<int>& yDir, int len)
{
	if (word.length() - len == 0)
	{
		return true;
	}
	if ((row < 0) || (col < 0) || (row >= board.size()) || (col >= board[0].size()) || board[row][col] != word[len])
	{
		return false;
	}
	board[row][col] = '0';
	for (int i = 0; i < xDir.size(); i++)
	{
		if (exist(row + yDir[i], col + xDir[i], board, word, xDir, yDir, len + 1))
		{
			return true;
		}
	}
	board[row][col] = word[len];
	return false;
}

bool exist(vector<vector<char>>& board, string word)
{
	if (!word.empty())
	{
		vector<int> xDir = { 1, -1, 0, 0 };
		vector<int> yDir = { 0, 0, 1, -1 };
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				if (exist(i, j, board, word, xDir, yDir, 0))
				{
					return true;
				}
			}
		}
	}
	return false;
}

int main(void) {
	vector<vector<char>> board { {'A', 'B', 'C', 'E'}, { 'S', 'F', 'E', 'S' }, { 'A', 'D', 'E', 'E' } };
	string word = "ABCESEEEFS";
	cout << exist(board, word);
	return 0;
}