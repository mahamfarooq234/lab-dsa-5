#include <iostream>
#include <stack>
using namespace std;

class StackQueue {
    stack<int> in, out;
public:
    void enQueue(int v) { in.push(v); }
    int deQueue() {
        if (in.empty() && out.empty()) { cout << "[UNDERFLOW] Empty!\n"; return -1; }
        if (out.empty()) while (!in.empty()) { out.push(in.top()); in.pop(); }
        int v = out.top(); out.pop();
        return v;
    }
    int front() {
        if (in.empty() && out.empty()) { cout << "[UNDERFLOW] Empty!\n"; return -1; }
        if (out.empty()) while (!in.empty()) { out.push(in.top()); in.pop(); }
        return out.top();
    }
    bool isEmpty() { return in.empty() && out.empty(); }
    void display() {
        if (isEmpty()) { cout << "Empty.\n"; return; }
        StackQueue t = *this;
        while (!t.isEmpty()) cout << t.deQueue() << " ";
        cout << endl;
    }
};

int main() {
    StackQueue q;
    int c;
    do {
        cout << "\n1.Enqueue 2.Dequeue 3.Front 4.Display 5.Exit\nChoice: ";
        cin >> c;
        if (c == 1) { int v; cout << "Value: "; cin >> v; q.enQueue(v); }
        else if (c == 2) { int v = q.deQueue(); if (v != -1) cout << "Dequeued: " << v << endl; }
        else if (c == 3) { int v = q.front(); if (v != -1) cout << "Front: " << v << endl; }
        else if (c == 4) q.display();
    } while (c != 5);
}