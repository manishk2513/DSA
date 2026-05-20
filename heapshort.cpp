#include <iostream>
using namespace std;

// Heapify function
void heapify(int arr[],
             int n,
             int index)
{
    int largest = index;

    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // Compare left child
    if(left < n &&
       arr[left] > arr[largest])
    {
        largest = left;
    }

    // Compare right child
    if(right < n &&
       arr[right] > arr[largest])
    {
        largest = right;
    }

    // Swap if needed
    if(largest != index)
    {
        swap(arr[index],
             arr[largest]);

        // Heapify affected subtree
        heapify(arr,
                n,
                largest);
    }
}

// Heap Sort Function
void heapSort(int arr[],
              int n)
{
    // Build Max Heap
    for(int i = n / 2 - 1;
        i >= 0;
        i--)
    {
        heapify(arr,
                n,
                i);
    }

    // Extract elements one by one
    for(int i = n - 1;
        i > 0;
        i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Heapify reduced heap
        heapify(arr,
                i,
                0);
    }
}

// Display Array
void display(int arr[],
             int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main()
{
    int arr[] =
    {
        40, 10, 30, 50, 20
    };

    int n = 5;

    cout << "Original Array:\n";

    display(arr, n);

    heapSort(arr, n);

    cout << "\nSorted Array:\n";

    display(arr, n);

    return 0;
}
