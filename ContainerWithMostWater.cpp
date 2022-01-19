#include <iostream>
#include <vector>

#define MAX(a,b) (a>b ? a:b)
#define MIN(a,b) (a<b ? a:b)

using namespace std;

int maxArea(vector<int>& height) {
	int p1 = 0;
	int p2 = height.size() - 1;
	int gap;
	int out;

	while (true) {
		gap = p2 - p1;
		out = MIN(p1, p2) * gap;
		int diff = height[p1] - height[p2];

		if (gap == 2) {
			return out;
		}

		if (diff > 0) {
			for (int i = p2 - 1; i > p1; i--) {
				if ((MAX(height[i], height[p1]) * (i - p1)) >= (height[p2] * gap)) {
					p2 = i;
					if (height[p2] >= height[p1]) {
						break;
					}
				}
			}
		}
		else if (diff < 0) {
			for (int i = p1 + 1; i < p2; i++) {
				if ((MAX(height[i], height[p2]) * (p2 - i)) >= (height[p1] * gap)) {
					p1 = i;
					if (height[p1] >= height[p2]) {
						break;
					}
				}
			}
		}
		else {

		}
	}

	return 0;
}

int main()
{
	vector<int> height = {3,3,9,4};

	maxArea(height);

    return 0;
}
