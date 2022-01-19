#include <iostream>

using namespace std;

/*
int kthFactor(int n, int k)
{
    int i = 1;
    for (; i * i <= n; i++)
    {
        if (!(n % i) && !--k)
        {
            return i;
        }
    }
    for (i -= 1; i >= 1; i--)
    {
        if (i * i != n && !(n % i) && !--k)
        {
            return n / i;
        }
    }
    return -1;
}
*/

int kthFactor(int n, int k)
{
    for (int i = 1; i * i < n; i++)
    {
        if (!(n % i) && !--k)
        {
            return i;
        }
    }
    for (int i = sqrt(n); i >= 1; i--)
    {
        if (!(n % i) && !--k)
        {
            return n / i;
        }
    }
    return -1;
}

int main(void)
{

    return 0;
}