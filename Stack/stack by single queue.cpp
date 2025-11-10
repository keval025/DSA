#include <bits/stdc++.h>
using namespace std;

class Stack {
    queue<int> q;

    public:

    void push(int data){
        q.push(data);
        int n = q.size();
        for(int i=0;i<n-1;i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop(){
        if(q.empty()){
            cout << "stack is empty\n";
            return -1;
        }
        int ans = q.front();
        q.pop();
        cout << "poped element is " << ans << endl;
    }

    int top(){
        if(q.empty()){
            cout << "Stack is empty " << endl;
            return -1;
        }
        return q.front();
    }

    int size(){
        return q.size();
    }

    bool empty(){
        return q.size() == 0;
    }
};

int main(){
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.pop();
    s.top();
    s.size();

    return 0;
}