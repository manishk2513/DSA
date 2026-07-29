// Q5: Store N numbers in an array and search for a particular number using linear search.
#include <iostream>
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

    int key;
    cout << "Enter element to search: ";
    cin >> key;

    int position = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            position = i + 1;
            break;
        }
    }

    if (position != -1)
    {
        cout << "Element found at position " << position << ".\n";
    }
    else
    {
        cout << "Element not found.\n";
    }

    delete[] arr;
    return 0;
}