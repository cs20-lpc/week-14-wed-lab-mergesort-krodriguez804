#include <iostream>
using namespace std;

/*
## Reflection Questions

1. What is the time complexity of Merge Sort?
    O(n lg (n))
2. Why does Merge Sort work well with linked lists?
    No shifting needed. Arrays require copying. Linked lists just
    change pointers.
3. Is Merge Sort stable? 
    Yes
4. What extra memory does Merge Sort require?
    Recursion stack
*/

struct Node
{
    int data;
    Node* next;
};

void insertEnd(Node*& head, int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void display(Node* head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* sortedMerge(Node* a, Node* b)
{
    // TODO:
    // Merge two sorted linked lists
    // Base case. If one list is null, the other is sorted.
    if (a == NULL) {
        return b;
    }
    
    if (b == NULL) {
        return a;
    }

    Node* c = NULL;

    if (a->data <= b->data) {
        c = a;

        // recursive call to find what comes next
        c->next = sortedMerge(a->next, b); 
    }
    else {
        c = b;
        
        c->next = sortedMerge(a, b->next);
    }

    return c;
}

void splitList(Node* source, Node*& front, Node*& back)
{
    // TODO:
    // Use slow/fast pointer method
    Node* slow = source;
    Node* fast = source->next;

    // Split list into two halves
    while (fast != NULL) {
        fast = fast->next;

        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    front = source;
    back = slow->next;
    slow->next = NULL;
}

void mergeSort(Node*& head)
{
    if (head == NULL || head->next == NULL)
        return;

    Node* a;
    Node* b;

    // TODO:
    // Split list
    splitList(head, a, b);

    // Recursively sort both halves
    mergeSort(a);
    mergeSort(b);

    // Merge sorted lists
    // sortedMerge returns a pointer.
    // This updates head pointer after merging.
    head = sortedMerge(a, b); 
}

int main()
{
    Node* head = NULL;

    int values[10] = {38, 27, 43, 3, 9, 82, 10, 5, 61, 14};

    for (int i = 0; i < 10; i++)
        insertEnd(head, values[i]);

    cout << "Before Sorting: ";
    display(head);

    mergeSort(head);

    cout << "After Sorting: ";
    display(head);

    return 0;
}
