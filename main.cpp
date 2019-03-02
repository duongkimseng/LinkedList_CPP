#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>

struct Node
{
    int data;
    Node *next;
};

class Linked_List
{
private:
    Node *head, *tail;

public:
    Linked_List();
    void Random_List();
    void Add_Tail(int d);
    void Add_Head(int d);
    void Add_Pos(int pos, int d);
    void Delete_Head();
    void Delete_Tail();
    void Delete_Pos(int pos);
    void Sort_Node();
    void Display();
};

Linked_List::Linked_List()
{
    head = NULL;
    tail = NULL;
}

void Linked_List::Random_List()
{
    int d, pos;
    srand((int) time(0));
    pos = (rand()%3)+3;
    for (int i = 1; i <= pos; i++)
    {
        Node *tmp = new Node;
        d = (rand()%100) + 1;
        tmp->data = d;
        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
            tail->next = head;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
            tail->next = head;
        }
        delete tmp;
    }
}

void Linked_List::Add_Head(int d)
{
    Node *tmp = new Node;
    tmp->data = d;
    if(head == NULL)
    {
        head = tmp;
        tail = tmp;
        tail -> next = head;
    }
    else
    {
        tmp->next = head;
        head = tmp;
        tail->next = head;
    }

}

void Linked_List::Add_Tail(int d)
{
    Node *tmp = new Node;
    tmp->data = d;

    if(head == NULL)
    {
        head = tmp;
        tail = tmp;
        tail->next = head;
    }
    else
    {
        tail->next = tmp;
        tail = tail->next;
        tail->next = head;
    }
}

void Linked_List::Add_Pos(int pos, int d)
{
    Node *prev = new Node;
    Node *curr = new Node;
    Node *tmp = new Node;
    tmp->data = d;
    curr = head;
    for(int i = 1; i < pos; i++)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = tmp;
    tmp->next = curr;

}

void Linked_List::Delete_Head()
{
    Node *tmp = new Node;
    tmp = head;
    if(tmp->next == head)
    {
        head = NULL;
    }
    else
    {
        head = tmp->next;
        tail->next=head;
    }
    delete tmp;
}

void Linked_List::Delete_Tail()
{
    Node *prev = new Node;
    Node *curr = new Node;
    curr = head;

    do
    {
        prev = curr;
        curr = curr->next;
    }while(curr->next != head);
    tail = prev;
    prev->next = head;
    delete curr;
}

void Linked_List::Delete_Pos(int pos)
{
    Node *prev = new Node;
    Node *curr = new Node;
    curr = head;

    for(int i = 1; i < pos; i++)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
}

void Linked_List::Sort_Node()
{
    Node *tmp = new Node;
    Node *curr = new Node;
    curr = head;
    while(curr->next != head)
    {
        tmp = curr->next;

        while(tmp != head)
        {
            if(curr->data > tmp->data)
                std::swap(curr->data, tmp->data);
            tmp = tmp->next;
        }

        curr = curr->next;
    }
    delete tmp;
    delete curr;
}


void Linked_List::Display()
{
    Node *tmp = new Node;
    tmp = head;

    if(head == NULL)
    {
        std::cout << "Empty";
    }

    else
    {
        do
        {
            std::cout << tmp->data << '\t';
            tmp = tmp->next;
        }while(tmp != head);
        std::cout << tail->next->data;
    }
    std::cout << "\n\n\n";
}

int main()
{
    Linked_List ll;
    ll.Random_List();

    char S1, S2;
    int pos, da;

    while(S1 != 'q')
    {
        system("CLS");
        std::cout << "List : ";
        ll.Display();

        std::cout << "1. Insert \n"
                << "2. Delete \n"
                << "3. Sort \n"
                << "Q. Quit" << "\n\n";

        std::cout << "Input : ";
        std::cin >> S1;
        S1 = std::tolower(S1);

        switch(S1)
        {
        case '1': //add case
            system("CLS");
            std::cout << "List : ";
            ll.Display();
            std::cout << "Add : \n" << "1. Head\n" << "2. Tail\n" << "3. Specific Position" << "\n\n";
            std::cout << "Input : ";
            std::cin >> S2;
            S2 = std::tolower(S2);
            std::cout << "\n\n";
            switch(S2)
            {
            case '1': //add Node
                std::cout << "Input Data : ";
                std::cin >> da;
                ll.Add_Head(da);
                break;

            case '2': //add to head
                std::cout << "Input Data : ";
                std::cin >> da;
                ll.Add_Tail(da);
                break;

            case '3': //add to specific position
                std::cout << "Input Position : ";
                std::cin >> pos;
                std::cout << "Input Data : ";
                std::cin >> da;
                ll.Add_Pos(pos, da);
                break;

            default: //out of cases
                std::cout << "Invalid Input!!!";
                system("PAUSE");
                break;
            }
            break;

        case '2': //delete case
            system("CLS");
            std::cout << "List : ";
            ll.Display();
            std::cout << "Delete : \n" << "1. Head\n" << "2. Tail\n" << "3. Specific Position" << "\n\n";
            std::cout << "Input : ";
            std::cin >> S2;
            S2 = std::tolower(S2);
            std::cout << "\n\n";
            switch(S2)
            {
            case '1': //delete head
                ll.Delete_Head();
                break;

            case '2': //delete tail
                ll.Delete_Tail();
                break;

            case '3': //delete specific position
                std::cout << "Input Position : ";
                std::cin >> pos;
                ll.Delete_Pos(pos);
                break;

            default: //out of cases
                std::cout << "Invalid Input!!!" << std::endl;
                system("PAUSE");
                break;
            }
            break;

        case '3': //sort case
            ll.Sort_Node();
            break;

        case 'q': //quit case
            std::cout << "Thank You!!" << std::endl;
            break;

        default: //wrong case input
            std::cout << "Invalid Input, " << "Please Try Again!!!" << std::endl;
            system("PAUSE");

            break;
        }
    }


    return 0;
}
