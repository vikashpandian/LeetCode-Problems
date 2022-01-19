#include <iostream>
#include <vector>

#define MAX(a,b) (a>b ? a:b)
#define MIN(a,b) (a<b ? a:b)

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    int count = 0;
    ListNode* temp = head;
    ListNode* prev = nullptr;
    ListNode* curr = nullptr;
    while (temp->next) {
        prev = curr;
        curr = temp;
        for (count = 0; count < n && temp->next; count++)
            temp = temp->next;
    }
    ListNode* toRem = nullptr;
    if (!count)
        return nullptr;
    if (count == n)
        toRem = curr;
    else {
        if (!prev)
            return curr->next;
        while (count--)
            prev = prev->next;
        toRem = prev;
    }
    toRem->next = (toRem->next->next ? toRem->next->next : nullptr);
    return head;
}

int main() {
    //ListNode* A = new ListNode(5, new ListNode(8, new ListNode(19, new ListNode(1, new ListNode(7, new ListNode(99, new ListNode(109)))))));
    //ListNode* A = new ListNode(5, new ListNode(8, new ListNode(7, new ListNode(6))));
    ListNode* A = new ListNode(5, new ListNode(8));
    ListNode* out = removeNthFromEnd(A, 2);
    while (out) {
        cout << out->val << "\t";
        out = out->next;
    }
    return 0;
}
