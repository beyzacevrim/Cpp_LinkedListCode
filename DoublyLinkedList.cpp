#include <iostream>

struct Node {
    int data ;
    Node* prev ;
    Node* next ;
};

Node* head = nullptr ;

void newNodeEnd (int data) {

    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if(head == nullptr) { // if the list is empty
        head = newNode ;
    }
    else { // if the list isn't empty

        Node* current = head ; // new pointer to traverse the list
        while (current->next != nullptr) { // current points to the last node in the list
            current = current->next ;
        }
        current->next = newNode ;
        newNode->prev = current ;
    }
}

void printForward() {
    Node* current = head ;
    while(current != nullptr) {
        std::cout << current->data << " " ;
        current = current->next ;
    }
    std::cout << std::endl;
}
void printBackwards() {
    Node* current = head ;
    while(current->next != nullptr) { // current points to the last node
        current = current->next ;
    }
    while(current != nullptr) {
        std::cout << current->data << " " ;
        current = current->prev ;
    }
    std::cout << std::endl;
}
int main() {
    for(int i=1 ; i<=10 ; i++) {
        newNodeEnd(i);
    }
    printForward();
    printBackwards();
    return 0;
}

