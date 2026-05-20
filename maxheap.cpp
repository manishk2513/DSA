#include <iostream>
using namespace std;

class MaxHeap
{
    int arr[100];
    int size;

public:

    MaxHeap()
    {
        size = 0;
    }

    // Insert into heap
    void insert(int value)
    {
        arr[size] = value;

        int index = size;

        size++;

        // Up Heapify
        while(index > 0)
        {
            int parent = (index - 1) / 2;

            if(arr[parent] < arr[index])
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
        int largest = index;

        int left = 2 * index + 1;
        int right = 2 * index + 2;

        // Compare left child
        if(left < size &&
           arr[left] > arr[largest])
        {
            largest = left;
        }

        // Compare right child
        if(right < size &&
           arr[right] > arr[largest])
        {
            largest = right;
        }

        // Swap if needed
        if(largest != index)
        {
            swap(arr[index], arr[largest]);

            heapifyDown(largest);
        }
    }

    // Extract maximum element
    int extractMax()
    {
        if(size == 0)
        {
            cout << "Heap is Empty\n";
            return -1;
        }

        int maxElement = arr[0];

        arr[0] = arr[size - 1];

        size--;

        heapifyDown(0);

        return maxElement;
    }

    // Get maximum element
    int getMax()
    {
        if(size == 0)
        {
            cout << "Heap is Empty\n";
            return -1;
        }

        return arr[0];
    }

    // Build heap from array
    void buildHeap(int input[],
                   int n)
    {
        size = n;

        for(int i = 0; i < n; i++)
        {
            arr[i] = input[i];
        }

        // Start from last non-leaf node
        for(int i = n / 2 - 1;
            i >= 0; i--)
        {
            heapifyDown(i);
        }
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
    MaxHeap h;

    h.insert(50);
    h.insert(30);
    h.insert(40);
    h.insert(60);

    cout << "Heap after insertion:\n";

    h.display();

    cout << "\nMaximum Element: "
         << h.getMax();

    cout << "\n\nExtracted Max: "
         << h.extractMax();

    cout << "\nHeap after extraction:\n";

    h.display();

    int arr[] = {10, 40, 20, 5, 30};

    int n = 5;

    h.buildHeap(arr, n);

    cout << "\nHeap after heapify:\n";

    h.display();

    return 0;
}