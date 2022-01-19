#include <iostream>
#include <map>

using namespace std;

map <int, char> romanIntMap = { {1,'I'},
                                {5,'V'},
                                {10,'X'},
                                {50,'L'},
                                {100,'C'},
                                {500,'D'},
                                {1000,'M'} };

int getComponent(int n, int factor)
{
    for (int i = 1; i <= factor; i++)
    {
        n *= 10;
    }
    return n;
}

string intToRoman(int num)
{
    int factor = 0;
    string output;
    while (true)
    {
        string currDigit;
        int temp = num % 10;
        num /= 10;
        if (temp)
        {
            if (temp == 4 || temp == 9)
            {
                currDigit.push_back(romanIntMap[getComponent(1, factor)]);
                temp++;
            }
            if (temp == 5 || temp == 10)
            {
                currDigit.push_back(romanIntMap[getComponent(temp, factor)]);
                temp = 0;
            }
            if (temp > 5)
            {
                currDigit.push_back(romanIntMap[getComponent(5, factor)]);
                temp -= 5;
            }
            if (temp)
            {
                currDigit.append(temp, romanIntMap[getComponent(1, factor)]);
            }
            output.insert(0, currDigit);
            if (!num) 
            {
                return output;
            }
        }
        factor++;
    }
}

int main()
{
    while (true)
    {
        int n;
        cin >> n;
        cout << intToRoman(n) << endl;
    }

    return 0;
}
