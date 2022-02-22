#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int compareVersion(string ver1, string ver2)
{
    int l1 = ver1.length(), l2 = ver2.length(), i = 0, j = 0;
    while (i < l1 || j < l2)
    {
        int num1 = 0, num2 = 0;
        while (i < l1 && ver1[i] != '.')
        {
            num1 = (num1 * 10) + ver1[i++] - '0';
        }
        while (j < l2 && ver2[j] != '.')
        {
            num2 = (num2 * 10) + ver2[j++] - '0';
        }
        if (num1 < num2) return -1;
        else if (num1 > num2) return 1;
        i++; j++;
    }
    return 0;
}

int main(void)
{

	return 0;
}