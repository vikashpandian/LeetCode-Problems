#include <iostream>
#include <vector>
#include "LinkedList.h"

using namespace std;

ListNode* deleteDuplicates(ListNode* head) {
    ListNode** cursor = &head;
    while (*cursor) {
        ListNode** trace = cursor;
        while ((*trace)->next && (*trace)->next->val == (*cursor)->val)
            trace = &(*trace)->next;
        if (trace != cursor) *cursor = (*trace)->next;
        else cursor = &(*cursor)->next;
    }
    return head;
}

int main() {
    ListNode* A = nullptr;
    //ListNode* A = new ListNode(5, new ListNode(5, new ListNode(6, new ListNode(6, new ListNode(9, new ListNode(9, new ListNode(11)))))));

    //deleteDuplicates(A);

    ListNode* out = deleteDuplicates(A);

    while (out) {
        cout << out->val << "\t";
        out = out->next;
    }

    return 0;
}
