#include "myQueue.h"

int main() {
    myQueue<int> q(10);
    int c;
    do {
        cout << "\n1.Add 2.Resolve 3.Next 4.Display 5.Exit\nChoice: ";
        cin >> c;
        if (c == 1) { int id; cout << "Ticket ID: "; cin >> id; q.enQueue(id); }
        else if (c == 2) { if (!q.isEmpty()) cout << "Resolved: " << q.deQueue() << endl; else q.deQueue(); }
        else if (c == 3) { if (!q.isEmpty()) cout << "Next: " << q.front() << endl; else q.front(); }
        else if (c == 4) q.display();
    } while (c != 5);
}