#include <iostream>
using namespace std;
template <typename T>
class AbstractStack
{
public:

    virtual void push(T value) = 0;

    virtual T pop() = 0;

    virtual T top() const = 0;

    virtual bool isEmpty() const = 0;

    virtual bool isFull() const = 0;

    virtual ~AbstractStack()
    {
    }
};

template <typename T>
class myStack : public AbstractStack<T>
{
private:

    T* arr;
    T* minArr;

    int maxSize;
    int currentSize;
    int minSize;

public:
    myStack(int size = 10)
    {
        maxSize = size;
        currentSize = 0;
        minSize = 0;

        arr = new T[maxSize];
        minArr = new T[maxSize];
    }

    void push(T value)
    {
        if (isFull())
        {
            cout << "Stack is full!" << endl;
            return;
        }

        arr[currentSize] = value;
        currentSize++;

        if (minSize == 0 || value <= minArr[minSize - 1])
        {
            minArr[minSize] = value;
            minSize++;
        }

        cout << "Element pushed successfully!" << endl;
    }

    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return T();
        }

        T value = arr[currentSize - 1];
        currentSize--;

        if (value == minArr[minSize - 1])
        {
            minSize--;
        }

        return value;
    }

    T top() const
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return T();
        }

        return arr[currentSize - 1];
    }

    bool isEmpty() const
    {
        return currentSize == 0;
    }

    bool isFull() const
    {
        return currentSize == maxSize;
    }

    T getMin() const
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return T();
        }

        return minArr[minSize - 1];
    }

    void display() const
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return;
        }

        cout << "Stack elements (Top to Bottom):" << endl;

        for (int i = currentSize - 1; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }

    ~myStack()
    {
        delete[] arr;
        delete[] minArr;
    }
};
int main2(){
    int size;

    cout << "Enter maximum stack size: ";
    cin >> size;

    if (size <= 0)
    {
        cout << "Invalid stack size!" << endl;
        return 0;
    }

    myStack<int> s(size);

    int choice, value;

    do
    {
        cout << " ENHANCED STACK MENU " << endl;
        cout << "1. Push element" << endl;
        cout << "2. Pop element" << endl;
        cout << "3. Show top element" << endl;
        cout << "4. Check if stack is empty" << endl;
        cout << "5. Check if stack is full" << endl;
        cout << "6. Display stack elements" << endl;
        cout << "7. Show minimum element" << endl;
        cout << "8. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;

            s.push(value);
            break;

        case 2:
            cout << "Popped element: " << s.pop() << endl;
            break;

        case 3:
            cout << "Top element: " << s.top() << endl;
            break;

        case 4:
            if (s.isEmpty())
                cout << "Stack is empty." << endl;
            else
                cout << "Stack is not empty." << endl;
            break;

        case 5:
            if (s.isFull())
                cout << "Stack is full." << endl;
            else
                cout << "Stack is not full." << endl;
            break;

        case 6:
            s.display();
            break;

        case 7:
            cout << "Minimum element: " << s.getMin() << endl;
            break;

        case 8:
            cout << "Program ended!" << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 8);

    return 0;
}
