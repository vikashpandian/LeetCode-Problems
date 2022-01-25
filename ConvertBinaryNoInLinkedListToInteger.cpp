#include <iostream>
#include <vector>
#include <algorithm>
#include "LinkedList.h"

using namespace std;

int getDecimalValue(ListNode* head)
{
    int res = 0;
    while (head)
    {
        res = (res << 1) + head->val;
        head = head->next;
    }
    return res;
}

int main(void)
{

	return 0;
}