#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
    Node(int value) {
        key = value;
        left = right = NULL;
        height = 1;
    }
};

class AVLTree {
private:
    Node* head;
    int height(Node* node) {
        return node ? node->height : 0;
    }
    int getBalance(Node* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }
    Node* insert(Node* node, int key) {
        if (!node) return new Node(key);
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;
        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);
            
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);
            
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left)
            current = current->left;

        return current;
    }
    void inOrder(Node* head) {
        if (head) {
            inOrder(head->left);
            cout << head->key << " ";
            inOrder(head->right);
        }
    }

public:
    AVLTree() : head(nullptr) {}
    void insert(int key) {
        head = insert(head, key);
    }
    void inOrder() {
        inOrder(head);
        cout << endl;
    }
};
int main() {
    AVLTree tree;
    int choice, key;

    cout << "1. Insert" << endl;
    cout << "2. In-order Traversal" << endl;
    cout << "3. Exit" << endl;
    while (true) {
    	cout << "Enter your choice: ";
    	cin >> choice;
        switch (choice) {
            case 1:
            	while (true) {
            		cin >> key;
            		if (key < 0) break;
            		tree.insert(key);
            	}
                break;
            case 2:
                cout << "In-order traversal of the AVL tree: ";
                tree.inOrder();
                break;
            case 3:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}

/*

    Node* deleteNode(Node* head, int key) {
        if (!head) return head;

        if (key < head->key)
            head->left = deleteNode(head->left, key);
        else if (key > head->key)
            head->right = deleteNode(head->right, key);
        else {
            if ((!head->left) || (!head->right)) {
                Node* temp = head->left ? head->left : head->right;
                if (!temp) {
                    temp = head;
                    head = nullptr;
                } else
                    *head = *temp; 
                delete temp;
            } else {
                Node* temp = minValueNode(head->right);
                head->key = temp->key;
                head->right = deleteNode(head->right, temp->key);
            }
        }
        if (!head) return head;
        head->height = 1 + max(height(head->left), height(head->right));
        int balance = getBalance(head);
        if (balance > 1 && getBalance(head->left) >= 0)
            return rightRotate(head);
        if (balance > 1 && getBalance(head->left) < 0) {
            head->left = leftRotate(head->left);
            return rightRotate(head);
        }
        if (balance < -1 && getBalance(head->right) <= 0)
            return leftRotate(head);
        if (balance < -1 && getBalance(head->right) > 0) {
            head->right = rightRotate(head->right);
            return leftRotate(head);
        }

        return head;
    }
*/
