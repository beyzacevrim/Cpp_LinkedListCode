#include <iostream>

struct Node {
    int data;
    Node *next;
};

Node *head = nullptr;

void newNodeEnd(int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
    } else {
        Node *current = head;
        while (current->next != head) { // find the last node
            current = current->next;
        }
        current->next = newNode; // add the new node to the end of the list
        newNode->next = head; // make the new node the last node, by pointing to the head
    }
}

void printForward() {
    Node *current = head;
    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != head);// at the end current points to the first node ( is the last pointer )

    std::cout << std::endl;
}

int main() {
    for (int i = 0; i <= 10; i++) {
        newNodeEnd(i);
    }
    printForward();
    return 0;
}

