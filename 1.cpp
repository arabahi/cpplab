#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	Node* parent;
	Node(int val) {
		data = val;
		left = right = parent = NULL;
	}
};

class Tree {
	Node* head;
	public:
		Tree() {
			head = NULL;
		}
		void insert(int val) {
			Node* newNode = new Node(val);
			if (head == NULL) {
				head = newNode;
				return;
			}
			Node *prev = NULL, *cur = head;
			while (cur != NULL) {
				prev = cur;
				if (val > cur->data)
					cur = cur->right;
				else
					cur = cur->left;
			}
			newNode->parent = prev;
			if (val > prev->data) {
				prev->right = newNode;
			} else {
				prev->left = newNode;
			}
		}
		Node* getHead() {
			return head;
		}
		void inorder(Node* node) {
			if (node == NULL) return;
			inorder(node->left);
			cout << node->data << " ";
			inorder(node->right);
		}
		void preorder(Node* node) {
			if (node == NULL) return;
			cout << node->data << " ";
			preorder(node->left);
			preorder(node->right);
		}
		void postorder(Node* node) {
			if (node == NULL) return;
			postorder(node->left);
			postorder(node->right);
			cout << node->data << " ";
		}
};

void showChoices() {
	cout << "Choices:" << endl;
	cout << "1. Insert" << endl;
	cout << "2. Inorder" << endl;
	cout << "3. Preorder" << endl;
	cout << "4. Postorder" << endl;
}

int main() {
	Tree tree;
	showChoices();
	bool flag = true;
	while (flag) {
		int choice;
		cout << "Enter Choice: ";
		cin >> choice;
		switch (choice) {
			case 1:
				int temp;
				cout << "Enter value: ";
				cin >> temp;
				tree.insert(temp);
				break;
			case 2:
				tree.inorder(tree.getHead());
				cout << endl;
				break;
			case 3:
				tree.preorder(tree.getHead());
				cout << endl;
				break;
			case 4:
				tree.postorder(tree.getHead());
				cout << endl;
				break;
			default:
				flag = false;
				break;
		}
	}
	return 0;
}
