#include <iostream>
#include <vector>
#include <algorithm>
#include "LinkedList.h"

using namespace std;

ListNode* reverseList(ListNode* head)
{
    if (!head) return head;
    ListNode* prev = nullptr, * node = head;
    while (node)
    {
        ListNode* next = node->next;
        node->next = prev;
        prev = node;
        node = next;
    }
    return prev;
}

int main(void)
{

	return 0;
}