// Created by Arseniy Arsentyew <programpro.ars@gmail.com>
// Sharing with the MIT license

// class Stack:
//     head - link to the toppest element
//
//     push(key) - adds (key) to the stack
//     pop() - deletes and returnes the toppest element
//     top() - returnes the toppest element
//     isEmpty() - returnes true if stack is empty
//     print() - prints a stack

#include <bits\stdc++.h>

using namespace std;

// Structure of one node
struct Node {
    int data;
    struct Node* next;
};

// Stack realisation
class Stack {
    public: 
        Node* head;

        Stack() {
            head = NULL;
        }

        void push(int key) {
            Node* newNode = new Node;
            newNode->data = key;
            newNode->next = head;
            head = newNode;
        }

        int pop() {
            if (head == NULL) {
                cout << "ERROR: stack is empty\n";
                return -1;
            }
            Node* toDelete = new Node;
            toDelete = head;
            int toReturn = toDelete->data;
            head = head->next;
            delete toDelete;
            return toReturn;
        }

        int top() {
            return head->data;
        }

        bool isEmpty(){
            if (head == NULL) {
                return true;
            }
            return false;
        }

        void print() {
            Node *currentNode = new Node;
            currentNode = head;
            if (currentNode == NULL) {
                cout << "The stack is empty\n";
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
    Stack stack;
    cout << "Stack has been created\n";
    cout << "-: ";
    while(cin >> input) {
        if (input == "push") {
            int key;
            cin >> key;
            stack.push(key);
            stack.print();
        }
        else if (input == "top") {
            cout << stack.top() << '\n';
        }
        else if (input == "pop") {
            cout << stack.pop() << '\n';
            stack.print();
        }
        else if (input == "isEmpty") {
            bool state = stack.isEmpty();
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