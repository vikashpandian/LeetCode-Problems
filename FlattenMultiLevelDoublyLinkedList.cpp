#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node() : val(0), prev(nullptr), next(nullptr), child(nullptr) {}
    Node(int x) : val(x), prev(nullptr), next(nullptr), child(nullptr) {}
    Node(int x, Node* prev, Node* next, Node* child) : val(x), prev(prev), next(next), child(child) {}
};

Node* flatten(Node* head) {
    if (!head) return head;
    Node* cursor = head;
    while (cursor) {
        if (!cursor->child) {
            cursor = cursor->next;
            continue;
        }
        Node* temp = cursor->child;
        while (temp->next) temp = temp->next;
        temp->next = cursor->next;
        if(temp->next) temp->next->prev = temp;
        cursor->next = cursor->child;
        cursor->next->prev = cursor;
        cursor->child = nullptr;
    }
    return head;
}

int main(void) {

    return 0;
}