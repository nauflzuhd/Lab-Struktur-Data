#include <iostream>
using namespace std;

#define MAX 5
int stack[MAX];
int top = -1; // awalnya kosong

//push
void push (int value) {
    if (top == MAX) {
        cout << "Stack Penuh !\n";
    } else {
        top++;
        stack[top] = value;
        cout << value << " ditambahkan dalam stack \n";
    }
}

//pop
void pop() {
    if (top == -1) {
        cout << "Stack kosong !\n";
    } else {
        cout << "n" << stack[top] << " dihapus dari stack.\n";
        top--;
    }
}

//display
void display() {
    if (top == 1) {
        cout << "Stack kosong !\n";
    } else {
        cout << "\nIsi Stack : \n";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        // cout << "\n isi array (index 0 ke MAX-1) : \n";
        // for (int i = 0; i < top; i++) {
        //     cout << "[" << i << "] " << stack[i] << " "; 
        // } 
        cout << endl;
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    for (int i = 0; i < 5; i++ ) {
        display();
        pop();
        display();
    }

    return 0;
}