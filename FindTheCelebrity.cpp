#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool knows(int a, int b)
{
    // Just a sample implementation for the api and this will not work
    return rand() % 2;
}

int findCelebrity(int n)
{
    int person = 0;
    for (int i = 1; i < n; i++)
    {
        if (knows(person, i)) person = i;
    }
    for (int i = 0; i < n; i++)
    {
        if (person != i && (!knows(i, person) || knows(person, i))) return -1;
    }
    return person;
}

int main(void)
{

	return 0;
}