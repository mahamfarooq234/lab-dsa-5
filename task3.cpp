#include <stack>
#include "myQueue.h"

void reverseFirstK(myQueue<int>& q, int k) {
    if (k <= 1 || q.isEmpty()) return;
    if (k > q.size()) k = q.size();

    stack<int> s;
    for (int i = 0; i < k; i++) s.push(q.deQueue());
    while (!s.empty()) { q.enQueue(s.top()); s.pop(); }

    int rem = q.size() - k;
    for (int i = 0; i < rem; i++) q.enQueue(q.deQueue());
}

int main() {
    myQueue<int> q(10);
    int n; cout << "How many elements? "; cin >> n;
    cout << "Enter: ";
    for (int i = 0; i < n; i++) { int v; cin >> v; q.enQueue(v); }

    int k; cout << "K: "; cin >> k;

    cout << "Before: "; q.display();
    reverseFirstK(q, k);
    cout << "After:  "; q.display();
}
