#include <iostream>
using namespace std;

class myQueue {
private:
    int* stack1;
    int* stack2;

    int top1;
    int top2;
    int maxSize;

public:
    myQueue(int size = 10) {
        maxSize = size;

        stack1 = new int[maxSize];
        stack2 = new int[maxSize];

        top1 = -1;
        top2 = -1;
    }
    bool isEmpty() {
        return top1 == -1 && top2 == -1;
    }
    void enQueue(int value) {
        if (top1 + top2 + 2 == maxSize) {
            cout << "Queue is full!" << endl;
            return;
        }

        stack1[++top1] = value;

        cout << "Element inserted successfully!" << endl;
    }
    void transfer() {
        while (top1 != -1) {
            stack2[++top2] = stack1[top1--];
        }
    }
    int deQueue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        if (top2 == -1) {
            transfer();
        }

        return stack2[top2--];
    }
    int front() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        if (top2 == -1) {
            transfer();
        }

        return stack2[top2];
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements (Front to Rear):" << endl;

        for (int i = top2; i >= 0; i--) {
            cout << stack2[i] << endl;
        }

        for (int i = 0; i <= top1; i++) {
            cout << stack1[i] << endl;
        }
    }

    ~myQueue() {
        delete[] stack1;
        delete[] stack2;
    }
};

int main2() {
    int size;
    int choice;
    int value;

    cout << "Enter maximum queue size: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid queue size!" << endl;
        return 0;
    }

    myQueue q(size);

    do {
        cout << " QUEUE USING TWO STACKS ";
        cout << "1. EnQueue" << endl;
        cout << "2. DeQueue" << endl;
        cout << "3. Front Element" << endl;
        cout << "4. Display Elements" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enQueue(value);
            break;

        case 2:
            if (!q.isEmpty()) {
                cout << "Removed element: " << q.deQueue() << endl;
            }
            else {
                cout << "Queue is empty!" << endl;
            }
            break;

        case 3:
            if (!q.isEmpty()) {
                cout << "Front element: " << q.front() << endl;
            }
            else {
                cout << "Queue is empty!"<< endl;
            }
            break;

        case 4:
            q.display();
            break;

        case 0:
            cout << "Program ended." << endl;
            break;

        default:
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
