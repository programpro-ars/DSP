// Created by Arseniy Arsentyew <programpro.ars@gmail.com>
// Sharing with the MIT license

// class Queue:
//     head - link to the first element
//     tail - link to the last element
//     
//     enQueue(key) - adds (key) to the queue
//     deQueue() - deletes and returns the last element
//     isEmpty() - returns true if queue is empty
//     print() - prints a queue

#include <bits\stdc++.h>

using namespace std;

// Structure of one node
struct Node {
    int data;
    struct Node* next;
};

// Queue realisation
class Queue {
    public: 
        Node* head;
        Node* tail;

        Queue() {
            head = NULL;
            tail = NULL;
        }

        int deQueue() {
            if (head == NULL) {
                cout << "ERROR: queue is empty\n";
                return -1;
            }
            Node* toDelete = new Node;
            toDelete = head;
            int toReturn = toDelete->data;
            head = head->next;
            delete toDelete;
            if (head == NULL) {
                tail = NULL;
            }
            return toReturn;
        }
        
        void enQueue(int key) {
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

        bool isEmpty(){
            if (head == NULL){
                return true;
            }
            return false;
        }

        void print() {
            Node *currentNode = new Node;
            currentNode = head;
            if (currentNode == NULL) {
                cout << "The queue is empty\n";
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
    Queue queue;
    cout << "Queue has been created\n";
    cout << "-: ";
    while(cin >> input) {
        if (input == "enQueue") {
            int key;
            cin >> key;
            queue.enQueue(key);
            queue.print();
        }
        else if (input == "deQueue") {
            cout << queue.deQueue() << '\n';
            queue.print();
        }
        else if (input == "isEmpty") {
            bool state = queue.isEmpty();
            if (state) {
                cout << "Yes\n";
            }
            else {
                cout << "No\n";
            }
        }      
        else {
            break;
        }
        cout << "-: ";
    }
    return 0;
}   