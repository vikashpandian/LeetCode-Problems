#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Sea 
{
public:
    //Sample-Implementation for a specific Input
    bool hasShips(vector<int> r, vector<int> l)
    {
        return (l[0] == l[1] && r[0] == r[1]);
    }
};

int countShipsHelper(Sea& sea, vector<int> r, vector<int> l)
{
    if (l[0] > r[0] || l[1] > r[1]) return 0;
    bool val = sea.hasShips(r, l);
    if (!val) return 0;
    if (val && l == r) return 1;

    int lx = l[0], ly = l[1], rx = r[0], ry = r[1];
    int mx = (lx + rx) / 2, my = (ly + ry) / 2;
    int res = countShipsHelper(sea, { mx, my }, l)
        + countShipsHelper(sea, r, { mx + 1, my + 1 })
        + countShipsHelper(sea, { rx, my }, { mx + 1, ly })
        + countShipsHelper(sea, { mx, ry }, { lx, my + 1 });
    return res;
}

int countShips(Sea sea, vector<int> r, vector<int> l)
{
    return countShipsHelper(sea, r, l);
}

int main(void)
{
    Sea sea;
    cout << countShips(sea, { 4,4 }, { 0,0 });
	return 0;
}