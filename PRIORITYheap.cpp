#include <iostream>
using namespace std;

class PriorityQueue
{
    int heap[100];
    int size;

public:

    PriorityQueue()
    {
        size = 0;
    }

    // Insert into Max Heap
    void enqueueWithPriority(int value)
    {
        heap[size] = value;

        int index = size;

        size++;

        // Up Heapify
        while(index > 0)
        {
            int parent = (index - 1) / 2;

            if(heap[parent] < heap[index])
            {
                swap(heap[parent],
                     heap[index]);

                index = parent;
            }

            else
            {
                break;
            }
        }

        cout << value
             << " inserted into Priority Queue\n";
    }

    // Down Heapify
    void heapifyDown(int index)
    {
        int largest = index;

        int left = 2 * index + 1;
        int right = 2 * index + 2;

        // Compare left child
        if(left < size &&
           heap[left] > heap[largest])
        {
            largest = left;
        }

        // Compare right child
        if(right < size &&
           heap[right] > heap[largest])
        {
            largest = right;
        }

        // Swap if needed
        if(largest != index)
        {
            swap(heap[index],
                 heap[largest]);

            heapifyDown(largest);
        }
    }

    // Remove highest priority element
    int dequeueHighestPriority()
    {
        if(size == 0)
        {
            cout << "Priority Queue Empty\n";
            return -1;
        }

        int highest = heap[0];

        heap[0] = heap[size - 1];

        size--;

        heapifyDown(0);

        return highest;
    }

    // Display queue
    void display()
    {
        if(size == 0)
        {
            cout << "Priority Queue Empty\n";
            return;
        }

        cout << "\nPriority Queue Elements:\n";

        for(int i = 0; i < size; i++)
        {
            cout << heap[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    PriorityQueue pq;

    pq.enqueueWithPriority(30);
    pq.enqueueWithPriority(50);
    pq.enqueueWithPriority(10);
    pq.enqueueWithPriority(40);

    pq.display();

    cout << "\nHighest Priority Removed: "
         << pq.dequeueHighestPriority();

    pq.display();

    return 0;
}