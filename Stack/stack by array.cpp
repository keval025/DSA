#include <bits/stdc++.h>
using namespace std;

class Stack{
    int *arr;
    int size;
    int top;

    public:
    Stack() {
        arr = new int[1000];
        size = 1000;
        top = -1;
    }

    void push(int data){
        if(top == size - 1){
            cout << "Stack Overflow\n";
            return;
        }else{
            top++;
            arr[top] = data;
        }
    }

    int pop(){
        if(empty()){
            cout << "Stack underflow\n";
            return -1;
        }
        int x = arr[top];
        top--;
        return x; 
    }

    int peek(){
        if(empty()){
            cout << "Stack underflow\n";
            return -1;
        }
        return arr[top];
    }

    bool empty(){
        return top == -1;
    }
};

int main(){
    Stack s;

    s.push(1);
    s.push(2);
    cout << s.peek() << endl;
    s.pop();
    cout << s.pop() << s.peek() << endl;
}