#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    
    LinkedList() : head(nullptr) {}
    
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

Node* mergeTwoLists(Node* l1, Node* l2) {
    Node dummy(0);
    Node* current = &dummy;
    
    while (l1 && l2) {
        if (l1->data <= l2->data) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }
    
    current->next = l1 ? l1 : l2;
    return dummy.next;
}

Node* mergeAllLists(vector<LinkedList>& lists) {
    if (lists.empty()) return nullptr;
    
    Node* merged = lists[0].head;
    for (int i = 1; i < lists.size(); i++) {
        merged = mergeTwoLists(merged, lists[i].head);
    }
    return merged;
}

void displayMergedList(Node* head) {
    cout << "Merged Sorted List: ";
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main() {
    int n, m;
    
    cout << "Enter number of linked lists: ";
    cin >> n;
    cout << "Enter number of elements in each list: ";
    cin >> m;
    
    vector<LinkedList> lists(n);
    
    for (int i = 0; i < n; i++) {
        cout << "\nEnter " << m << " elements for linked list " << (i + 1) << ":\n";
        for (int j = 0; j < m; j++) {
            int val;
            cout << "Element " << (j + 1) << ": ";
            cin >> val;
            lists[i].insert(val);
        }
        cout << "List " << (i + 1) << ": ";
        lists[i].display();
    }
    
    Node* mergedHead = mergeAllLists(lists);
    displayMergedList(mergedHead);
    
    return 0;
}