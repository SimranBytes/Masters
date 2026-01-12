#include <iostream>
using namespace std;

#define MAX 5   // maximum size of the stack

int stack[MAX];
int top = -1;  // stack is initially empty

// ---------- PUSH ----------
void push(int value) {
    if (top == MAX - 1) {
        cout << "Stack Overflow! Cannot push " << value << endl;
    } else {
        top++;
        stack[top] = value;
        cout << value << " pushed onto the stack." << endl;
    }
}

// ---------- POP ----------
void pop() {
    if (top == -1) {
        cout << "Stack Underflow! Nothing to pop." << endl;
    } else {
        cout << stack[top] << " popped from the stack." << endl;
        top--;
    }
}

// ---------- PEEK ----------
void peek() {
    if (top == -1) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Top element is: " << stack[top] << endl;
    }
}

// ---------- DISPLAY ----------
void display() {
    if (top == -1) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack elements (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

// ---------- MAIN ----------
int main() {
    int choice, value;

    cout << "\n--- Stack Implementation using Array ---\n";

    do {
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
