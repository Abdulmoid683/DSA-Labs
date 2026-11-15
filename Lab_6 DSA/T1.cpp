#include <iostream>
using namespace std;
template <typename T>
class AbstractQueue {
public:
    virtual void enQueue(T value) = 0;
    virtual T deQueue() = 0;
    virtual T front() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;

    virtual ~AbstractQueue() {}
};
template <typename T>
class myQueue : public AbstractQueue<T> {
private:
    T* arr;
    int maxSize;
    int currentSize;
    int frontIndex;
    int rearIndex;

public:
    myQueue(int size = 10) {
        maxSize = size;
        currentSize = 0;
        frontIndex = 0;
        rearIndex = -1;

        arr = new T[maxSize];
    }
    void enQueue(T value) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }

        rearIndex = (rearIndex + 1) % maxSize;
        arr[rearIndex] = value;
        currentSize++;

        cout << "Element inserted successfully!" << endl;
    }

    T deQueue() {
        if (isEmpty()) {
            cout << "Queue is empty!" <<endl;
            return T();
        }

        T value = arr[frontIndex];

        frontIndex = (frontIndex + 1) % maxSize;
        currentSize--;

        return value;
    }

    T front() const {
        if (isEmpty()) {
            return T();
        }

        return arr[frontIndex];
    }

    bool isEmpty() const {
        return currentSize == 0;
    }

    bool isFull() const {
        return currentSize == maxSize;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements (Front to Rear):" << endl;

        for (int i = 0; i < currentSize; i++) {
            int index = (frontIndex + i) % maxSize;
            cout << arr[index] << endl;
        }
    }

    ~myQueue() {
        delete[] arr;
    }
};

int main1() {
    int size;
    int choice;
    int value;

    cout << "Enter maximum queue size: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid queue size!" << endl;
        return 0;
    }

    myQueue<int> q(size);

    do {
        cout << " QUEUE MENU ";
        cout << "1. EnQueue (Insert)" << endl;
        cout << "2. DeQueue (Remove)" << endl;
        cout << "3. Front Element" << endl;
        cout << "4. Check Empty" << endl;
        cout << "5. Check Full" << endl;
        cout << "6. Display Queue" << endl;
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
            if (q.isEmpty()) {
                cout << "Queue is empty!" << endl;
            }
            else {
                cout << "Removed element: " << q.deQueue() << endl;
            }
            break;

        case 3:
            if (q.isEmpty()) {
                cout << "Queue is empty!" << endl;
            }
            else {
                cout << "Front element: " << q.front() << endl;
            }
            break;

        case 4:
            if (q.isEmpty()) {
                cout << "Queue is empty." << endl;
            }
            else {
                cout << "Queue is not empty." << endl;
            }
            break;

        case 5:
            if (q.isFull()) {
                cout << "Queue is full." << endl;
            }
            else {
                cout << "Queue is not full." << endl;
            }
            break;

        case 6:
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
