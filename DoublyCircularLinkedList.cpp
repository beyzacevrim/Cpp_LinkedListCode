#include <iostream>

struct Node {
    int data;
    Node *next;
    Node *prev;
};

Node *head = nullptr;

void newNodeEnd(int data) {
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    } else {
        Node *current = head;
        while (current->next != head) { // find the last node
            current = current->next;
        }
        current->next = newNode; // add the new node to the end of the list
        newNode->prev = current; // make the previous last node point to the new node
        newNode->next = head; // make the new node the last node, by pointing to the head
        head->prev = newNode; // make the head's previous pointer point to the new node
    }
}

void printForward() {
    Node *current = head;
    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != head);

    std::cout << std::endl;
}
void printBackwards() {
    Node *current = head->prev; // start at the last node
    do {
        std::cout << current->data << " ";
        current = current->prev;
    } while (current != head->prev); // loop until we get back to the last node

    std::cout << std::endl;
}

int main() {
    for (int i = 0; i <= 10; i++) {
        newNodeEnd(i);
    }
    printForward();
    printBackwards();
    return 0;
}
