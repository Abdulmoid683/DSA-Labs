#include <iostream>
#include <string>
using namespace std;

class LibraryItem {
public:
    virtual void display() = 0;
};

class Book : public LibraryItem {
private:
    string title;
    string author;
    int pages;

public:
    Book() {}

    Book(string t, string a, int p) {
        title = t;
        author = a;
        pages = p;
    }

    string getTitle() {
        return title;
    }

    int getPages() {
        return pages;
    }

    void display() override {
        cout << "Book Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pages << endl;
    }
};

class Newspaper : public LibraryItem {
private:
    string name;
    string date;
    string edition;

public:
    Newspaper() {}

    Newspaper(string n, string d, string e) {
        name = n;
        date = d;
        edition = e;
    }

    string getName() {
        return name;
    }

    string getEdition() {
        return edition;
    }

    void display() override {
        cout << "Newspaper Name: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Edition: " << edition << endl;
    }
};

template <typename T, typename Compare>
void selectionSort(T arr[], int size, Compare compare) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < size; j++) {
            if (compare(arr[j], arr[minIndex])) {
                minIndex = j;
            }
        }

        T temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

template <typename T, typename Key, typename GetKey>
T* linearSearch(T arr[], int size, Key key, GetKey getKey) {
    for (int i = 0; i < size; i++) {
        if (getKey(arr[i]) == key) {
            return &arr[i];
        }
    }

    return NULL;
}

template <typename T, typename Key, typename GetKey>
T* binarySearch(T arr[], int size, Key key, GetKey getKey) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (getKey(arr[mid]) == key) {
            return &arr[mid];
        }
        else if (getKey(arr[mid]) < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return NULL;
}

class Library {
private:
    Book books[100];
    Newspaper newspapers[100];

    int bookCount;
    int newspaperCount;

public:
    Library() {
        bookCount = 0;
        newspaperCount = 0;
    }

    void addBook(Book book) {
        if (bookCount < 100) {
            books[bookCount] = book;
            bookCount++;
        }
    }

    void addNewspaper(Newspaper newspaper) {
        if (newspaperCount < 100) {
            newspapers[newspaperCount] = newspaper;
            newspaperCount++;
        }
    }

    void displayCollection() {
        cout << "----- BOOKS -----" << endl;

        for (int i = 0; i < bookCount; i++) {
            books[i].display();
            cout << endl;
        }

        cout << "----- NEWSPAPERS -----" << endl;

        for (int i = 0; i < newspaperCount; i++) {
            newspapers[i].display();
            cout << endl;
        }
    }

    void sortBooksByPages() {
        selectionSort(books, bookCount,
            [](Book a, Book b) {
                return a.getPages() < b.getPages();
            });
    }

    void sortNewspapersByEdition() {
        selectionSort(newspapers, newspaperCount,
            [](Newspaper a, Newspaper b) {
                return a.getEdition() < b.getEdition();
            });
    }

    Book* searchBookByTitle(string title) {
        return linearSearch(books, bookCount, title,
            [](Book b) {
                return b.getTitle();
            });
    }

    Newspaper* searchNewspaperByName(string name) {
        return linearSearch(newspapers, newspaperCount, name,
            [](Newspaper n) {
                return n.getName();
            });
    }

    Book* searchBookByTitleBinary(string title) {
        selectionSort(books, bookCount,
            [](Book a, Book b) {
                return a.getTitle() < b.getTitle();
            });

        return binarySearch(books, bookCount, title,
            [](Book b) {
                return b.getTitle();
            });
    }

    Newspaper* searchNewspaperByNameBinary(string name) {
        selectionSort(newspapers, newspaperCount,
            [](Newspaper a, Newspaper b) {
                return a.getName() < b.getName();
            });

        return binarySearch(newspapers, newspaperCount, name,
            [](Newspaper n) {
                return n.getName();
            });
    }
};

int main() {

    Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
    Book book2("To Kill a Mockingbird", "Harper Lee", 324);

    Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
    Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");

    Library library;

    library.addBook(book1);
    library.addBook(book2);

    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);

    cout << "Before Sorting:\n";
    library.displayCollection();

    library.sortBooksByPages();
    library.sortNewspapersByEdition();

    cout << "After Sorting:";
    library.displayCollection();

    Book* foundBook = library.searchBookByTitle(
        "The Catcher in the Rye"
    );

    if (foundBook != NULL) {
        cout << "Found Book:";
        foundBook->display();
    }
    else {
        cout << "Book not found.";
    }

    Newspaper* foundNewspaper = library.searchNewspaperByName(
        "The Times"
    );

    if (foundNewspaper != NULL) {
        cout << "Found Newspaper:";
        foundNewspaper->display();
    }
    else {
        cout << "Newspaper not found.";
    }

    return 0;
}