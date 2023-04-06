#include <iostream>

struct Node {
    int data ;
    Node* next ;
};

Node* head = nullptr ;

void newNodeToEnd(int data) {
    if(head == nullptr) {
        head = new Node() ; // head = (Node*)malloc(sizeof(Node*))
        head->data = data ;
        head->next = nullptr ;
    }
    else {
        Node* current = head ;
        while(current->next != nullptr) {
            current = current->next ;
        }
        // * create new node and add it to the end of the list *
        Node* newNode = new Node() ; // newNode = (Node*)malloc(sizeof(Node*))
        newNode->data = data ;
        newNode->next = nullptr ;
        current->next = newNode ;
        //
    }
}

void addNewToBeginning(int data) {
    Node* newNode = new Node() ;
    newNode->data = data ;
    newNode->next = head ;
    head = newNode ;
}
void newNodeBetween(int i, int data) {
    if (i<=1) {
        if(i==1) {
            // add node to the beginning
            addNewToBeginning(data);
        }
        else {
            std::cout << "Undefined node, " << i << ".node doesn't exist. Only 1, 2, 3... numbers are possible." << std::endl ;
        }
    }
    else {
        if(head == nullptr) {
            Node* newNode = new Node() ;
            newNode->data = data ;
            newNode->next = nullptr ;
        }
        else {
            Node* current = head ;
            // current->next != nullptr && sayesinde list boyutundan aha büyük bir sıra num girilirse en sona eklenecek
            // kod böyle bir girdide liste eklemeyecek şekilde de güncellenebilir.
            for(int j = 0 ; current->next != nullptr && j<i-2 ; j++) { // j<i-2 kısmında zorlandım (j<i-1) !  7.2.2023 sömestr
                current = current->next ;
            } // i.node olmasını istiyorsak bir önceki nodeun pointerına kadar ulaşmamız gerekir
            // bu da eğer 0 dan saymaya başlarsak j<i-2 ,
            // 1 den saymaya başlarsak j<i-1 sınırında olmalı .
            // çünkü ben kendim sayarken 1den saymaya başladım iterasyonu ancak for döngüsünü yazarken
            // 0 - i-1 aralıgıı seklinde yazdım, hata buydu.
            Node* newNode = new Node() ;
            newNode->data = data ;
            newNode->next = current->next ;
            current->next = newNode ;
        }
    }

}

void printList() {
    Node* current = head ;
    std::cout << "List : " ;
    while (current->next != nullptr) {
        std::cout << current->data << " , " ;
        current = current->next ;
    }
    std::cout << current->data ;
}
int main() {
    std::cout << "[...3, -2, -1, 0].node doesn't exist. Only [1, 2, 3, 4...] numbers are possible." << std::endl  ;
    std::cout << std::endl ;

    newNodeToEnd(5);
    newNodeToEnd(4);
    newNodeToEnd(2);
    newNodeToEnd(1);

    newNodeBetween(2,0);
    newNodeBetween(2,99);
    newNodeToEnd(100);
    newNodeBetween(1,2023);

    newNodeBetween(10,2023);

    printList();
    return 0;
}
