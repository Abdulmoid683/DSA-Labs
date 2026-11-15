#include <iostream>
using namespace std;

class myCarStack {
private:
    string cars[8];
    int topIndex;

public:
    myCarStack() {
        topIndex = -1;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    bool isFull() {
        return topIndex == 7;
    }

    int size() {
        return topIndex + 1;
    }

    void push(string carNumber) {
        if (isFull()) {
            cout << "Parking lot is full! Cannot park more cars." << endl;
            return;
        }

        topIndex++;
        cars[topIndex] = carNumber;

        cout << "Car parked successfully!" << endl;
    }

    string pop() {
        if (isEmpty()) {
            return "";
        }

        string carNumber = cars[topIndex];
        topIndex--;

        return carNumber;
    }

    string top() {
        if (isEmpty()) {
            return "";
        }

        return cars[topIndex];
    }

    bool search(string carNumber) {
        for (int i = 0; i <= topIndex; i++) {
            if (cars[i] == carNumber) {
                return true;
            }
        }

        return false;
    }

    void display() {
        if (isEmpty()) {
            cout << "Parking lot is empty!" << endl;
            return;
        }

        cout << "\nCurrently parked cars (Top to Bottom):" << endl;

        for (int i = topIndex; i >= 0; i--) {
            cout << cars[i] << endl;
        }
    }

    void removeCar(string carNumber) {
        if (isEmpty()) {
            cout << "Parking lot is empty!" << endl;
            return;
        }

        if (!search(carNumber)) {
            cout << "Car not found in parking lot!" << endl;
            return;
        }

        myCarStack tempStack;

        while (top() != carNumber) {
            tempStack.push(pop());
        }

        pop();

        cout << "Car " << carNumber << " removed successfully!" << endl;

        while (!tempStack.isEmpty()) {
            push(tempStack.pop());
        }
    }
};

int main3() {
    myCarStack parking;
    int choice;
    string carNumber;

    do {
        cout << " PARKING LOT MANAGEMENT SYSTEM ";
        cout << "1. Park a New Car" << endl;
        cout << "2. Remove a Car" << endl;
        cout << "3. View Currently Parked Cars" << endl;
        cout << "4. Display Total Cars Parked" << endl;
        cout << "5. Search for a Car" << endl;
        cout << "6. View Top Car"<< endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter car number: ";
            cin >> carNumber;
            parking.push(carNumber);
            break;

        case 2:
            cout << "Enter car number to remove: ";
            cin >> carNumber;
            parking.removeCar(carNumber);
            break;

        case 3:
            parking.display();
            break;

        case 4:
            cout << "Total cars parked: " << parking.size() << endl;
            break;

        case 5:
            cout << "Enter car number to search: ";
            cin >> carNumber;

            if (parking.search(carNumber)) {
                cout << "Car is present in parking lot." << endl;
            }
            else {
                cout << "Car is not present in parking lot." << endl;
            }
            break;

        case 6:
            if (parking.isEmpty()) {
                cout << "Parking lot is empty!\n";
            }
            else {
                cout << "Top car: " << parking.top() << endl;
            }
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
