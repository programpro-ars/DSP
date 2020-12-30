// Created by Arseniy Arsentyew <programpro.ars@gmail.com>
// Sharing with the MIT license

// class LinkedList:
//     head - link to the first element
//     tail - link to the last element
//     
//     pushFront(key) - adds (key) to the ending of a list
//     popFront() - deletes the first element
//     pushBack(key) - adds (key) to the beginning of a list
//     popBack() - deletes the last element
//     find(key) - finds (key) in a list
//     erase(key) - deletes node which contains (key)
//     clear() - clears a list
//     print() - prints a list

#include <bits\stdc++.h>

using namespace std;

// Structure of one node
struct Node {
    int data;
    struct Node* next;
};

// Linked list realisation
class LinkedList {
    public: 
        Node* head;
        Node* tail;

        LinkedList() {
            head = NULL;
            tail = NULL;
        }

        void pushFront(int key) {
            Node* newNode = new Node;
            newNode->data = key;
            newNode->next = head;
            head = newNode;
            if (tail == NULL) {
                tail = head;
            }
        }

        void popFront() {
            if (head == NULL) {
                cout << "ERROR: list is empty\n";
                return;
            }
            Node* toDelete = new Node;
            toDelete = head;
            head = head->next;
            delete toDelete;
            if (head == NULL) {
                tail = NULL;
            }
        }
        
        void pushBack(int key) {
            Node* newNode = new Node;
            newNode->data = key;
            newNode->next = NULL;
            if (tail == NULL) {
                head = newNode;
                tail = newNode;
            }   
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        void popBack() {
            if (head == NULL) {
                cout << "ERROR: list is empty\n";
                return;
            }
            if (head == tail) {
                delete head;
                head = NULL;
                tail = NULL;
            }
            else {
                Node* pop = head;
                while (pop->next->next != NULL) {
                    pop = pop->next;
                }
                delete pop->next;
                pop->next = NULL;
                tail = pop;
            }
        }

        Node* find(int key) {
            Node *currentNode = new Node;
            currentNode = head;
            if (currentNode == NULL) {
                cout << "ERROR: list is empty\n";
                return (Node*)NULL;
            }
            while (currentNode != NULL) {
                if (currentNode->data == key) {
                    return currentNode;
                }
                currentNode = currentNode->next;
            }
            cout << "ERROR: list doesn\'t contain the key\n";
            return (Node*)NULL;
        }

        void erase(int key) {
            if (head == NULL) {
                cout << "ERROR: list is empty\n";
                return;
            }
            if (head->data == key) {
                delete head;
                head = NULL;
                tail = NULL;
                cout << key << " was deleted\n";
                return;
            }
            Node* currentNode = new Node;
            Node* previousNode = new Node;
            currentNode = head;
            while (currentNode != NULL) {
                if (currentNode->data == key) {
                    if (currentNode->next == NULL) {
                        tail = previousNode;
                    }
                    previousNode->next = currentNode->next;
                    delete currentNode;
                    cout << key << " was deleted\n";
                    return;
                }
                previousNode = currentNode;
                currentNode = currentNode->next;
            }
            cout << "ERROR: list doesn\'t contain " << key;
        }

        void clear() {
            head = NULL;
            tail = NULL;
        }

        void print() {
            Node *currentNode = new Node;
            currentNode = head;
            if (currentNode == NULL) {
                cout << "The linked list is empty\n";
                return;
            }
            while (currentNode != NULL) {
                cout << currentNode->data << ' ';
                currentNode = currentNode->next;
            }
            cout << '\n';
        }
};

// Example CLI
int main() {
    string input;
    LinkedList list;
    cout << "Linked list has been created\n";
    cout << "-: ";
    while(cin >> input) {
        if (input == "pushFront") {
            int key;
            cin >> key;
            list.pushFront(key);
            list.print();
        }
        else if (input == "popFront") {
            list.popFront();
            list.print();
        }
        else if (input == "popBack") {
            list.popBack();
            list.print();
        }
        else if (input == "pushBack") {
            int key;
            cin >> key;
            list.pushBack(key);
            list.print();
        }
        else if (input == "erase") {
            int key;
            cin >> key;
            list.erase(key);
            list.print();
        }
        else if (input == "find") {
            int key;
            cin >> key;
            Node* result = new Node;
            result = list.find(key);
            cout << &result << '\n';
        }
        else if (input == "clear") {
            list.clear();
            cout << "List has been cleaned\n";
        }        
        else {
            break;
        }
        cout << "-: ";
    }
    return 0;
}   