#include <iostream>
using namespace std;

int top = -1;
int n=10;
int *s1;        

void pop() {
    if (top == -1) {
        cout << "Stack Underflow! No element to pop." << endl;
        return;
    }
    cout << "Element deleted is: " << s1[top] << endl;
    top--;
}

void push(int a) {
    if (top == n - 1) {
        cout << "Stack Overflow! Cannot push element " << a << endl;
        return;
    }
    top++;
    s1[top] = a;
}

void peek() {
    if (top == -1) {
        cout << "Stack is empty, no top element." << endl;
        return;
    }
    cout << "Top element of the stack is: " << s1[top] << endl;
}

void printstack(int arr[]){
    n=top;
    for(int i=n; i>=0; i--){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    s1 = new int[n];
    int s2[n];
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);   
    push(7);
    cout<<endl;
    cout<<"Stack reversal using auxiliary stack"<<endl;
    cout<<"Elements in the stack are: "<<endl;
    printstack(s1);
   
    int j=0;
    while(top!=-1){
        s2[j]=s1[top];
        j++;
        top--;
    }

    cout<<"Reversed elements will be: "<<endl;
    for(int i=j-1; i>=0; i--){
        cout<<s2[i]<<" ";
    }
   
    return 0;
}