#include <iostream>

using namespace std;

bool isoperator(char x)
{
    if (x == '*' || x == '-' || x == '+' || x == '/')
        return true;

    return false;
}

int resolveOperator(char ope, int n1, int n2)
{
    int result = 0;
    if (ope == '+')
    {
        result = n1 + n2;
    }
    else if (ope == '-')
    {
        result = n1 - n2;
    }
    else if (ope == '*')
    {
        result = n1 * n2;
    }
    else
    {
        result = n1 / n2;
    }
    return result;
}

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
};

class Stak
{
public:
    Node *Top;
    Stak()
    {
        Top = NULL;
    }

    bool isempty()
    {
        return (this->Top == NULL);
    }

    void push(int item)
    {
        Node *newNode = new Node();
        newNode->data = item;
        if (isempty())
        {
            newNode->next = NULL;
            this->Top = newNode;
        }
        else
        {
            newNode->next = this->Top;
            this->Top = newNode;
        }
    }

    void displaydata()
    {
        int counter = 1;
        Node *temp = this->Top;
        while (temp != NULL)
        {
            cout << "The stak whose index is " << counter << ": " << temp->data << endl;
            temp = temp->next;
            counter++;
        }
        delete temp;
    }
    dvfvfdvdv

    int pop()
    {
        int value = this->Top->data;
        Node *temp = this->Top;
        Top = Top->next;
        delete temp;
        return value;
    }

    int peek()
    {
        return this->Top->data;
    }
};

int resolveExpression(string Expression)
{
    Stak stack;
    for (int i = 0; i < Expression.length(); i++)
    {
        char ch = Expression[i];
        if (!isoperator(ch) && isdigit(ch))
        {
            stack.push(int(ch - '0'));
        }
        else
        {
            int number1 = stack.pop();
            int number2 = stack.pop();

            stack.push(resolveOperator(ch, number1, number2));
        }
    }
    int result = stack.pop();

    return result;
}
int main()
{
    string EX = "42*5+";
    cout << resolveExpression(EX);
}