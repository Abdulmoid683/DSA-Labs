#include <iostream>
using namespace std;

class myQueue {
private:
    int arr[100];
    int frontIndex;
    int rearIndex;
    int currentSize;

public:
    myQueue() {
        frontIndex = 0;
        rearIndex = -1;
        currentSize = 0;
    }

    bool isEmpty() {
        return currentSize == 0;
    }

    void enqueue(int value) {
        if (currentSize == 100) {
            cout << "Queue is full!" << endl;
            return;
        }

        rearIndex = (rearIndex + 1) % 100;
        arr[rearIndex] = value;
        currentSize++;
    }

    int dequeue() {
        if (isEmpty()) {
            return -1;
        }

        int value = arr[frontIndex];
        frontIndex = (frontIndex + 1) % 100;
        currentSize--;

        return value;
    }

    int front() {
        if (isEmpty()) {
            return -1;
        }

        return arr[frontIndex];
    }

    int size() {
        return currentSize;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        for (int i = 0; i < currentSize; i++) {
            int index = (frontIndex + i) % 100;
            cout << arr[index] << " ";
        }

        cout << endl;
    }
};
void reverseFirstK(myQueue& q, int k) {
    if (k <= 1 || q.isEmpty()) {
        return;
    }

    if (k > q.size()) {
        k = q.size();
    }

    int stack[100];
    int top = -1;
    for (int i = 0; i < k; i++) {
        stack[++top] = q.dequeue();
    }
    while (top != -1) {
        q.enqueue(stack[top--]);
    }

    int remaining = q.size() - k;

    for (int i = 0; i < remaining; i++) {
        q.enqueue(q.dequeue());
    }
}

int main3() {
    myQueue q;
    int n, value, k;

    cout << "Enter number of queue elements: ";
    cin >> n;

    if (n < 0 || n > 100) {
        cout << "Invalid queue size!" << endl;
        return 0;
    }

    cout << "Enter queue elements:" << endl;

    for (int i = 0; i < n; i++) {
        cin >> value;
        q.enqueue(value);
    }

    cout << "Original Queue: ";
    q.display();

    cout << "Enter K: ";
    cin >> k;

    reverseFirstK(q, k);

    cout << "Queue after reversing first K elements: ";
    q.display();

    return 0;
}
