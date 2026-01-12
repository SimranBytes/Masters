#include <iostream>
using namespace std;

#define MAX 5 

int queue[MAX];
int front = 0;
int rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        cout << "Queue Overflow! Cannot insert " << value << endl;
    } else {
        rear++;
        queue[rear] = value;
        cout << value << " inserted into queue." << endl;
    }
}

void dequeue() {
    if (front > rear) {
        cout << "Queue Underflow! Nothing to delete." << endl;
    } else {
        cout << queue[front] << " deleted from queue." << endl;
        front++;
    }
}

void display() {
    if (front > rear) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    
    queue[0] = 10;
    queue[1] = 20;
    queue[2] = 30;
    rear = 2;  
    cout << "Initial Queue: ";
    display();

    int choice, value;

    do {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
