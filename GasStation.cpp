#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost) {
	int n(gas.size()), sum(0), subsum(INT_MAX), res(0);
	for (int i = 0; i < n; i++) {
		sum += gas[i] - cost[i];
		if (sum < subsum) subsum = sum, res = i + 1;
	}
	return sum >= 0 ? res % n : -1;
}

int main(void) {
	vector<int> gas = { 1,2,3,4,5 };
	vector<int> cost = { 3,4,5,1,2 };
	cout << canCompleteCircuit(gas, cost);
	return 0;
}