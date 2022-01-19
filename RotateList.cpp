#include <iostream>
#include <vector>
#include "LinkedList.h"

using namespace std;

ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next || !k) return head;
    ListNode* cursor = head;
    for (int i = 1; i < k; i++) {
        if (cursor->next)
            cursor = cursor->next;
        if (!cursor->next) {
            if (!(k %= ++i)) return head;
            cursor = head, i = 0;
        }
    }
    ListNode* trail = nullptr;
    while (cursor->next) {
        cursor = cursor->next;
        trail = !trail ? head : trail->next;
    }
    cursor->next = head;
    head = trail->next;
    trail->next = nullptr;
    return head;
}

int main() {
    //ListNode* A = nullptr;
    //ListNode* A = new ListNode(5, new ListNode(5, new ListNode(6, new ListNode(6, new ListNode(9, new ListNode(9, new ListNode(11)))))));
    ListNode* A = new ListNode(0, new ListNode(1, new ListNode(2)));

    ListNode* out = rotateRight(A, 6);

    while (out) {
        cout << out->val << "\t";
        out = out->next;
    }

    return 0;
}
