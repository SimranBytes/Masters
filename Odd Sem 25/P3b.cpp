#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL; 

void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
    cout << value << " inserted at the beginning.\n";
}

void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    cout << value << " inserted at the end.\n";
}

void insertAtPosition(int value, int pos) {
    Node* newNode = new Node();
    newNode->data = value;

    if (pos == 1) {
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
        cout << value << " inserted at position " << pos << ".\n";
        return;
    }

    Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Position out of range.\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
    cout << value << " inserted at position " << pos << ".\n";
}

void deleteFromBeginning() {
    if (head == NULL) {
        cout << "List is empty (Underflow).\n";
        return;
    }

    Node* temp = head;
    cout << "Deleted element: " << temp->data << endl;

    head = head->next;
    if (head != NULL)
        head->prev = NULL;

    delete temp;
}

void deleteFromEnd() {
    if (head == NULL) {
        cout << "List is empty (Underflow).\n";
        return;
    }

    Node* temp = head;
    if (temp->next == NULL) {
        cout << "Deleted element: " << temp->data << endl;
        delete temp;
        head = NULL;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    cout << "Deleted element: " << temp->data << endl;
    temp->prev->next = NULL;
    delete temp;
}

void deleteElement(int value) {
    if (head == NULL) {
        cout << "List is empty (Underflow).\n";
        return;
    }

    Node* temp = head;
    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Element " << value << " not found.\n";
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;  

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    cout << value << " deleted from the list.\n";
    delete temp;
}

void display() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    cout << "Current List: ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice, value, pos;

    cout << "\n--- Doubly Linked List Implementation ---\n";

    do {
        cout << "\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Specific Position\n";
        cout << "4. Delete from Beginning\n5. Delete from End\n6. Delete Specific Element\n";
        cout << "7. Display\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            insertAtBeginning(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            insertAtEnd(value);
            break;
        case 3:
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter position: ";
            cin >> pos;
            insertAtPosition(value, pos);
            break;
        case 4:
            deleteFromBeginning();
            break;
        case 5:
            deleteFromEnd();
            break;
        case 6:
            cout << "Enter element to delete: ";
            cin >> value;
            deleteElement(value);
            break;
        case 7:
            display();
            break;
        case 8:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 8);

    return 0;
}
