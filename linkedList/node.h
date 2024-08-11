#ifndef NODE_H
#define NODE_H

#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
    Node() : data(0), next(nullptr), prev(nullptr) {}

    static void display(Node *head)
    {
        Node *it = head;
        while (it)
        {
            cout << it->data << " ";
            it = it->next;
        }
        cout << endl;
    }
    static Node *createList(const vector<int> &v)
    {
        if (v.empty())
            return nullptr;
        bool flag = true;
        Node *head = nullptr;
        Node *itr = nullptr;
        for (auto it : v)
        {
            if (flag)
            {
                head = new Node(it);
                itr = head;
                flag = false;
            }
            else
            {
                Node *temp = new Node(it);
                itr->next = temp;
                temp->prev = itr;
                itr = itr->next;
            }
        }
        return head;
    }
};

#endif