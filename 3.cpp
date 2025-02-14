#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node*next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

struct Node* inputList() {
    int inp;
    struct Node* head = NULL;
    struct Node* cur = head;
    do {
        cout << "Enter val: ";
        cin >> inp;
        if (inp < 0) break;
        struct Node* node = new struct Node(inp);
        if (head == NULL) {
            head = node;
            cur = head;
        } else {
            cur->next = node;
            cur = cur->next;
        }
    } while (true);
    return head;
}

void showList(struct Node* head) {
    struct Node* cur = head;
    while (cur != NULL) {
        cout << cur->data << "->";
        cur = cur->next;
    }
    cout << "NULL\n";
}

struct Node* deletion(struct Node* head, int pos) {
    struct Node* cur = head;
    int size = 0;
    while (cur != NULL) {
        size++;
        cur = cur->next;
    }
    if (size < pos) {
        cout << "Position is out of limits." << endl;
        return head;
    }

    if (pos == 1) return head->next;

    struct Node* prev = head;

    while (pos > 2) {
        pos--;
        prev = prev->next;
    }
    struct Node* temp = prev->next;
    prev->next = prev->next->next;
    delete temp;
    return head;
}

int main() {
    struct Node *head = inputList();
    cout << endl;
    showList(head);

    int pos = 2;
    head = deletion(head, pos);

    showList(head);
    return 0;
}