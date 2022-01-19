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

ListNode* detectCycle(ListNode* head) {
    if (!head) return nullptr;
    ListNode* slow = head, * fast = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
        cout << slow->val << "\t" << fast->val << endl;
        if (fast == slow) {
            ListNode* temp = head;
            while (temp != slow) {
                slow = slow->next;
                temp = temp->next;
            }
            return slow;
        }
    }
    return nullptr;
}

int main() {
    ListNode* A = new ListNode(5, new ListNode(8, new ListNode(0, new ListNode(6, new ListNode(19)))));
    A->next->next->next->next = A->next;
    cout << detectCycle(A)->val;

    return 0;
}
