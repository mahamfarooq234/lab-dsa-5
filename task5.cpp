#include "myQueue.h"

int main() {
    myQueue<string> q(10);
    int c;
    do {
        cout << "\n1.Add 2.Print 3.Front 4.Display 5.Exit\nChoice: ";
        cin >> c; cin.ignore();
        if (c == 1) { string s; cout << "Document: "; getline(cin, s); q.enQueue(s); }
        else if (c == 2) { if (!q.isEmpty()) cout << "Printed: " << q.deQueue() << endl; else q.deQueue(); }
        else if (c == 3) { if (!q.isEmpty()) cout << "Front: " << q.front() << endl; else q.front(); }
        else if (c == 4) q.display();
    } while (c != 5);
}