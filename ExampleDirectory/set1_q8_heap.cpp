// Q8: Implement a heap data structure with insertion, deletion, and display of heap elements.
#include <iostream>
using namespace std;

class MaxHeap
{
private:
    int *heap;
    int capacity;
    int size;

    void heapifyUp(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;
            if (heap[parent] >= heap[index])
            {
                break;
            }
            int temp = heap[parent];
            heap[parent] = heap[index];
            heap[index] = temp;
            index = parent;
        }
    }

    void heapifyDown(int index)
    {
        while (true)
        {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && heap[left] > heap[largest])
            {
                largest = left;
            }
            if (right < size && heap[right] > heap[largest])
            {
                largest = right;
            }
            if (largest == index)
            {
                break;
            }
            int temp = heap[index];
            heap[index] = heap[largest];
            heap[largest] = temp;
            index = largest;
        }
    }

public:
    MaxHeap(int cap) : capacity(cap), size(0)
    {
        heap = new int[capacity];
    }

    ~MaxHeap()
    {
        delete[] heap;
    }

    void insert(int value)
    {
        if (size == capacity)
        {
            cout << "Heap is full.\n";
            return;
        }
        heap[size] = value;
        heapifyUp(size);
        size++;
    }

    void deleteRoot()
    {
        if (size == 0)
        {
            cout << "Heap is empty.\n";
            return;
        }
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
        cout << "Root deleted.\n";
    }

    void display() const
    {
        if (size == 0)
        {
            cout << "Heap is empty.\n";
            return;
        }
        cout << "Heap elements: ";
        for (int i = 0; i < size; i++)
        {
            cout << heap[i] << " ";
        }
        cout << '\n';
    }
};

int main()
{
    int capacity, value, choice;
    cout << "Enter heap capacity: ";
    cin >> capacity;
    MaxHeap heap(capacity);

    do
    {
        cout << "\n1. Insert\n2. Delete Root\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            heap.insert(value);
            break;
        case 2:
            heap.deleteRoot();
            break;
        case 3:
            heap.display();
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}