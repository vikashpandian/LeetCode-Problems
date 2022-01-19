#include <iostream>
#include <vector>

using namespace std;

int diagonalSum(vector<vector<int>>& mat) {
    int res = 0;
    for (int i = 0, j = mat.size() - 1; i < mat.size(); i++, j--)
        res += (mat[i][i] + (i != j ? mat[i][j] : 0));
    return res;
}

int main() {
    //vector< vector<int>> nums({ {1,2,2},{2,2,2},{3,3,3} });
    //vector< vector<int>> nums({ {1,2,3},{4,5,6},{7,8,9} });
    //vector< vector<int>> nums({ {1,5,9},{10,11,13},{12,13,15} });
    vector< vector<int>> nums({ {1,3,5},{6,7,12},{11,14,14} });
    cout << diagonalSum(nums) << endl;

    return 0;
}