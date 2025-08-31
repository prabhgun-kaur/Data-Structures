#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 100
struct Stack {
    int arr[MAX];
    int top;
} st;

void init() {
    st.top = -1;
}

void push(int x) {
    if (st.top < MAX - 1) {
        st.arr[++st.top] = x;
    }
}

int pop() {
    if (st.top >= 0) {
        return st.arr[st.top--];
    }
    return -1; // error case
}

// Function to evaluate Postfix expression
int evaluatePostfix(char postfix[]) {
    init();
    int n = strlen(postfix);

    for (int i = 0; i < n; i++) {
        char c = postfix[i];

        // If operand, push to stack
        if (isdigit(c)) {
            push(c - '0');   // convert char digit to int
        }
        // If operator, pop two operands and apply
        else {
            int val2 = pop();
            int val1 = pop();

            switch (c) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
                case '^': push(pow(val1, val2)); break;
            }
        }
    }

    return pop(); // final result
}

int main() {
    char postfix[100];
    cout << "Enter a postfix expression (single-digit operands): ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Result = " << result << endl;

    return 0;
}
