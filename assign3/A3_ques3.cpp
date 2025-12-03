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

int isEmpty(Stack &s) {
    if (s.top == -1) return 1;
    return 0;
}

int isFull(Stack &s) {
    if (s.top == MAX - 1) return 1;
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
    return '\0'; // null character if empty
}

// Function to check matching pair
int isMatchingPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '{' && close == '}') return 1;
    if (open == '[' && close == ']') return 1;
    return 0;
}

// Function to check balanced parentheses
int checkBalanced(char exp[]) {
    Stack s;
    init(s);

    for (int i = 0; i < strlen(exp); i++) {
        char c = exp[i];

        // If opening bracket, push
        if (c == '(' || c == '{' || c == '[') {
            push(s, c);
        }
        // If closing bracket, check stack
        else if (c == ')' || c == '}' || c == ']') {
            if (isEmpty(s)) return 0;  // No matching opening
            char top = pop(s);
            if (!isMatchingPair(top, c)) return 0;
        }
    }

    // If stack empty → balanced
    return isEmpty(s);
}

int main() {
    char exp[100];
    cout << "Enter an expression: ";
    cin >> exp;

    if (checkBalanced(exp)) {
        cout << "Expression is Balanced" << endl;
    } else {
        cout << "Expression is NOT Balanced" << endl;
    }

    return 0;
}
