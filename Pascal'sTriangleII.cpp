#include <iostream>
#include <vector>
#include <string>

#define MAX(a,b) (a>b ? a:b)
#define MIN(a,b) (a<b ? a:b)

using namespace std;

vector<int> getRow(int rowIndex) {
	vector<int> prevRow;
	for (int i = 1; i <= rowIndex + 1; i++) {
		vector<int> curRow(i, 1);
		for (int j = 1; j < i - 1; j++)
			curRow[j] = prevRow[j] + prevRow[j - 1];
		prevRow = curRow;
	}
	return prevRow;
}

int main() {
	int n;
	while (true) {
		cin >> n;
		auto output = getRow(n);
		for (auto a : output) {
			cout << a << '\t';
		}
	}

	return 0;
}
