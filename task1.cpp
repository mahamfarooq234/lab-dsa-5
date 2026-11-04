#include "myQueue.h"

int main() {
    myQueue<int> q(5);
    int c;
    do {
        cout << "\n1.Enqueue 2.Dequeue 3.Front 4.Display 5.Exit\nChoice: ";
        cin >> c;
        if (c == 1) { int v; cout << "Value: "; cin >> v; q.enQueue(v); }
        else if (c == 2) { if (!q.isEmpty()) cout << "Dequeued: " << q.deQueue() << endl; else q.deQueue(); }
        else if (c == 3) { if (!q.isEmpty()) cout << "Front: " << q.front() << endl; else q.front(); }
        else if (c == 4) q.display();
    } while (c != 5);
}