#include <iostream>
#include "../Header Files/Stack.h"
#include "../Header Files/StackComponent.h"
#include "../Header Files/CircularBuffer.h"
#include "../Header Files/QueueUsingCurcularBuffer.h"
#include "../Header Files/QueueUsingStack.h"

using namespace std;

// TODO: Падает на втором добавлении в очередь на двух стеках
// TODO: Некорректно выводит очередь на кольцевом буфере
int GetValue()
{
    int value = -1;
    while (true)
    {
        if (cin >> value)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        else
        {
            cout << "Unknown command. Try entering the command again" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void PrintStack(Stack& stack) 
{
    if (stack.IsEmpty())
    {
        cout << "Stack is empty." << endl;
        return;
    }

    StackComponent* current = stack.Top();

    cout << "Current stack elements (top to bottom): ";

    while (current != nullptr) 
    {
        cout << current->Value << " ";
        current = current->Next;
    }

    cout << endl;
}

void PrintCircularBuffer(CircularBuffer& buffer)
{
    int* array = buffer.Buffer();

    cout << "Current circular buffer elements: ";
    for (int i = 0; i < buffer.OccupiedSpace(); i++)
    {
        cout << array[i] << " ";
    }

    cout << endl;
}

void PrintQueueUsingCircularBuffer(QueueUsingCircularBuffer& queue)
{
    PrintCircularBuffer(*queue.Buffer());
}

void PrintQueueUsingStack(QueueUsingStack& queue)
{
    Stack stack1 = queue.Stack1();
    Stack stack2 = queue.Stack2();
    PrintStack(stack1);
    PrintStack(stack2);
}

void DisplayMenu()
{
    cout << "Select the action you want to do:" << endl;
    cout << "1. Stack" << endl;
    cout << "2. Circular Buffer" << endl;
    cout << "3. Queue using Circular Buffer" << endl;
    cout << "4. Queue using Stack" << endl;
}

void StackMenu()
{
    // TODO: Использовать динамическую память (во всех структурах). Не забыть про очистку памяти
    Stack stack;

    int choice, value;

    do
    {
        cout << "Select the action you want to do:" << endl;
        cout << "1. Insert new element" << endl;
        cout << "2. Remove element" << endl;
        cout << "3. Back to main menu" << endl;
        cout << "Your choice: " << endl;
        choice = GetValue();

        switch (choice)
        {
        case 1:
        {
            cout << "New element: " << endl;
            cin >> value;
            stack.Push(value);
            cout << "Added a new element" << endl;
            PrintStack(stack);
            break;
        }

        case 2:
        {
            if (stack.IsEmpty())
            {
                cout << "Stack is empty" << endl;
                break;
            }

            value = stack.Pop();
            cout << "Removed element: " << value << endl;
            PrintStack(stack);
            break;
        }   

        case 3:
        {
            stack.~Stack();
            break;
        }

        default:
        { 
            cout << "Unknown command. Try entering the command again" << endl;
            break;
        }
        
        }
    } while (choice != 3);
}

void CircularBufferMenu()
{
    CircularBuffer circularBuffer(10);

    int choice, value;

    do
    {
        cout << "Select the action you want to do:" << endl;
        cout << "1. Insert new element" << endl;
        cout << "2. Remove element" << endl;
        cout << "3. Resize" << endl;
        cout << "4. Back to main menu" << endl;
        cout << "Your choice: " << endl;
        choice = GetValue();

        switch (choice)
        {
        case 1:
        {
            cout << "New element: " << endl;
            cin >> value;
            circularBuffer.Insert(value);
            cout << "Added a new element. Size: " << circularBuffer.OccupiedSpace() << endl;
            PrintCircularBuffer(circularBuffer);
            break;
        }

        case 2:
        {
            if (circularBuffer.OccupiedSpace() == 0)
            {
                cout << "Circular buffer is empty" << endl;
                break;
            }

            value = circularBuffer.GetValue();
            cout << "Removed element: " << value << ". Size: " << circularBuffer.OccupiedSpace() << endl;
            PrintCircularBuffer(circularBuffer);
            break;
        }

        case 3:
        {
            cout << "New capacity: " << endl;
            cin >> value;
            if (circularBuffer.FreeSpace() == 0)
            {
                cout << "The size has not been changed" << endl;
                break;
            }
            
            circularBuffer.Resize(value);
            cout << "Resized" << endl;
            break;
        }

        default:
        {
            if (choice != 4)
            {
                cout << "Unknown command. Try entering the command again" << endl;
            }

            break;
        }
        }
    } while (choice != 4);
}

void QueueUsingCircularBufferMenu()
{
    QueueUsingCircularBuffer queue(10);

    int choice, value;

    do
    {
        cout << "Select the action you want to do:" << endl;
        cout << "1. Insert new element" << endl;
        cout << "2. Remove element" << endl;
        cout << "3. Back to main menu" << endl;
        cout << "Your choice: " << endl;
        choice = GetValue();

        
        switch (choice)
        {
        case 1:
        {
            cout << "New element: " << endl;
            cin >> value;
            queue.Enqueue(value);
            cout << "Added a new element. Size: " << queue.Size() << endl;
            PrintQueueUsingCircularBuffer(queue);
            break;
        }

        case 2:
        {
            if (queue.Size() == 0)
            {
                cout << "Queue is empty" << endl;
                break;
            }

            value = queue.Dequeue();
            cout << "Removed element: " << value << ". Size: " << queue.Size() << endl;
            PrintQueueUsingCircularBuffer(queue);
            break;
        }

        case 3:
        {
            break;
        }

        default:
        {
            if (choice != 3)
            {
                cout << "Unknown command. Try entering the command again" << endl;
            }

            break;
        }

        }
    } while (choice != 3);
}


void QueueUsingStackMenu()
{
    QueueUsingStack queue;

    int choice, value;

    do
    {
        cout << "Select the action you want to do:" << endl;
        cout << "1. Insert new element" << endl;
        cout << "2. Remove element" << endl;
        cout << "3. Back to main menu" << endl;
        cout << "Your choice: " << endl;
        choice = GetValue();

        switch (choice)
        {
        case 1:
        {
            cout << "New element: " << endl;
            cin >> value;
            queue.Enqueue(value);
            cout << "Added a new element" << endl;
            PrintQueueUsingStack(queue);
            break;
        }

        case 2:
        {
            if (queue.IsEmpty())
            {
                cout << "Queue is empty" << endl;
                break;
            }

            value = queue.Dequeue();
            cout << "Removed element: " << value << endl;
            PrintQueueUsingStack(queue);
            break;
        }

        case 3:
        {
            queue.~QueueUsingStack();
            break;
        }

        default:
        {
            cout << "Unknown command. Try entering the command again" << endl;
            break;
        }

        }
    } while (choice != 3);
}

void main()
{
    int choice, value;

    do
    {
        DisplayMenu();
        cout << "Your choice: " << endl;
        choice = GetValue();

        switch (choice)
        {
        case 1:
        {
            StackMenu();
            break;
        }

        case 2:
        {
            CircularBufferMenu();
            break;
        }

        case 3:
        {
            QueueUsingCircularBufferMenu();
            break;
        }

        case 4:
        {
            QueueUsingStackMenu();
            break;
        }

        default:
        {
            cout << "Unknown command. Try entering the command again" << endl;
            break;
        }

        } 

    } while (choice != 5);
}