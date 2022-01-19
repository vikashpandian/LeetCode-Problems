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

void deleteNode(ListNode* node) {
    ListNode* next = node->next;
    *node = *node->next;
    delete next;
}

int main() {
    ListNode* A = new ListNode(5, new ListNode(8, new ListNode(19, new ListNode(5, new ListNode(8, new ListNode(7))))));
    ListNode* B = new ListNode(0, new ListNode(6, new ListNode(25)));
    ListNode* C = new ListNode(0);

    deleteNode(A->next->next);

    ListNode* out = A;
    while (out) {
        cout << out->val << "\t";
        out = out->next;
    }

    return 0;
}
