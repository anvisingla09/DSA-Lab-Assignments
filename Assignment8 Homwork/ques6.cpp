#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0 && heap[(index-1)/2] < heap[index]) {
            swap(heap[(index-1)/2], heap[index]);
            index = (index-1)/2;
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        int largest = index;
        int left = 2*index + 1;
        int right = 2*index + 2;

        if (left < size && heap[left] > heap[largest])
            largest = left;
        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size()-1);
    }

    void remove() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int getTop() {
        if (heap.empty()) return -1;
        return heap[0];
    }

    bool isEmpty() {
        return heap.empty();
    }
};

int main() {
    PriorityQueue pq;
    pq.insert(30);
    pq.insert(50);
    pq.insert(20);
    pq.insert(40);

    cout << "Top element (highest priority): " << pq.getTop() << endl;
    pq.remove();
    cout << "After removing top, new top: " << pq.getTop() << endl;

    return 0;
}
