// Created by Arseniy Arsentyew <programpro.ars@gmail.com>
// Sharing with the MIT license

// class DynamicArray:
//     size - count of elements
//     capacity - count of memory
//     current - pointer to a current array
//
//     get(i) - returns value of (i)th element
//     set(i, val) - sets (val) to (i)th element
//     pushBack(val) - adds (val) to the ending
//     remove(i) - removes (i)th element
//     getSize() - returns count of elements
//     print() - prints dynamic array

#include <bits\stdc++.h>

using namespace std;

// DynamicArray realisation
class DynamicArray {
    public: 
        int size;
        int capacity;
        int* current;

        DynamicArray() {
            size = 0;
            capacity = 2;
            current = new int[capacity];
        }

        int get(int i) {
            if (i >= size) {
                cout << "ERROR: incorrect index\n";
                return -1;
            }
            return current[i];
        }

        void set(int i, int val) {
            if (i >= size) {
                cout << "ERROR: incorrect index\n";
            }   
            current[i] = val;         
        }

        void pushBack(int val) {
            if (size == capacity) {
                int* newArr = new int[2 * capacity];
                for (int i = 0; i < size; i++) {
                    newArr[i] = current[i];
                }
                delete current;
                current = newArr;
                capacity *= 2;
            }
            current[size] = val;
            size++;
        }

        void remove(int i) {
            if (i >= size) {
                cout << "ERROR: incorrect index";
                return;
            }
            for (int j = i; j < size - 1; j++) {
                current[j] = current[j + 1];
            }
            size--;
        }

        int getSize() {
            return size;
        }

        void print() {
            for (int i = 0; i < size; i++) {
                cout << current[i] << ' ';
            }
            cout << '\n';
        }
};

// Example CLI
int main() {
    string input;
    DynamicArray dynamicArray;
    cout << "Dynamic array has been created\n";
    cout << "-: ";
    while(cin >> input) {
        if (input == "get") {
            int key;
            cin >> key;
            dynamicArray.get(key);
        }
        else if (input == "set") {
            int ind, val;
            cin >> ind >> val;
            dynamicArray.set(ind, val);
            dynamicArray.print();
        }
        else if (input == "pushBack") {
            int val;
            cin >> val;
            dynamicArray.pushBack(val);
            dynamicArray.print();
        }
        else if (input == "remove") {
            int ind;
            cin >> ind;
            dynamicArray.remove(ind);
            dynamicArray.print();
        }   
        else if (input == "getSize") {
            cout << dynamicArray.getSize() << '\n';
        }    
        else {
            break;
        }
        cout << "-: ";
    }
    return 0;
}   