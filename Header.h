#include <iostream>
using namespace std;

template <typename T>
class AbstractQueue {
public:
    virtual void enQueue(T value) = 0;
    virtual T deQueue() = 0;
    virtual T front() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractQueue() {}
};

template <typename T>
class myQueue : public AbstractQueue<T> {
    T* arr;
    int maxSize, currentSize, frontIdx, rearIdx;
public:
    myQueue(int size) {
        maxSize = size;
        arr = new T[maxSize];
        currentSize = 0;
        frontIdx = 0;
        rearIdx = -1;
    }
    ~myQueue() { delete[] arr; }

    void enQueue(T value) {
        if (isFull()) { cout << "[OVERFLOW] Queue full!\n"; return; }
        rearIdx = (rearIdx + 1) % maxSize;
        arr[rearIdx] = value;
        currentSize++;
    }
    T deQueue() {
        if (isEmpty()) { cout << "[UNDERFLOW] Queue empty!\n"; return T(); }
        T v = arr[frontIdx];
        frontIdx = (frontIdx + 1) % maxSize;
        currentSize--;
        return v;
    }
    T front() const {
        if (isEmpty()) { cout << "[UNDERFLOW] Queue empty!\n"; return T(); }
        return arr[frontIdx];
    }
    bool isEmpty() const { return currentSize == 0; }
    bool isFull() const { return currentSize == maxSize; }
    int size() const { return currentSize; }

    void display() const {
        if (isEmpty()) { cout << "Queue is empty.\n"; return; }
        int i = frontIdx;
        for (int k = 0; k < currentSize; k++) {
            cout << arr[i] << " ";
            i = (i + 1) % maxSize;
        }
        cout << endl;
    }
};
