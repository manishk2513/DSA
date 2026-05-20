#include <iostream>
using namespace std;

#define SIZE 5

struct Element
{
    int value;
    int priority;
};

class PriorityQueue
{
    Element arr[SIZE];
    int count;

public:

    PriorityQueue()
    {
        count = 0;
    }

    // Insert element with priority
    void insert(int value, int priority)
    {
        if(count == SIZE)
        {
            cout << "Priority Queue Overflow\n";
            return;
        }

        arr[count].value = value;
        arr[count].priority = priority;

        count++;

        cout << value << " inserted with priority "
             << priority << endl;
    }

    // Get highest priority element
    void getHighestPriority()
    {
        if(count == 0)
        {
            cout << "Priority Queue is Empty\n";
            return;
        }

        int highest = 0;

        for(int i = 1; i < count; i++)
        {
            if(arr[i].priority > arr[highest].priority)
            {
                highest = i;
            }
        }

        cout << "Highest Priority Element: "
             << arr[highest].value << endl;
    }

    // Delete highest priority element
    void deleteHighestPriority()
    {
        if(count == 0)
        {
            cout << "Priority Queue is Empty\n";
            return;
        }

        int highest = 0;

        for(int i = 1; i < count; i++)
        {
            if(arr[i].priority > arr[highest].priority)
            {
                highest = i;
            }
        }

        cout << "Deleted Element: "
             << arr[highest].value << endl;

        // Shift elements left
        for(int i = highest; i < count - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        count--;
    }

    // Display queue
    void display()
    {
        if(count == 0)
        {
            cout << "Priority Queue is Empty\n";
            return;
        }

        cout << "\nElements in Priority Queue:\n";

        for(int i = 0; i < count; i++)
        {
            cout << "Value: "
                 << arr[i].value
                 << " Priority: "
                 << arr[i].priority
                 << endl;
        }
    }
};

int main()
{
    PriorityQueue pq;

    pq.insert(100, 2);
    pq.insert(200, 5);
    pq.insert(300, 1);
    pq.insert(400, 4);

    pq.display();

    pq.getHighestPriority();

    pq.deleteHighestPriority();

    pq.display();

    return 0;
}