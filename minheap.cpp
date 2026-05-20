#include <iostream>
using namespace std;

class MinHeap
{
    int arr[100];
    int size;

public:

    MinHeap()
    {
        size = 0;
    }

    // Insert into Min Heap
    void insert(int value)
    {
        arr[size] = value;

        int index = size;

        size++;

        // Up Heapify
        while(index > 0)
        {
            int parent = (index - 1) / 2;

            if(arr[parent] > arr[index])
            {
                swap(arr[parent], arr[index]);

                index = parent;
            }

            else
            {
                break;
            }
        }
    }

    // Down Heapify
    void heapifyDown(int index)
    {
        int smallest = index;

        int left = 2 * index + 1;
        int right = 2 * index + 2;

        // Compare left child
        if(left < size &&
           arr[left] < arr[smallest])
        {
            smallest = left;
        }

        // Compare right child
        if(right < size &&
           arr[right] < arr[smallest])
        {
            smallest = right;
        }

        // Swap if needed
        if(smallest != index)
        {
            swap(arr[index], arr[smallest]);

            heapifyDown(smallest);
        }
    }

    // Extract minimum element
    int extractMin()
    {
        if(size == 0)
        {
            cout << "Heap is Empty\n";
            return -1;
        }

        int minElement = arr[0];

        arr[0] = arr[size - 1];

        size--;

        heapifyDown(0);

        return minElement;
    }

    // Get minimum element
    int getMin()
    {
        if(size == 0)
        {
            cout << "Heap is Empty\n";
            return -1;
        }

        return arr[0];
    }

    // Display heap
    void display()
    {
        for(int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    MinHeap h;

    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(40);
    h.insert(2);

    cout << "Min Heap:\n";

    h.display();

    cout << "\nMinimum Element: "
         << h.getMin();

    cout << "\n\nExtracted Minimum: "
         << h.extractMin();

    cout << "\nHeap after extraction:\n";

    h.display();

    return 0;
}