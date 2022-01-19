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

bool hasCycle(ListNode* head) {
    if (!head) return false;
    ListNode* slow = head, * fast = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) return true;
    }
    return false;
}

int main() {
    ListNode* A = new ListNode(5, new ListNode(8, new ListNode(0, new ListNode(6, new ListNode(19)))));
    A->next->next->next = A;
    cout << hasCycle(A);

    return 0;
}
