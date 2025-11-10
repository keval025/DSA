#include <bits/stdc++.h>
using namespace std;

class CircularQueue{
    int *arr;
    int currSize, cap;
    int frontIndex, rearIndex;

    public:
    CircularQueue(int size){
        arr = new int[size];
        cap = size;
        currSize = 0;
        frontIndex = 0;
        rearIndex = -1;
    }

    void push(int data){
        if(currSize == cap){
            cout << "CQ is FULL\n";
            return;
        }
        rearIndex = (rearIndex + 1) % cap;
        arr[rearIndex] = data;
        currSize++;
    }

    void pop(){
        if(currSize == 0){
            cout << "CQ is EMPTY\n";
            return;
        }
        frontIndex = (frontIndex + 1) % cap;
        currSize--;
    }

    int front(){
        if(currSize == 0){
            cout << "CQ is EMPTY\n";
            return -1; // sentinel value when empty
        }
        
        return arr[frontIndex];
    }

    bool empty(){
        return currSize == 0;
    }
};
int main(){

        CircularQueue cq(4);

        cq.push(1);
        int val = cq.front();
        cout << "front: " << val << "\n";

        cq.pop();
        cout << "after pop, empty? " << (cq.empty() ? "yes" : "no") << "\n";
        cq.front();

    return 0;
};