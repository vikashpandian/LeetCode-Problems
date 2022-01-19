#include <iostream>
#include <vector>

#define MAX(a,b) (a>b ? a:b)
#define MIN(a,b) (a<b ? a:b)

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode head(-1);
    ListNode* tail = &head;
    while (l1 && l2) {
        ListNode *&temp = l1->val <= l2->val ? l1 : l2;
        tail = tail->next = temp;
        temp = temp->next;
    }
    tail->next = l1 ? l1 : l2;
    return head.next;
}

int main() {
    ListNode* A = new ListNode(5, new ListNode(8, new ListNode(19)));
    ListNode* B = new ListNode(0, new ListNode(6, new ListNode(25)));

    ListNode* out = mergeTwoLists(A, B);
    while (out) {
        cout << out->val << "\t";
        out = out->next;
    }
	return 0;
}
