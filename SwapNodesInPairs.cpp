#include <iostream>
#include "LinkedList.h"

using namespace std;

ListNode* swapPairs(ListNode* head) {
    ListNode **cursor = &head, *a, *b;
    while ((a = *cursor) && (b = a->next)) {
        a->next = b->next;
        b->next = a;
        *cursor = b;
        cursor = &(a->next);
    }
    return head;
}

int main() {
    ListNode* A = new ListNode(5, new ListNode(8, new ListNode(19)));
    ListNode* out = swapPairs(A);
    while (out) {
        cout << out->val << "\t";
        out = out->next;
    }
    return 0;
}