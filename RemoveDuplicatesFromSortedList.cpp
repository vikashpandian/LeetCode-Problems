#include <iostream>
#include <vector>
#include "LinkedList.h"

using namespace std;

ListNode* deleteDuplicates(ListNode* head) {
    ListNode** cursor = &head;
    while (*cursor) {
        while ((*cursor)->next && (*cursor)->next->val == (*cursor)->val)
            (*cursor) = (*cursor)->next;
        cursor = &(*cursor)->next;
    }
    return head;
}

int main() {
    ListNode* A = nullptr;
    //ListNode* A = new ListNode(5, new ListNode(5, new ListNode(6, new ListNode(6, new ListNode(9, new ListNode(9, new ListNode(9)))))));

    deleteDuplicates(A);

    ListNode* out = A;

    while (out) {
        cout << out->val << "\t";
        out = out->next;
    }

    return 0;
}
