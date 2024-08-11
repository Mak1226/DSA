#include <bits/stdc++.h>
#include "node.h"
using namespace std;

void createLinkedList(vector<int> v);
void insertNode(Node *head, int target, int pos);
void deleteNode(Node *head, int pos);
void countNode(Node *head);
void searchNode(Node *head, int target);

int main()
{
    int choice;
    cout << 
    "1. Create List\n"
    "2.Insert Node\n"
    "3.Delete Node\n"
    "4.Find Length\n"
    "5.Search Element" 
    << endl;
    cin >> choice;
    Node *head;
    switch (choice)
    {
    case 1:
    {
        cout << "Test Case 1" << endl;
        cout << "1 2 3 4 5" << endl;
        createLinkedList({1, 2, 3, 4, 5});
        cout << "Test Case 2" << endl;
        cout << "1" << endl;
        createLinkedList({1});
        break;
    }
    case 2:
    {
        cout << "Test Case 1" << endl;
        cout << "1 2 4 5\nTarget: 3 3rd" << endl;
        head = Node::createList({1, 2, 4, 5});
        insertNode(head, 3, 3);
        cout << "Test Case 2" << endl;
        cout << "2 3 4 5\nTarget: 1 1st" << endl;
        head = Node::createList({2, 3, 4, 5});
        insertNode(head, 1, 1);
        cout << "Test Case 3" << endl;
        cout << "1 2 3 4\nTarget: 5 5th" << endl;
        head = Node::createList({1, 2, 3, 4});
        insertNode(head, 5, 5);
        break;
    }
    case 3:
    {
        cout << "Test Case 1" << endl;
        cout << "1 2 3 4 5\nTarget: 1st" << endl;
        head = Node::createList({1, 2, 3, 4, 5});
        deleteNode(head, 1);
        cout << "Test Case 2" << endl;
        cout << "1 2 3 4 5\nTarget: 5th" << endl;
        head = Node::createList({1, 2, 3, 4, 5});
        deleteNode(head, 5);
        cout << "Test Case 3" << endl;
        cout << "1 2 3 4 5\nTarget: 3rd" << endl;
        head = Node::createList({1, 2, 3, 4, 5});
        deleteNode(head, 3);
        break;
    }
    case 4:
    {
        cout << "Test Case 1" << endl;
        cout << "1 2 3 4 5" << endl;
        head = Node::createList({1, 2, 3, 4, 5});
        countNode(head);
        cout << "Test Case 2" << endl;
        cout << "1" << endl;
        head = Node::createList({1});
        countNode(head);
        cout << "Test Case 3" << endl;
        cout << "1 2 3 4 5 6 7 8" << endl;
        head = Node::createList({1, 2, 3, 4, 5, 6, 7, 8});
        countNode(head);
        break;
    }
    case 5:
    {

        cout << "Test Case 1" << endl;
        cout << "1 2 3 4 5\nTarget: 5" << endl;
        head = Node::createList({1, 2, 3, 4, 5});
        searchNode(head, 5);
        cout << "Test Case 2" << endl;
        cout << "1\nTarget: 5" << endl;
        head = Node::createList({1});
        searchNode(head, 5);
        cout << "Test Case 3" << endl;
        cout << "1 2 3 4 5 6 7 8\nTarget: 1" << endl;
        head = Node::createList({1, 2, 3, 4, 5, 6, 7, 8});
        searchNode(head, 1);
        break;
    }
    default:
        break;
    }
    return 0;
}
void createLinkedList(vector<int> v)
{
    Node *head = Node::createList(v);
    Node::display(head);
}
void insertNode(Node *head, int target, int pos)
{
    Node *temp = new Node(target);
    if (!head)
        if (pos == 1)
            head = temp;
    if (pos == 1)
    {
        temp->next = head;
        head = temp;
    }
    int i = 0;
    Node *it = head;
    while (it)
    {
        i++;
        if (i == pos - 1)
        {
            temp->next = it->next;
            it->next = temp;
            break;
        }
        it = it->next;
    }
    Node::display(head);
}
void deleteNode(Node *head, int pos)
{
    if (!head || (!head->next && pos == 1))
    {
        cout << nullptr << endl;
        return;
    }
    else if (pos == 1)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        Node::display(head);
        return;
    }
    Node *it = head;
    int i = 1;
    while (it)
    {
        if (i == pos - 1)
        {
            Node *temp = it->next;
            it->next = temp->next;
            free(temp);
            break;
        }
        i++;
        it = it->next;
    }
    Node::display(head);
}
void countNode(Node *head)
{
    int c = 0;
    Node *it = head;
    while (it)
    {
        c++;
        it = it->next;
    }
    cout << c << endl;
}
void searchNode(Node *head, int target)
{
    Node *it = head;
    while (it)
    {
        if (it->data == target)
        {
            cout << true << endl;
            return;
        }
        it = it->next;
    }
    cout << false << endl;
}
