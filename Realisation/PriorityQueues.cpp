// Created by Arseniy Arsentyew <programpro.ars@gmail.com>
// Sharing with the MIT license

// class PriorityQueue:
//     heap - link to main array
//     size - count of elements
//     INF - max possible value
//     maxSize - size of a main array
//
//     parent(i) - returns parent of (i)
//     leftChild(i) - returns left child of (i)
//     rightChild(i) - returns right child of (i)
//     siftUp(i) - moves node closer to the root
//     siftDown(i) - moves node further to the root
//     insert(p) - adds (p) to priority queue
//     extractMax() - returns the root element
//     remove(i) - deletes (i)th element
//     changePriority(i, p) - sets (i)th element to (p)
//     print() - prints priority queue

#include <bits\stdc++.h>

using namespace std;

// Priority queue realisation
class PriorityQueue {
    public:
        int* heap;
        int size;
        int INF = 100000;
        int maxSize = 1000;

        PriorityQueue() {
            heap = new int[maxSize];
            for (int i = 0; i < maxSize; i++) {
                heap[i] = -INF;
            }
            size = 0;
        }
         
        int parent(int i) {
            return floor(i / 2.0);
        }

        int leftChild(int i) {
            return 2 * i;
        }

        int rightChild(int i) {
            return 2 * i + 1;
        }

        void siftUp(int i) {
            while (i > 1 && heap[parent(i)] < heap[i]) {
                swap(heap[parent(i)], heap[i]);
                i = parent(i);
            }
        }

        void siftDown(int i) {
            int maxInd = i;
            int left = leftChild(i);
            if (left <= size && heap[left] > heap[maxInd]) {
                maxInd = left;
            }
            int right = rightChild(i);
            if (right <= size and heap[right] > heap[maxInd]) {
                maxInd = right;
            }
            if (i != maxInd) {
                swap(heap[i], heap[maxInd]);
                siftDown(maxInd);
            }
        }

        void insert(int p) {
            size++;
            heap[size] = p;
            siftUp(size);
        }

        int extractMax() {
            int result = heap[1];
            heap[1] = heap[size];
            size--;
            siftDown(1);
            return result;
        }

        void remove(int i) {
            heap[i] = INF;
            siftUp(i);
            extractMax();
        }

        void changePriority(int i, int p) {
            int oldp = heap[i];
            heap[i] = p;
            if (p > oldp) {
                siftUp(i);
            }
            else {
                siftDown(i);
            }
        }

        void print() {
            for (int i = 1; i < size + 1; i++) {
                cout << heap[i] << ' ';
            }
            cout << '\n';
        }
};

// Example CLI
int main() {
    string input;
    PriorityQueue priorityQueue;
    cout << "Priority queue has been created\n";
    cout << "-: ";
    while(cin >> input) {
        if (input == "insert") {
            int val;
            cin >> val;
            priorityQueue.insert(val);
            priorityQueue.print();
        }
        else if (input == "extractMax") {
            cout << priorityQueue.extractMax() << '\n';
            priorityQueue.print();
        }
        else if (input == "remove") {
            int val;
            cin >> val;
            priorityQueue.remove(val);
            priorityQueue.print();
        }   
        else if (input == "changePriority") {
            int ind, newValue;
            cin >> ind >> newValue;
            priorityQueue.changePriority(ind, newValue);
            priorityQueue.print();
        }    
        else {
            break;
        }
        cout << "-: ";
    }
    return 0;
}   