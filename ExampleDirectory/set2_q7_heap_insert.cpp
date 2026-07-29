// Q7: Create a heap and insert elements into it, then display the heap after insertion.
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
    int capacity, n, value;
    cout << "Enter heap capacity: ";
    cin >> capacity;
    MaxHeap heap(capacity);

    cout << "Enter number of elements to insert: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value " << i + 1 << ": ";
        cin >> value;
        heap.insert(value);
    }

    heap.display();
    return 0;
}