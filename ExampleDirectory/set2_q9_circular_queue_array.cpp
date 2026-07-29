// Q9: Design a circular queue using an array with enqueue, dequeue, and display operations.
#include <iostream>
using namespace std;

class CircularQueue
{
private:
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    CircularQueue(int cap) : front(-1), rear(-1), size(0), capacity(cap)
    {
        arr = new int[capacity];
    }

    ~CircularQueue()
    {
        delete[] arr;
    }

    bool isEmpty() const
    {
        return size == 0;
    }

    bool isFull() const
    {
        return size == capacity;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full. Overflow.\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        if (front == -1)
        {
            front = 0;
        }
        size++;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Underflow.\n";
            return;
        }
        front = (front + 1) % capacity;
        size--;
        if (size == 0)
        {
            front = rear = -1;
        }
    }

    void display() const
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        int index = front;
        for (int i = 0; i < size; i++)
        {
            cout << arr[index] << " ";
            index = (index + 1) % capacity;
        }
        cout << '\n';
    }
};

int main()
{
    int capacity, choice, value;
    cout << "Enter queue capacity: ";
    cin >> capacity;
    CircularQueue queue(capacity);

    do
    {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            queue.enqueue(value);
            break;
        case 2:
            queue.dequeue();
            break;
        case 3:
            queue.display();
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}