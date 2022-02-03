#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
// DP-Method
int arr[35] = {};
int fib(int n)
{
    if(n < 2) return n;
    if(arr[n]) return arr[n];
    arr[n] = fib(n - 1) + fib(n - 2);
    return arr[n];
}
*/

int fib(int n)
{
    if (n < 2) return n;
    int a = 1, b = 1;
    for (int i = 2; i < n; i++)
    {
        b = a + (a = b);
    }
    return b;
}

int main(void)
{

	return 0;
}