#include <iostream>
#include <vector>
#include <string>

#define MAX(a,b) (a>b ? a:b)
#define MIN(a,b) (a<b ? a:b)

using namespace std;

vector<vector<int>> generate(int numRows) {
	vector<vector<int>> output;
	for (int i = 1; i <= numRows; i++) {
		vector<int> curRow(i, 1);
		for (int j = 1; j < i - 1; j++)
			curRow[j] = output.back()[j] + output.back()[j - 1];
		output.push_back(curRow);
	}
	return output;
}

int main() {
	int n;
	while (true) {
		cin >> n;
		auto output = generate(n);
	}

	return 0;
}
