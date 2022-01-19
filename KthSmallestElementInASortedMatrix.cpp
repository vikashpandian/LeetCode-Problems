#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> p;
typedef pair<int, p> pp;

/*
int kthSmallest(vector<vector<int>>& mx, int k) {
    priority_queue<p, vector<p>, greater<p>> minHeap;
    int m = mx.size(), n = mx[0].size();
    for (int i = 0; i < n; i++) minHeap.push({ mx[i][0], i * n });
    for (int cnt = 1; !minHeap.empty(); cnt++) {
        p val = minHeap.top();
        minHeap.pop();
        if (cnt == k) return val.first;
        if (val.second++ % n != n - 1) minHeap.push({ mx[val.second / n][val.second % n],val.second });
    }
    return 0;
}
*/
/*
int kthSmallest(vector<vector<int>>& mx, int k) {
    priority_queue<pp, vector<pp>, greater<pp>> minHeap;
    int m = mx.size(), n = mx[0].size();
    for (int i = 0; i < n; i++) minHeap.push({ mx[i][0],{i,0} });
    for (int cnt = 1; !minHeap.empty(); cnt++) {
        pp val = minHeap.top();
        minHeap.pop();
        if (cnt == k) return val.first;
        if (++val.second.second != n) minHeap.push({ mx[val.second.first][val.second.second],val.second });
    }
    return 0;
}
*/

template <class T>
void minHeapify(vector<T>& minHeap, int pos) {
    if (pos * 2 + 1 >= minHeap.size()) return;
    int l = pos * 2 + 1, r = pos * 2 + 2, s = pos, n = minHeap.size();
    if (minHeap[l] < minHeap[s]) s = l;
    if (r<n && minHeap[r] < minHeap[s]) s = r;
    if (pos != s) {
        swap(minHeap[pos], minHeap[s]);
        minHeapify(minHeap, s);
    }
}

int kthSmallest(vector<vector<int>>& mx, int k) {
    vector<pp> minHeap;
    int m = mx.size(), n = mx[0].size(), res = 0;
    for (int i = 0; i < n; i++) minHeap.push_back({ mx[i][0],{i,0} });
    for (int i = 0; i < k; i++) {
        minHeapify(minHeap, 0);
        res = minHeap[0].first;
        minHeap[0].first = (++(minHeap[0].second.second) < n) ? mx[minHeap[0].second.first][minHeap[0].second.second] : INT_MAX;
    }
    return res;
}

int main() {
    //vector< vector<int>> nums({ {1,2,2},{2,2,2},{3,3,3} });
    //vector< vector<int>> nums({ {1,2,3},{4,5,6},{7,8,9} });
    //vector< vector<int>> nums({ {1,5,9},{10,11,13},{12,13,15} });
    vector< vector<int>> nums({ {1,3,5},{6,7,12},{11,14,14} });
    cout << kthSmallest(nums,6) << endl;

    return 0;
}