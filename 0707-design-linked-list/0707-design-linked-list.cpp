
class Node
{
public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        next = nullptr;
    }
};

class MyLinkedList
{
private:
    Node *head;
    int size = 0;

public:
    MyLinkedList()
    {
        head = nullptr;
    }

    int get(int index)
    {
        if (index < 0 || index >= size)
        {
            return -1;
        }
        Node *current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current->val;
    }

    void addAtHead(int val)
    {
        Node *temp = new Node(val);
        temp->next = head;
        head = temp;
        size++;
    }

    void addAtTail(int val)
    {
        if (head == nullptr)
        {
            Node *temp = new Node(val);
            head = temp;
            size++;
            return;
        }
        Node *temp = new Node(val);
        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = temp;
        temp->next = nullptr;
        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > size)
        {
            return;
        }
        Node *temp = new Node(val);
        if (index == 0)
        {
            temp->next = head;
            head = temp;
            size++;
            return;
        }

        Node *current = head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
        temp->next = current->next;
        current->next = temp;

        size++;
    }

    void deleteAtIndex(int index)
    {

        if (index < 0 || index >= size)
        {
            return;
        }
        Node *current = head;
        if (index == 0)
        {
            head = head->next;
            delete current;
            size--;
            return;
        }

        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
        Node *nodeToDelete = current->next;
        current->next = nodeToDelete->next;
        delete nodeToDelete;
        size--;
    }
};
