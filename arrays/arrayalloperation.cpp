#include <iostream>
using namespace std;

class ArrayOperations
{
    int arr[100];
    int size;

public:

    // Constructor
    ArrayOperations()
    {
        size = 0;
    }

    // Create Array
    void createArray()
    {
        cout << "Enter number of elements: ";
        cin >> size;

        cout << "Enter elements:\n";

        for(int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
    }

    // Traversal
    void traverse()
    {
        cout << "\nArray Elements:\n";

        for(int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    // Insertion
    void insertElement()
    {
        int position, value;

        cout << "\nEnter position to insert: ";
        cin >> position;

        cout << "Enter value: ";
        cin >> value;

        // Shift elements to right
        for(int i = size; i >= position; i--)
        {
            arr[i] = arr[i - 1];
        }

        arr[position - 1] = value;

        size++;

        cout << "Element Inserted Successfully\n";
    }

    // Deletion
    void deleteElement()
    {
        int position;

        cout << "\nEnter position to delete: ";
        cin >> position;

        // Shift elements left
        for(int i = position - 1; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        size--;

        cout << "Element Deleted Successfully\n";
    }

    // Searching
    void searchElement()
    {
        int key;
        bool found = false;

        cout << "\nEnter element to search: ";
        cin >> key;

        for(int i = 0; i < size; i++)
        {
            if(arr[i] == key)
            {
                cout << "Element found at position: "
                     << i + 1 << endl;

                found = true;
                break;
            }
        }

        if(!found)
        {
            cout << "Element not found\n";
        }
    }

    // Updating
    void updateElement()
    {
        int position, newValue;

        cout << "\nEnter position to update: ";
        cin >> position;

        cout << "Enter new value: ";
        cin >> newValue;

        arr[position - 1] = newValue;

        cout << "Element Updated Successfully\n";
    }
};

int main()
{
    ArrayOperations obj;

    int choice;

    obj.createArray();

    do
    {
        cout << "\n========== ARRAY OPERATIONS ==========\n";

        cout << "1. Traversal\n";
        cout << "2. Insertion\n";
        cout << "3. Deletion\n";
        cout << "4. Searching\n";
        cout << "5. Updating\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                obj.traverse();
                break;

            case 2:
                obj.insertElement();
                obj.traverse();
                break;

            case 3:
                obj.deleteElement();
                obj.traverse();
                break;

            case 4:
                obj.searchElement();
                break;

            case 5:
                obj.updateElement();
                obj.traverse();
                break;

            case 6:
                cout << "Program Ended\n";
                break;

            default:
                cout << "Invalid Choice\n";
        }

    } while(choice != 6);

    return 0;
}