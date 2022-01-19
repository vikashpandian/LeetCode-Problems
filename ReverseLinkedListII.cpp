#include <iostream>
#include <vector>
#include "linkedList.h"

using namespace std;

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (left == right) return head;
    ListNode* cursor = head, * prev = nullptr, * l = nullptr, * next = nullptr;
    for (int pos = 1; pos <= right; pos++) {
        if (pos == left) l = prev;
        prev = cursor;
        cursor = cursor->next;
        if (pos >= left) prev->next = next,next = prev;
    }
    ListNode* &temp = l ? l->next : head;
    temp->next = cursor, temp = prev;
    return head;
}

int main(void) {
    //ListNode* A = nullptr;
    ListNode* A = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6, new ListNode(7)))))));
    ListNode* out = reverseBetween(A, 1, 7);
    while (out) {
        cout << out->val << "\t";
        out = out->next;
    }
    return 0;
}
