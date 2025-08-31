#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100
struct Stack {
    char arr[MAX];
    int top;
} st;

void init() {
    st.top = -1;
}


void push(char c) {
    if (st.top < MAX - 1) {
        st.arr[++st.top] = c;
    }
}

char pop() {
    if (st.top >= 0) {
        return st.arr[st.top--];
    }
    return '\0';
}

char peek() {
    if (st.top >= 0) return st.arr[st.top];
    return '\0';
}

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

// Infix to Postfix conversion
void infixToPostfix(char infix[], char postfix[]) {
    init();
    int k = 0;
    for (int i = 0; i < strlen(infix); i++) {
        char c = infix[i];

        // Operand → directly to output
        if (isalnum(c)) {
            postfix[k++] = c;
        }
        // Opening bracket
        else if (c == '(') {
            push(c);
        }
        // Closing bracket
        else if (c == ')') {
            while (peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        }
        // Operator
        else {
            while (st.top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }

    // Pop remaining operators
    while (st.top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
}

int main() {
    char infix[100], postfix[100];
    cout << "Enter infix expression: ";
    cin >> infix;

    infixToPostfix(infix, postfix);

    cout << "Postfix expression: " << postfix << endl;
    return 0;
}
