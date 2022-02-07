#include <iostream>
#include <queue>

using namespace std;

// A linked list node
class Node
{
public:
    int value;
    Node *next;
};

/* Given a reference (pointer to pointer) to the head
of a list and an int, appends a new node at the end */
void append(Node **head_ref, int new_value)
{
    /* 1. allocate node */
    Node *new_node = new Node();

    Node *last = *head_ref; /* used in step 5*/

    /* 2. put in the value */
    new_node->value = new_value;

    /* 3. This new node is going to be
    the last node, so make next of
    it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty,
    then make the new node as head */
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
    {
        last = last->next;
    }

    /* 6. Change the next of last node */
    last->next = new_node;
    return;
}

float IQR(Node *head)
{

    float IQR = 0;
    float Q1 = 0;
    float Q3 = 0;

    Node *t1 = head;
    Node *t2 = head;
    Node *t3 = head;

    Node *q = head;

    int t1Prev = 0;
    int t2Prev = 0;
    int t3Prev = 0;

    int counter = 1;

    while (q)
    {

        // the median is at the half way point
        if (counter % 2 == 0)
        {
            t2Prev = t2->value;
            t2 = t2->next;
        }
        // the q1 is quater way point
        if (counter % 4 == 0)
        {

            t1Prev = t1->value;
            t1 = t1->next;
            // cout << endl
            //      << "t1Prev = " << t1Prev << endl;
        }
        // cout<<"t3 = "<<t3->value<<endl;
        if (counter % 2 != 0 || counter % 3 == 0)
        {
            // cout<<"t3 = "<<t3->value<<endl;
            t3Prev = t3->value;
            t3 = t3->next;
        }
        // cout<<"t3 = "<<t3->value<<endl;

        counter++;

        q = q->next;
    }

    counter -= 1;
    // cout << endl
    //      << endl
    //      << "t1 = " << t1->value << "\tt2 = " << t2->value << "\tt3 = " << t3->value << "\tcounter = " << counter << " " << counter << " / 2 = " << counter / 3 << endl;
    // cout << endl
    //      << "t1Prev = " << t1Prev << "\tt2Prev = " << t2Prev << "\tt3Prev = " << t3Prev<<"\tt3->next = "<<t3->next->value << endl;

    // count is even
    if (counter % 2 == 0)
    {

        // cout << "here" << endl;
        Q1 = ((t1->value) + (t1Prev)) / 2.0;
        Q3 = ((t3->value) + (t3->next->value)) / 2.0;
        // cout<<"Q1 = "<<t1->value<<" + "<<t1Prev<<"/2.0 = "<<Q1<<endl;
        // cout<<"Q3 = "<<t3->value<<" + "<<t3->next->value<<"/2.0 = "<<Q3<<endl;

        if (counter == 10)
        {

            Q1 = t1->value;
            Q3 = t3->next->value;
        }

        if (counter == 4)
        {

            Q1 = ((t1->value) + (t1Prev)) / 2.0;

            Q3 = ((t3->value) + (t3->next->value)) / 2.0;
        }

        IQR = Q3 - Q1;
    }

    // count is odd
    else
    {
        // cout << "here" << endl;

        if (counter > 9)
        {

            Q1 = t1->value;
            Q3 = t3->next->value;
        }

        if (counter < 9)
        {

            // cout << "here 2" << endl;
            // cout << "t3 = " << t3->value << "\tt1 = " << t1->value << endl;
            Q1 = t1->value;
            Q3 = t3->value;
        }

        if (counter == 9)
        {
            Q1 = ((t1->value) + (t1Prev)) / 2.0;
            Q3 = ((t3->value) + (t3->next->value)) / 2.0;
        }

        IQR = Q3 - Q1;
    }
    return IQR;
}

// This function prints contents of
// linked list starting from head
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << " " << node->value;
        node = node->next;
    }

    cout << endl;
}



/* Driver code*/
int main()
{
    /* Start with the empty list */
    Node *head = NULL;

    // Insert 6. So linked list becomes 6->NULL
    // count = 10 even case, Q1 = 8 , Q3 = 2456

    append(&head, 1);
    append(&head, 8);
    append(&head, 15);
    append(&head, 43);
    append(&head, 82);
    append(&head, 101);
    append(&head, 110);
    append(&head, 2456);
    append(&head, 55345);
    append(&head, 137556);

    // count = 9 Q1 = 4, Q3 = 8.5 DONE

    // if LL = 2, 3, 4, 5, 6, 7, 8, 9, 10 then Q1 = 3.5 Q3 = 8.5 DONE

    // append(&head, 2);
    // append(&head, 3);
    // append(&head, 4);
    // append(&head, 5);
    // append(&head, 6);
    // append(&head, 7);
    // append(&head, 8);
    // append(&head, 9);
    // append(&head, 10);

    // count = 11, Q1 = 15, Q3 = 55345

    // append(&head, 1);
    // append(&head, 8);
    // append(&head, 15);
    // append(&head, 43);
    // append(&head, 82);
    // append(&head, 101);
    // append(&head, 110);
    // append(&head, 2456);
    // append(&head, 55345);
    // append(&head, 137556);
    // append(&head, 137576);

    // count = 7, Q1 = 3 Q2 = 7 DONE

    // append(&head, 2);
    // append(&head, 4);
    // append(&head, 4);
    // append(&head, 5);
    // append(&head, 6);
    // append(&head, 7);
    // append(&head, 8);

    // Counter = 4 Q1 = 1.5, Q3 = 3.5

    // append(&head, 1);
    // append(&head, 2);
    // append(&head, 3);
    // append(&head, 4);

    cout << "Created Linked list is: ";
    printList(head);

    cout << endl
         << "IQR is " << IQR(head);

    return 0;
}