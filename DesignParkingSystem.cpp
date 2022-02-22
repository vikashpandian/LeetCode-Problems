#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class ParkingSystem {
public:
    int slots[3];
    ParkingSystem(int b, int m, int s)
    {
        slots[0] = b;
        slots[1] = m;
        slots[2] = s;
    }

    bool addCar(int t)
    {
        /*
        if(slots[t - 1])
        {
            slots[t - 1]--;
            return true;
        }
        return false;
        */
        return slots[t - 1]-- > 0;
    }
};

int main(void)
{

	return 0;
}