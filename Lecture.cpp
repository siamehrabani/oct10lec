#include<iostream>
using namespace std;

template <typename T>
class Node {
public: // defined public to make it easier to access
    T data; //value of the node
    Node* prev; //pointer to the previous node
    Node* next; //pointer to the next node

    Node(T val) : data(val), prev(nullptr), next(nullptr) {}
    // constructor to initialize the node with a value
};    

template <typename T>
class DLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    DLinkedList() : head(nullptr), tail(nullptr) {}
    void insertAtStart(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }   

    void insertAtEnd(T val){
        Node<T>* newNode = new Node<T>(val);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void deleteByValue(T val) {
        Node<T>* current = head;
        while (current != nullptr && current->data != val) {
            current = current->next;
        }
        if (current != nullptr) { // found the node
            if (current == head) {
                head = current->next;
                if (head != nullptr) {
                    head->prev = nullptr;
                }
            }
            else if (current == tail) {
                tail = current->prev;
                if (tail != nullptr) {
                    tail->next = nullptr;
                }
            }     
            else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
        }
    }   

    void printForward() {
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }          

    void printBackward() {
        Node<T>* current = tail;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};

int main() {
    DLinkedList<int> intlist;
    
    intlist.insertAtStart(20);
    intlist.insertAtEnd(30);
    intlist.insertAtStart(10);
    intlist.insertAtEnd(40);

    cout << "Doubly Linked List (Forward): ";
    intlist.printForward();

    cout << "Doubly Linked List (Backward): ";
    intlist.printBackward();

    int d = 30;
    intlist.deleteByValue(d);
    cout << "Deleted " << d << endl;    
    intlist.printForward();

    return 0;
}