#include <iostream>
#include <string.h>
using namespace std;

#define MAX 100   

struct Stack {
    char arr[MAX];
    int top;
};


void init(Stack &s) {
    s.top = -1;
}


int isFull(Stack &s) {
    if (s.top == MAX - 1) return 1;
    return 0;
}


int isEmpty(Stack &s) {
    if (s.top == -1) return 1;
    return 0;
}


void push(Stack &s, char c) {
    if (!isFull(s)) {
        s.arr[++s.top] = c;
    }
}


char pop(Stack &s) {
    if (!isEmpty(s)) {
        return s.arr[s.top--];
    }
    return '\0'; // return null character if empty
}

// Reverse string using stack
void reverseString(char str[]) {
    Stack s;
    init(s);

    int n = strlen(str);

    // Push all characters
    for (int i = 0; i < n; i++) {
        push(s, str[i]);
    }

    // Pop all characters back into string
    for (int i = 0; i < n; i++) {
        str[i] = pop(s);
    }
}

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin >> str;   

    reverseString(str);

    cout << "Reversed string: " << str << endl;

    return 0;
}
