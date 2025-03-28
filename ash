#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


Node* createCircularList(int n) {
    Node *head = nullptr, *temp = nullptr;
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i) {
        Node* newNode = new Node;
        cin >> newNode->data;
        newNode->next = nullptr;
        
        if (!head) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    
    if (temp != nullptr)
        temp->next = head;
    return head;
}

int findDistance(Node* head, int start, int end) {
    if (!head) return -1;
    
    Node* temp = head;
    int distance = 0;
    do {
        if (startFound && !endFound) {
            distance++;
        }
        if (temp->data == start) {
            startFound = true;
        }
        if (startFound && temp->data == end) {
            endFound = true;
        }
        temp = temp->next;
    } while (!startFound || !endFound);
    
    return distance;
}

bool isElementPresent(Node* head, int element) {
    if (!head) return false;
    
    Node* temp = head;
    
    do {
        if (temp->data == element) {
            return true;
        }
        temp = temp->next;
    } while (temp != head);
    
    return false;
}

int main() {
    int n, startElement, endElement;
    
    cout << "Enter the number of elements: ";
    cin >> n;
    
    Node* head = createCircularList(n);
    
    cout << "Enter two elements: ";
    cin >> startElement >> endElement;
    
    bool firstPresent = isElementPresent(head, startElement);
    bool secondPresent = isElementPresent(head, endElement);
    
    if (firstPresent && secondPresent) {
        int distance = findDistance(head, startElement, endElement);
        cout << "The distance between " << startElement << " and " << endElement << " is " << distance << "." << endl;
    } else {
        cout << "One or both of the elements do not exist in the list." << endl;
    }
    
    return 0;
}



