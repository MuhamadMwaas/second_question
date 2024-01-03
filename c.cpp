#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Linked_listsdfsdf
{
public:
    Node *head;
    Linked_list()
    {
        head = NULL;
    }

    bool isempty()
    {
        return (this->head == NULL);
    }

    void insertFirst(int value)
    {
        Node *newNode = new Node();

        newNode->data = value;
        if (isempty())
        {
            newNode->next = NULL;
        }
        else
        {
            newNode->next = head;
        }
        this->head = newNode;
    }

    void displaydata()
    {
        int counter = 0;
        Node *temp = this->head;
        while (temp != NULL)
        {
            cout << "The node whose index is " << counter << ": " << temp->data << endl;
            temp = temp->next;
            counter++;
        }
        delete temp;
    }

    int count()
    {

        int counter = 0;
        Node *temp = this->head;
        while (temp != NULL)
        {
            temp = temp->next;
            counter++;
        }

        return counter;
    }

    bool inlist(int item)
    {
        bool result = false;
        Node *temp = this->head;
        while (temp != NULL)
        {
            if (temp->data == item)
            {
                result = true;
                break;
            }
            temp = temp->next;
        }
        delete temp;
        return result;
    }

    int get_by_index(int index)
    {
        int counter = 0;
        if (index >= 0)
        {
            Node *temp = this->head;
            while (temp != NULL)
            {
                if (counter == index)
                {
                    return temp->data;
                }
                temp = temp->next;
                counter++;
            }
            if (counter < index)
            {
                cout << "index out of rang the linked list has [" << counter << "] item";
            }
            delete temp;
        }
    }

    int *ToArray()
    {
        int size = count();
        int *a = new int[size];
        int i = 0;
        Node *temp = this->head;
        while (temp != NULL)
        {
            a[i] = temp->data;
            temp = temp->next;
            i++;
        }
        delete temp;
        return a;
    }

    void append(int value)
    {
        if (isempty())
        {
            insertFirst(value);
        }
        else
        {
            Node *temp = this->head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            Node *newNode = new Node();
            newNode->data = value;
            newNode->next = NULL;
            temp->next = newNode;
            delete temp;
        }
    }
};

int main()
{
    Linked_list list;
    list.insertFirst(1);
    list.insertFirst(2);
    list.insertFirst(3);
    list.insertFirst(4);
    list.insertFirst(5);
    list.displaydata();
    cout << list.count();
}