#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/*ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (!headA || !headB) return nullptr;
    ListNode* cursorA = headA, * cursorB = headB;
    int countA = 0, countB = 0;
    while (cursorA) {
        cursorA = cursorA->next;
        countA++;
    }
    while (cursorB) {
        cursorB = cursorB->next;
        countB++;
    }
    if (cursorA == cursorB) {
        cursorA = headA, cursorB = headB;
        if (countA > countB) {
            for (int i = 0; i < countA - countB; i++)
                cursorA = cursorA->next;
        }
        else {
            for (int i = 0; i < countB - countA; i++)
                cursorB = cursorB->next;
        }
        while (cursorA != cursorB) {
            cursorA = cursorA->next;
            cursorB = cursorB->next;
        }
        return cursorA;
    }

    return nullptr;
}*/

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (!headA || !headB) return nullptr;
    ListNode* cursor1 = headA, * cursor2 = headB;
    while (cursor1 != cursor2) {
        cursor1 = cursor1 ? cursor1->next : headB;
        cursor2 = cursor2 ? cursor2->next : headA;
    }
    return cursor1;
}

int main() {
    ListNode* A = new ListNode(5, new ListNode(8, new ListNode(0, new ListNode(6, new ListNode(19)))));
    ListNode* B = new ListNode(1, A->next);

    ListNode* op = getIntersectionNode(A, B);
    if (op)
        cout << op->val;
    else
        cout << "zzz";

    return 0;
}
