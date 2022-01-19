#include <iostream>
#include <vector>
#include <string>
#include <set>

#define MAX(a,b) (a>b ? a:b)
#define MIN(a,b) (a<b ? a:b)

using namespace std;

int singleNumber(vector<int>& nums) {
	set<int> memo;
	for (int num : nums) {
		if (memo.find(num) != memo.end())
			memo.erase(num);
		else
			memo.insert(num);
	}
	return *memo.begin();
}

int main() {
	vector<int> nums = { -336,513,-560,-481,-174,101,-997,40,-527,-784,-283,-336,513,-560,-481,-174,101,-997,40,-527,-784,-283,354 };
	cout << singleNumber(nums);
	return 0;
}
