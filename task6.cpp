#include "myQueue.h"

struct Package { int id, start, end; string address; };

int main() {
    myQueue<Package> q(10);
    int c;
    do {
        cout << "\n1.Add 2.Deliver 3.Front 4.Display 5.Check 6.Exit\nChoice: ";
        cin >> c; cin.ignore();

        if (c == 1) {
            Package p;
            cout << "ID: "; cin >> p.id; cin.ignore();
            cout << "Address: "; getline(cin, p.address);
            cout << "Start: "; cin >> p.start;
            cout << "End: "; cin >> p.end; cin.ignore();
            q.enQueue(p);
        }
        else if (c == 2) {
            if (q.isEmpty()) { cout << "[UNDERFLOW] Empty.\n"; continue; }
            Package p = q.deQueue();
            cout << "Delivered " << p.id << " to " << p.address << endl;
        }
        else if (c == 3) {
            if (q.isEmpty()) { cout << "[UNDERFLOW] Empty.\n"; continue; }
            Package p = q.front();
            cout << p.id << " | " << p.address << " | " << p.start << "-" << p.end << endl;
        }
        else if (c == 4) {
            if (q.isEmpty()) { cout << "No packages.\n"; continue; }
            myQueue<Package> t(q.size());
            while (!q.isEmpty()) {
                Package p = q.deQueue();
                cout << p.id << " | " << p.address << " | " << p.start << "-" << p.end << endl;
                t.enQueue(p);
            }
            while (!t.isEmpty()) q.enQueue(t.deQueue());
        }
        else if (c == 5) {
            if (q.isEmpty()) { cout << "[UNDERFLOW] Empty.\n"; continue; }
            int now; cout << "Current time: "; cin >> now; cin.ignore();
            Package p = q.front();
            if (now >= p.start && now <= p.end)
                cout << "Package " << p.id << " can be delivered.\n";
            else {
                cout << "Package " << p.id << " expired.\n";
                q.deQueue();
            }
        }
    } while (c != 6);
}