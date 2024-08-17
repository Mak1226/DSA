#include <bits/stdc++.h>
#include "node.h"
using namespace std;

void reverseListGroups(Node *head, int k);
void rotateList(Node *head, int target);
void flattenList(Node *head);
void cloneList(Node *head);
Node* createChildList(vector<vector<int>> v);
Node* createRandomList(vector<int> v);

int main()
{
    cout << "1.Reverse LL in groups\n2.Rotate LL\n3.Flatten LL\n4.Clone LL" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        cout << "Test Case 1" << endl;
        cout << "1 2 3 4 5 6 7 8\nTarget: 3" << endl;
        Node *head = Node::createList({1, 2, 3, 4, 5, 6, 7, 8});
        reverseListGroups(head, 3);
        cout << "Test Case 2" << endl;
        cout << "1 2 3 4 5 6 7 8 9\nTarget: 4" << endl;
        head = Node::createList({1, 2, 3, 4, 5, 6, 7, 8, 9});
        reverseListGroups(head, 4);
        break;
    }
    case 2:
    {
        cout << "Test Case 1" << endl;
        cout << "1 2 3 4 5 6 7 8\nTarget: 40" << endl;
        Node *head = Node::createList({1, 2, 3, 4, 5, 6, 7, 8});
        rotateList(head, 40);
        cout << "Test Case 2" << endl;
        cout << "1 2 3 4 5 6 7 8 9\nTarget: 6" << endl;
        head = Node::createList({1, 2, 3, 4, 5, 6, 7, 8, 9});
        rotateList(head, 6);
        break;
    }
    case 3:
    {
        cout << "Test Case 1" << endl;
        cout << "1 2 3 4\n3 6 9 12\n2 4 6 8\n4 8 12 16" << endl;
        Node *head = createChildList({{1, 2, 3, 4}, {3, 6, 9, 12}, {2, 4, 6, 8}, {4, 8, 12, 16}});
        flattenList(head);
        cout << "Test Case 2" << endl;
        cout << "5 6\n3 4\n1 2" << endl;
        head = createChildList({{5, 6}, {3, 4}, {1, 2}});
        flattenList(head);
        break;
    }
    case 4:
    {
        cout << "Test Case 1" << endl;
        cout << "1 2 3 4\n3 6 9 12\n2 4 6 8\n4 8 12 16" << endl;
        Node *head = createChildList({{1, 2, 3, 4}, {3, 6, 9, 12}, {2, 4, 6, 8}, {4, 8, 12, 16}});
        flattenList(head);
        cout << "Test Case 2" << endl;
        cout << "5 6\n3 4\n1 2" << endl;
        head = createChildList({{5, 6}, {3, 4}, {1, 2}});
        flattenList(head);
        break;
    }
    default:
        break;
    }
    return 0;
}
Node *reverseList(Node *head)
{
    if (!head || !head->next)
        return head;
    Node *newHead = reverseList(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}
Node *findKNode(Node *head, int k)
{
    int c = 1;
    Node *it = head;
    while (it)
    {
        if (c == k)
            return it;
        c++;
        it = it->next;
    }
    return nullptr;
}
void reverseListGroups(Node *head, int k)
{
    Node *it = head, *prevNode = nullptr;
    while (it)
    {
        Node *kNode = findKNode(it, k);
        if (!kNode)
            if (prevNode)
            {
                prevNode->next = it;
                break;
            }

        Node *nextNode = kNode->next;
        kNode->next = nullptr;
        reverseList(it);
        if (it == head)
            head = kNode;
        else
            prevNode->next = kNode;
        prevNode = it;
        it = nextNode;
    }
    Node::display(head);
}
void rotateList(Node *head, int target)
{
    int c = 1;
    Node *it = head;
    while (it->next)
    {
        c++;
        it = it->next;
    }
    it->next = head;
    int r = target % c;
    int rotate = c - r;
    if (!rotate)
    {
        Node::display(head);
        return;
    }
    it = head;
    while (--rotate)
        it = it->next;
    head = it->next;
    it->next = nullptr;
    Node::display(head);
}
Node *createChildList(vector<vector<int>> v)
{
    Node *dummy = new Node();
    Node *row = dummy;
    for (auto itr : v)
    {
        bool flag = true;
        Node *col;
        for (auto it : itr)
        {
            Node *temp = new Node(it);
            if (flag)
            {
                row->next = temp;
                row = temp;
                col = temp;
                flag = false;
            }
            else
            {
                col->prev = temp;
                col = col->prev;
            }
        }
    }
    /*
    Node *head = dummy->next;
    Node *it = head;
    while(it)
    {
        Node *itr = it;
        while(itr)
        {
            cout << itr->data << " ";
            itr = itr->prev;
        }
        cout << endl;
        it = it->next;
    }
    */
    return dummy->next;
}
Node *flat(Node *list1, Node *list2)
{
    Node *dummy = new Node();
    Node *res = dummy;
    while (list1 && list2)
    {
        if (list1->data < list2->data)
        {
            res->prev = list1;
            res = list1;
            list1 = list1->prev;
        }
        else
        {
            res->prev = list2;
            res = list2;
            list2 = list2->prev;
        }
        res->next = nullptr;
    }
    if (list1)
        res->prev = list1;
    else
        res->prev = list2;
    if (dummy->prev)
        dummy->prev->next = nullptr;
    return dummy->prev;
}
Node *flatten(Node *head)
{
    if (!head || !head->next)
        return head;
    Node *mergeHead = flatten(head->next);
    head = flat(head, mergeHead);
    return head;
}
void flattenList(Node *head)
{
    head = flatten(head);
    Node *it = head;
    while(it)
    {
        cout << it->data << " ";
        it = it->prev;
    }
    cout << endl;
}
Node* createRandomList(vector<int> v)
{
    Node *itr = nullptr, *head;
    map<int, Node*> m;
    for(int it: v)
    {
        Node *temp = new Node(it);
        if(!itr)
        {
            itr = temp;
            head = temp;
        }
        else
        {
            itr->next = temp;
            itr = itr->next;
        }
        m[it] = itr;
    }
    int l = v.size() / 2;
    int i=1;
    while(i<=l)
    {
        m[i]->prev = m[2*i];
        i++;
    }
    m[i++]->prev = nullptr;
    while(i<=v.size())
    {
        m[i]->prev = m[i-1];
        i++;
    }
    Node::display(head);
    Node *it = head;
    while(it)
    {
        if(it->prev)
            cout << it->prev->data << endl;
        it = it->next;
    }
    cout << endl;
    return head;
}