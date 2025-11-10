#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Queue {
    Node* head;
    Node* tail;

public:
    Queue() : head(nullptr), tail(nullptr) {}

    void push(int val) {
        Node* newNode = new Node(val);
        if (empty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop() {
        if (empty()) {
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        if (head == nullptr) tail = nullptr;
    }

    int front() {
        if (empty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        return head->data;
    }

    bool empty() {
        return head == nullptr;
    }
};

int main() {
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.front() << " ";
    q.pop();
    cout << q.front() << "\n";

    return 0;
}