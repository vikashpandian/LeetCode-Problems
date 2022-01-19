#include <iostream>
#include <vector>

#define MAX(a,b) (a>b ? a:b)
#define MIN(a,b) (a<b ? a:b)

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                for (int k = i + 1; k < 9; k++)
                    if (board[k][j] == board[i][j])
                        return false;
                for (int k = j + 1; k < 9; k++)
                    if (board[i][k] == board[i][j])
                        return false;
                for (int k = i; k < (i/3 + 1) * 3; k++)
                    for (int l = (j/3)*3; l < (j / 3 + 1) * 3; l++) {
                        if ((k != i || l != j) && board[k][l] == board[i][j])
                            return false;
                    }
            }
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board{
  {'5', '3', '.', '.', '7', '.', '.', '.', '.'}
, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}
, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}
, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}
, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}
, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}
, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}
, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}
, {'.', '.', '.', '.', '8', '.', '.', '7', '9'} };

    cout << isValidSudoku(board);
    return 0;
}

