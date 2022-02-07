#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next = NULL;
};

Node *insertToLinkedList(Node *head, int data)
{
    Node *newNode = new Node();
    newNode->value = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
void displayLinkedList(Node *head)
{
    Node *temp = head;
    cout << "\nLinked list is : ";
    while (temp != NULL)
    {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

void interQuartile(Node *head)
{
    Node *q1 = head;
    Node *q2 = head; // median
    Node *q3 = head;

    Node *temp = head;

    int count = 1;
    int tempData;
    int q1Data;
    int q2Data;
    int q3Data;
    while (temp)
    {
        // cout<<"\n\ntemp = "<<temp->value;
        // cout<<"\tq1 = "<<q1->value;
        // cout<<"\tq2 = "<<q2->value;
        // cout<<"\tq3 = "<<q3->value;
        tempData = temp->value;
        q1Data = q1->value;
        q2Data = q2->value;
        q3Data = q3->value;

        temp = temp->next;

        if (count % 2 == 0)
        {
            q2 = q2->next;
            // q3 = q3->next;
        }
        if (count % 3 == 0)
        {
            q3 = q3->next;
        }
        if (count % 4 == 0)
        {
            q1 = q1->next;
        }

        count++;
        // q1 = q1->next;
        // q2 = q2->next->next;
        // q3 = q3->next->next->next;
        // temp = q3;
    }
    if (q3)
        q3Data = q3->value;
    cout << "\n\ntemp = " << tempData;
    cout << "\tq1 = " << q1Data;
    cout << "\tq2 = " << q2Data;
    cout << "\tq3 = " << q3Data;
}

int main()
{
    Node *head;
    for (int j = 0; j < 10; j++)
    {
        int n = j + 4;
        head = NULL;
        for (int i = 1; i <= n; i++)
        {
            head = insertToLinkedList(head, i);
        }
        displayLinkedList(head);

        interQuartile(head);
        cout << endl;
    }

    return 0;
}