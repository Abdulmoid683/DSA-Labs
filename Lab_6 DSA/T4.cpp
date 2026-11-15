
#include <iostream>
using namespace std;

class TicketQueue {
private:
    int tickets[100];
    int frontIndex;
    int rearIndex;
    int currentSize;
    int maxSize;

public:
    TicketQueue(int size = 100) {
        maxSize = size;
        frontIndex = 0;
        rearIndex = -1;
        currentSize = 0;
    }

    bool isEmpty() {
        return currentSize == 0;
    }

    bool isFull() {
        return currentSize == maxSize;
    }

    // Add a new ticket
    void enqueue(int ticket_id) {
        if (isFull()) {
            cout << "Ticket queue is full!\n";
            return;
        }

        if (ticket_id < 1000 || ticket_id > 9999) {
            cout << "Ticket ID must be a 4-digit number!\n";
            return;
        }

        // Check for duplicate ticket ID
        for (int i = 0; i < currentSize; i++) {
            int index = (frontIndex + i) % maxSize;

            if (tickets[index] == ticket_id) {
                cout << "Ticket ID already exists!\n";
                return;
            }
        }

        rearIndex = (rearIndex + 1) % maxSize;
        tickets[rearIndex] = ticket_id;
        currentSize++;

        cout << "Ticket added successfully!\n";
    }

    // Resolve and remove the front ticket
    int dequeue() {
        if (isEmpty()) {
            cout << "No pending tickets!\n";
            return -1;
        }

        int ticket_id = tickets[frontIndex];

        frontIndex = (frontIndex + 1) % maxSize;
        currentSize--;

        return ticket_id;
    }

    // Show next ticket
    int front() {
        if (isEmpty()) {
            cout << "No pending tickets!\n";
            return -1;
        }

        return tickets[frontIndex];
    }

    // Display all pending tickets
    void display() {
        if (isEmpty()) {
            cout << "No pending tickets!\n";
            return;
        }

        cout << "\nPending Support Tickets:\n";

        for (int i = 0; i < currentSize; i++) {
            int index = (frontIndex + i) % maxSize;
            cout << tickets[index] << endl;
        }
    }
};

int main() {
    TicketQueue q;
    int choice;
    int ticket_id;

    do {
        cout << "\n===== CUSTOMER SUPPORT TICKET SYSTEM =====\n";
        cout << "1. Add New Ticket\n";
        cout << "2. Resolve Ticket\n";
        cout << "3. View Next Ticket\n";
        cout << "4. Display Pending Tickets\n";
        cout << "0. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter 4-digit Ticket ID: ";
            cin >> ticket_id;
            q.enqueue(ticket_id);
            break;

        case 2:
            if (!q.isEmpty()) {
                cout << "Ticket resolved: " << q.dequeue() << endl;
            }
            else {
                cout << "No pending tickets!\n";
            }
            break;

        case 3:
            if (!q.isEmpty()) {
                cout << "Next ticket to resolve: " << q.front() << endl;
            }
            else {
                cout << "No pending tickets!\n";
            }
            break;

        case 4:
            q.display();
            break;

        case 0:
            cout << "Customer Support System Closed.\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
