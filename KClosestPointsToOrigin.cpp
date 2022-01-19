#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
//Binary-Search Solution
vector<vector<int>> split(vector<double>& distances, vector<int>& remaining, double mid)
{
	vector<int> near, far;
	for (int i : remaining)
	{
		distances[i] <= mid ? near.push_back(i) : far.push_back(i);
	}
	return vector<vector<int>>({ near, far });
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
{
	vector<double> distances;
	vector<int> remaining, closest;
	double low = 0, high = 0;
	int i = 0;
	for (auto& point : points)
	{
		double dist = sqrt(point[0] * point[0] + point[1] * point[1]);
		distances.push_back(dist);
		high = max(high, dist);
		remaining.push_back(i++);
	}

	while (k)
	{
		double mid = low + (high - low) / 2;
		vector<vector<int>> split_res = split(distances, remaining, mid);
		auto& close = split_res[0];
		auto& far = split_res[1];

		if (close.size() > k)
		{
			remaining.swap(close);
			high = mid;
		}
		else
		{
			k -= close.size();
			closest.insert(closest.end(), close.begin(), close.end());
			remaining.swap(far);
			low = mid;
		}
	}

	vector<vector<int>> result;
	for (int i : closest)
	{
		result.push_back(points[i]);
	}
	return result;
}
*/

/* TO-DO: Implement your own version of Quick-Select */
//Quick-Select
vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
{
	nth_element(points.begin(), points.begin() + k - 1, points.end(), [](vector<int>& a, vector<int>& b) { return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1]; });
	return vector<vector<int>>(points.begin(), points.begin() + k);
}

int main(void)
{
	vector<vector<int>> points = { {1,3},{-2,2} };
	auto res = kClosest(points, 1);
	return 0;
}