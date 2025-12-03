#include<iostream>
using namespace std;
struct Stack{
    int arr[10];
    int top;
};
void initstack(Stack &s){
    s.top=-1;
}
int isEmpty(Stack &s){
    if(s.top ==-1)
    return 1;
    else 
    return 0;
}
int isFull(Stack &s){
    if(s.top ==9)
    return 1;
    else 
    return 0;
}
void push(Stack &s, int value){
    if(isFull(s)){
        cout<<"Stack Overflow! Cannot push"<<value<<endl;
    }
    else{
        s.arr[++s.top]=value;
        cout<<value<<" pushed into stack"<<endl;
    }
}
void pop(Stack &s){
    if(isEmpty(s)){
        cout<<"Stack underflow! Cannot pop"<<endl;
    }
    else{
        cout<<s.arr[s.top--]<<" popped from stack"<<endl;
    }
}
void peek(Stack &s){
    if(isEmpty(s)){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"top element: "<<s.arr[s.top]<<endl;
    }
}
void display(Stack &s){
    if(isEmpty(s)){
        cout<<"Stack is Empty"<<endl;
    }
    else{
        cout<<"Stack Elements (top to bottom):";
        for(int i=s.top;i>=0;i--){
            cout<<s.arr[i]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    Stack s;
    initstack(s);
    int value;
    push(s,4);
    push(s,5);
    push(s,3);
    push(s,10);
    display(s);
    pop(s);
    display(s);
    peek(s);

    return 0;
}