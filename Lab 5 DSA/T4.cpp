#include <iostream>
using namespace std;

class TextEditor {
private:
    char text[1000];
    int textSize;

    char undoStack[1000];
    int undoTop;

    char redoStack[1000];
    int redoTop;
    char undoType[1000];
    char redoType[1000];

public:
    TextEditor() {
        textSize = 0;
        undoTop = -1;
        redoTop = -1;
    }

    void typeCharacter(char ch) {
        if (textSize == 999 || undoTop == 999) {
            cout << "Text or history is full!" << endl;
            return;
        }

        text[textSize] = ch;
        textSize++;

        undoStack[++undoTop] = ch;
        undoType[undoTop] = 'T';
        redoTop = -1;

        cout << "Character added successfully!" << endl;
    }

    void deleteCharacter() {
        if (textSize == 0) {
            cout << "There is no character to delete!" << endl;
            return;
        }

        if (undoTop == 999) {
            cout << "Undo history is full!" << endl;
            return;
        }

        char ch = text[textSize - 1];
        textSize--;

        undoStack[++undoTop] = ch;
        undoType[undoTop] = 'D';

        redoTop = -1;

        cout << "Last character deleted successfully!" << endl;
    }

    void undo() {
        if (undoTop == -1) {
            cout << "Nothing to undo!" << endl;
            return;
        }

        char ch = undoStack[undoTop];
        char action = undoType[undoTop];
        undoTop--;

        if (action == 'T') {
            textSize--;
        }
        else if (action == 'D') {
            text[textSize] = ch;
            textSize++;
        }

        redoStack[++redoTop] = ch;
        redoType[redoTop] = action;

        cout << "Undo successful!" << endl;
    }

    void redo() {
        if (redoTop == -1) {
            cout << "Nothing to redo!" << endl;
            return;
        }

        char ch = redoStack[redoTop];
        char action = redoType[redoTop];
        redoTop--;

        if (action == 'T') {
            text[textSize] = ch;
            textSize++;
        }
        else if (action == 'D') {
            textSize--;
        }

        undoStack[++undoTop] = ch;
        undoType[undoTop] = action;

        cout << "Redo successful!" << endl;
    }

    void displayText() {
        cout << "Current Text: ";

        if (textSize == 0) {
            cout << "(Empty)";
        }
        else {
            for (int i = 0; i < textSize; i++) {
                cout << text[i];
            }
        }

        cout << endl;
    }
};

int main() {
    TextEditor editor;
    int choice;
    char ch;

    do {
        cout << " TEXT EDITOR " << endl;
        cout << "1. Type a Character" << endl;
        cout << "2. Delete Last Character" << endl;
        cout << "3. Undo" << endl;
        cout << "4. Redo" << endl;
        cout << "5. Display Text" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter a character: ";
            cin >> ch;
            editor.typeCharacter(ch);
            break;

        case 2:
            editor.deleteCharacter();
            break;

        case 3:
            editor.undo();
            break;

        case 4:
            editor.redo();
            break;

        case 5:
            editor.displayText();
            break;

        case 0:
            cout << "Text editor closed." << endl;
            break;

        default:
            cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 0);

    return 0;
}
