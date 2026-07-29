// Q4: Find the second largest and second smallest elements in an array without sorting it.
#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    if (n < 2)
    {
        cout << "Need at least two elements.\n";
        delete[] arr;
        return 0;
    }

    int smallest = INT_MAX, secondSmallest = INT_MAX;
    int largest = INT_MIN, secondLargest = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int value = arr[i];

        if (value < smallest)
        {
            secondSmallest = smallest;
            smallest = value;
        }
        else if (value 
            > smallest && value < secondSmallest)
        {
            secondSmallest = value;
        }

        if (value > largest)
        {
            secondLargest = largest;
            largest = value;
        }
        else if (value < largest && value > secondLargest)
        {
            secondLargest = value;
        }
    }

    if (secondSmallest == INT_MAX)
    {
        cout << "Second smallest does not exist due to duplicate or insufficient distinct values.\n";
    }
    else
    {
        cout << "Second smallest element: " << secondSmallest << '\n';
    }

    if (secondLargest == INT_MIN)
    {
        cout << "Second largest does not exist due to duplicate or insufficient distinct values.\n";
    }
    else
    {
        cout << "Second largest element: " << secondLargest << '\n';
    }

    delete[] arr;
    return 0;
}