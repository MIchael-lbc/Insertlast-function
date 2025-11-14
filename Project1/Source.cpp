#include <stdio.h>
#include <iostream>
using namespace std;

//========================================
// Node structure
//========================================
struct Node {
    int data;
    Node* next;

    Node(int d = 0) {
        data = d;
        next = nullptr;
    }
};

//========================================
// Linked List Class
//========================================
class LinkedList {
    Node* header;

public:
    LinkedList() { header = nullptr; }
    bool IsEmpty() { return header == nullptr; }
    // (1) Insert at end
    void InsertLast(int data) {
        if (header == nullptr) {
            header = new Node(data);
            return;
        }
        Node* it = header;
        while (it->next != nullptr)
            it = it->next;
        it->next = new Node(data);
    }
    // (4) Print list
    void PrintList() {
        Node* it = header;
        while (it != nullptr) {
            printf("%d -> ", it->data);
            it = it->next;
        }
        printf("NULL\n");
    }

    // (2) Insert at beginning
    void InsertFirst(int data) {
        Node* temp = new Node(data);
        temp->next = header;
        header = temp;
    }

    // (16) Reverse (new list)
    LinkedList* Reverse() {
        LinkedList* rev = new LinkedList();
        Node* it = header;
        while (it != nullptr) {
            rev->InsertFirst(it->data);
            it = it->next;
        }
        return rev;
    }



};




//
//========================================
// MAIN FUNCTION
//========================================
int main() {
    LinkedList list;
    printf("===== INSERTION TESTS =====\n");
    list.InsertLast(10);
    list.InsertLast(20);
    list.InsertLast(5);
    list.InsertLast(7);
    list.PrintList();
    printf("\n===== REVERSE TEST =====\n");
    LinkedList* rev = list.Reverse();
    printf("Reversed (new): "); rev->PrintList();

    delete rev;
    return 0;
}