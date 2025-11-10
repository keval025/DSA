#include <bits/stdc++.h>
using namespace std;

class Queue {
    stack <int> st1;
    stack <int> st2;

    public:

    void enqueue(int data){
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }

        st2.push(data);

        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
    }

    int deque(){
        if(st1.empty()){
            cout << "QUEUE is empty\n";
            return -1;
        }
        int ans = st1.top();
        st1.pop();
        return ans;
    }

    int front(){
        if(st1.empty()){
            cout << "QUEUE is empty\n";
            return -1;
        }
        int ans = st1.top();
        return ans;        
    }

    int size(){
        return st1.size();
    }

    bool empty(){
        return st1.empty();
    }
};

int main(){
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.deque();
    q.front();
    q.size();
    q.empty();

    return 0;
}