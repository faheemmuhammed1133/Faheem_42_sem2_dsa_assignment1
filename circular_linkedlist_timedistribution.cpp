/*1.Round-Robin Scheduling: (Please follow the different constraints as
discussed in the class)
-Simulate a round-robin scheduling for a set of users in an department for
printing task.
-Users are represented by nodes in a circular linked list, and each iteration
of the algorithm selects the next user in the circle.
-Other customisations if you want to add*/


#include <iostream>
#include <string>
using namespace std;

class Task
{
public:
    string name;
    float minutes;
    Task *next;
    Task()
    {
        float time;
        cout << "Enter User name: ";
        cin >> name;
        cout << "Enter time for the user(in hour): ";
        cin >> time;
        minutes= time*60;
        next = NULL;
    }
};

Task *createList(int n)
{
    Task *start = NULL;
    Task *ptr = NULL;
    for (int i = 0; i < n; i++)
    {
        Task *newTask = new Task();
        if (start == NULL)
        {
            start = newTask;
            ptr = newTask;
        }
        else
        {
            ptr->next = newTask;
            ptr = ptr->next;
        }
    }
    ptr->next = start;
    return start;
}

void scheduling(Task *&a, float &n)
{
    float b;
    cout << "Enter the number of hours per round: ";
    cin >> b;
    b=b*60;
    while (b >= n || b <= 0.0)
    {
        cout << "Invalid time. Enter the number of hours per round: ";
        cin >> b;
    }
    Task *ptr = a;
    Task *preptr = ptr;
    Task *temp = ptr;
    if (a == NULL)
    {
        cout << "No users available for scheduling.\n";
        return;
    }
    else
    {
        while (n > 0.0 && a != NULL)
        {
            if (ptr->minutes <= b)
            {
                if (ptr->minutes > n)
                {
                    ptr->minutes -= n;
                    n = 0.0;
                }
                else
                {
                    n -= ptr->minutes;
                    ptr->minutes = 0;
                }
            }
            else
            {
                ptr->minutes -= b;
                n -= b;
            }
            if (ptr->minutes <= 0.0)
            {
                cout << "User " << ptr->name << " task completed successfully\n";
                if (ptr == a && ptr->next == a)
                {
                    delete ptr;
                    a = NULL;
                    cout << "All users work is done\nTotal time left: " << n/60 << endl;
                    return;
                }
                if (ptr->next == a)
                {
                    preptr->next = a;
                }
                else if (ptr == a)
                {
                    temp = ptr;
                    while (temp->next != a)
                    {
                        temp = temp->next;
                    }
                    a = ptr->next;
                    temp->next = a;
                }
                else
                {
                    preptr->next = ptr->next;
                }
                temp = ptr;
                ptr = ptr->next;
                cout<<temp->name<<" \n";  // tezting phase
                delete temp;
            }
            else
            {
                preptr = ptr;
                ptr = ptr->next;
            }
        }
        if (n <= 0.0 && a != NULL)
        {
            cout << "Time over\n";
            ptr = a;
            do
            {
                if (ptr == a && ptr->next == a)
                {
                    cout << "User " << ptr->name << " work is left(" << (ptr->minutes)/60 << " hours)\n";
                    return;
                }
                cout << "User " << ptr->name << " work is left(" << (ptr->minutes)/60 << " hours)\n";
                ptr = ptr->next;
            } while (ptr->next != a);
        }
    }
}

void deleteList(Task *&a)
{
    if (a == NULL)
    {
        return;
    }
    Task *ptr = a;
    Task *temp = NULL;
    do
    {
        temp = ptr;
        ptr = ptr->next;
        delete temp;
    } while (ptr != a);
    a = NULL;
}

int main()
{
    float time;
    cout << "Enter total printing time available(in hour): ";
    cin >> time;
    while (time <= 0.0)
    {
        cout << "Invalid time. Enter total appropriate time(in hour): ";
        cin >> time;
    }
    time=time*60;
    int n;
    cout << "Enter number of users: ";
    cin >> n;
    while (n <= 0)
    {
        cout << "Invalid number of users. Enter appropriate number of users: ";
        cin >> n;
    }
    Task *start = createList(n);
    scheduling(start, time);
    deleteList(start);
    return 0;
}