#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*
long long smallestNumber(long long num)
{
    //vector<int> arr;
    int arr[10] = {};
    bool neg = num < 0;
    num = abs(num);
    string s;
    while (num > 0)
    {
        int n = num % 10;
        arr[n]++;
        num /= 10;
    }
    if (!neg)
    {
        s += "0";
        int i = 1;
        for (; i < 10; i++)
        {
            if (arr[i])
            {
                s.append(string(1, i + '0'));
                if (arr[0]) s.append(string(arr[0], '0'));
                arr[i]--;
                break;
            }
        }
        for (; i < 10; i++)
        {
            if (!s.empty())
                if (arr[i]) s.append(string(arr[i], i + '0'));
        }

    }
    else
    {
        s += "-0";
        for (int i = 9; i >= 0; i--)
        {
            if (arr[i]) s.append(string(arr[i], i + '0'));
        }
    }
    return stoll(s);
}
*/

long long smallestNumber(long long num)
{
    bool neg = num < 0;
    num = abs(num);
    string s = to_string(num);
    sort(s.begin(), s.end(), [&](int a, int b) {return (neg ? a > b : a < b); });
    if (!neg) swap(s[0], s[s.find_first_not_of('0')]);
    return stoll(s) * (neg ? -1 : 1);
}

int main(void)
{
    cout << smallestNumber(500004321);
	return 0;
}