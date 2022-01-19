#include <iostream>
#include "LinkedList.h"

using namespace std;

/*
// Own Solution  *Can be optimized
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* t1 = l1;
    ListNode* t2 = l2;
    int carry = 0;

    while (t1 || t2)
    {
        int val = (t1 ? t1->val : 0) + (t2 ? t2->val : 0) + carry;
        if (t1)
            t1->val = val % 10;
        if (t2)
            t2->val = val % 10;
        carry = val / 10;

        if ((t1 && t1->next) || (t2 && t2->next))
        {
            if (t1)
                t1 = t1->next;
            if (t2)
                t2 = t2->next;
        }
        else
        {
            if (t1 && !t1->next)
            {
                if (carry)
                    t1->next = new ListNode(carry);

                return l1;
            }
            else
            {
                if (carry)
                    t2->next = new ListNode(carry);

                return l2;
            }
        }
    }
    return t2;
}
*/

/*
// Iterative Solution - Optimized
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode res(0), *p = &res;
    int excess = 0;
    while (l1 || l2 || excess) {
        if (l1) excess += l1->val, l1 = l1->next;
        if (l2) excess += l2->val, l2 = l2->next;
        p = p->next = new ListNode(excess % 10);
        excess /= 10;
    }
    return res.next;
}
*/

// Recursive Solution
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry) {
    if (!l1 && !l2 && !carry) return nullptr;
    carry += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
    auto node = new ListNode(carry % 10);
    node->next = addTwoNumbers(l1 ? l1->next : nullptr, l2 ? l2->next : nullptr, carry / 10);
    return node;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    return addTwoNumbers(l1, l2, 0);
}

int main()
{
    ListNode* A = new ListNode(5, new ListNode(8, new ListNode(0, new ListNode(6, new ListNode(9)))));
    ListNode* B = new ListNode(5, new ListNode(8, new ListNode(0, new ListNode(6, new ListNode(9)))));
    auto out = addTwoNumbers(A,B);
    while (out) cout << out->val << "\t", out = out->next;
    return 0;
}
