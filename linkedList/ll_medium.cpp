#include <bits/stdc++.h>
#include "node.h"
using namespace std;

void reverseDLL(Node *head);
void addTwoNum(Node *head1, Node *head2);
void nodeOddEven(Node *head);
void sortZeroOneTwo(Node *head);
void removeNthNodeFromLast(Node *head, int k);
void reverseListIterative(Node *head);
void reverseListRecursive(Node *head);
void middleOfList(Node *head);
void deleteMiddle(Node *head);
void palindromeList(Node *head);
void addOne(Node *head);
void intersectionNode(Node *head1, Node *head2);
void createIntersectionNode(Node *head1, Node *head2);
void createLoop(Node *head, int pos);
void detectLoop(Node *head);
void lengthLoop(Node *head);
void startNodeLoop(Node *head);

int main()
{
    int choice;
    cout << "1.Reverse DLL\n"
            "2.Add 2 Lists\n"
            "3.Odd Even Nodes\n"
            "4.Sort 0 1 2\n"
            "5.Remove Nth Node From Last\n"
            "6.Reverse List\n"
            "7.Middle of List\n"
            "8.Remove Middle Mode\n"
            "9.Palindrome List\n"
            "10.Add One to List\n"
            "11.Intersection of Nodes\n"
            "12.Detect Loop\n"
            "13.Length of Loop\n"
            "14.Loop Starting Point"
         << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        cout << "Test Case 1" << endl;
        cout << "5" << endl;
        Node *test1 = Node::createList({5});
        reverseDLL(test1);
        cout << "Test Case 2" << endl;
        cout << "1 2 3 4 5" << endl;
        Node *test2 = Node::createList({1, 2, 3, 4, 5});
        reverseDLL(test2);
        break;
    }
    case 2:
    {
        cout << "Test Case 1" << endl;
        cout << "1 2 3\n4 5 6" << endl;
        Node *head1 = Node::createList({1, 2, 3});
        Node *head2 = Node::createList({4, 5, 6});
        addTwoNum(head1, head2);
        cout << "Test Case 2" << endl;
        cout << "1 2 3 4\n5 6 7 8 9" << endl;
        head1 = Node::createList({1, 2, 3, 4});
        head2 = Node::createList({5, 6, 7, 8, 9});
        addTwoNum(head1, head2);
        break;
    }
    case 3:
    {
        cout << "Test Case 1" << endl;
        cout << "1 2 3 4 5 6 7" << endl;
        Node *head = Node::createList({1, 2, 3, 4, 5, 6, 7});
        nodeOddEven(head);
        cout << "Test Case 2" << endl;
        cout << "1 2 3 4 5 6 7 8" << endl;
        head = Node::createList({1, 2, 3, 4, 5, 6, 7, 8});
        nodeOddEven(head);
        break;
    }
    case 4:
    {
        cout << "Test Case 1" << endl;
        cout << "0 2 1 1 2 0 0 2 1" << endl;
        Node *head = Node::createList({0, 2, 1, 1, 2, 0, 0, 2, 1});
        sortZeroOneTwo(head);
        cout << "Test Case 2" << endl;
        cout << "2 1 0" << endl;
        head = Node::createList({2, 1, 0});
        sortZeroOneTwo(head);
        break;
    }
    case 5:
    {
        cout << "Test Case 1" << endl;
        cout << "8 7 6 5 4 3 2 1\nTarget: 5" << endl;
        Node *head = Node::createList({8, 7, 6, 5, 4, 3, 2, 1});
        removeNthNodeFromLast(head, 5);
        cout << "Test Case 2" << endl;
        cout << "8 7 6 5 4 3 2 1\nTarget: 8" << endl;
        head = Node::createList({8, 7, 6, 5, 4, 3, 2, 1});
        removeNthNodeFromLast(head, 8);
        break;
    }
    case 6:
    {
        cout << "Test Case 1" << endl;
        cout << "1 2 3 4 5" << endl;
        Node *head = Node::createList({1, 2, 3, 4, 5});
        reverseListIterative(head);
        cout << "Test Case 2" << endl;
        cout << "1 2 3 4 5" << endl;
        head = Node::createList({1, 2, 3, 4, 5});
        reverseListRecursive(head);
        break;
    }
    case 7:
    {
        cout << "Test Case 1" << endl;
        cout << "1 2 3 4 5" << endl;
        Node *head = Node::createList({1, 2, 3, 4, 5});
        middleOfList(head);
        cout << "Test Case 2" << endl;
        cout << "1 2 3 4 5 6" << endl;
        head = Node::createList({1, 2, 3, 4, 5, 6});
        middleOfList(head);
        break;
    }
    case 8:
    {
        cout << "Test Case 1" << endl;
        cout << "1 2 3 4 5" << endl;
        Node *head = Node::createList({1, 2, 3, 4, 5});
        deleteMiddle(head);
        cout << "Test Case 2" << endl;
        cout << "1 2 3 4 5 6" << endl;
        head = Node::createList({1, 2, 3, 4, 5, 6});
        deleteMiddle(head);
        cout << "Test Case 3" << endl;
        cout << "1" << endl;
        head = Node::createList({1});
        deleteMiddle(head);
        cout << "Test Case 4" << endl;
        cout << "{}" << endl;
        head = Node::createList({});
        deleteMiddle(head);
        break;
    }
    case 9:
    {
        cout << "Test Case 1" << endl;
        cout << "1 2 3 2 1" << endl;
        Node *head = Node::createList({1, 2, 3, 2, 1});
        palindromeList(head);
        cout << "Test Case 2" << endl;
        cout << "1 2 3 3 2 1" << endl;
        head = Node::createList({1, 2, 3, 3, 2, 1});
        palindromeList(head);
        cout << "Test Case 3" << endl;
        cout << "1 2 3 4 5" << endl;
        head = Node::createList({1, 2, 3, 4, 5});
        palindromeList(head);
        cout << "Test Case 4" << endl;
        cout << "1 2 3 4 5 6" << endl;
        head = Node::createList({1, 2, 3, 4, 5, 6});
        palindromeList(head);
        break;
    }
    case 10:
    {
        cout << "Test Case 1" << endl;
        cout << "1 2 3 9 9" << endl;
        Node *head = Node::createList({1, 2, 3, 9, 9});
        addOne(head);
        cout << "Test Case 2" << endl;
        cout << "9 9 9 9 9" << endl;
        head = Node::createList({9, 9, 9, 9, 9});
        addOne(head);
        break;
    }
    case 11:
    {
        cout << "Test Case 1" << endl;
        cout << "1 2 3 4 5\n1 2" << endl;
        Node *head1 = Node::createList({1, 2, 3, 4, 5});
        Node *head2 = Node::createList({1, 2});
        createIntersectionNode(head1, head2);
        intersectionNode(head1, head2);
        cout << "Test Case 2" << endl;
        cout << "1 2 3 4 5\n1 2 3 4 5" << endl;
        head1 = Node::createList({1, 2, 3, 4, 5});
        head2 = Node::createList({1, 2, 3, 4, 5});
        intersectionNode(head1, head2);
        break;
    }
    case 12:
    {
        cout << "Test Case 1" << endl;
        cout << "1 2 3 4 5 6 7 8" << endl;
        Node *head = Node::createList({1, 2, 3, 4, 5, 6, 7, 8});
        createLoop(head, 4);
        detectLoop(head);
        cout << "Test Case 2" << endl;
        cout << "1 2 3 4 5" << endl;
        head = Node::createList({1, 2, 3, 4, 5});
        detectLoop(head);
        break;
    }
    case 13:
    {
        cout << "Test Case 1" << endl;
        cout << "1 2 3 4 5 6 7 8" << endl;
        Node *head = Node::createList({1, 2, 3, 4, 5, 6, 7, 8});
        createLoop(head, 4);
        lengthLoop(head);
        cout << "Test Case 2" << endl;
        cout << "1 2 3 4 5 6" << endl;
        head = Node::createList({1, 2, 3, 4, 5, 6});
        createLoop(head, 4);
        lengthLoop(head);
        break;
    }
    case 14:
    {
        cout << "Test Case 1" << endl;
        cout << "1 2 3 4 5 6 7 8" << endl;
        Node *head = Node::createList({1, 2, 3, 4, 5, 6, 7, 8});
        createLoop(head, 4);
        startNodeLoop(head);
        cout << "Test Case 2" << endl;
        cout << "1 2 3 4 5 6" << endl;
        head = Node::createList({1, 2, 3, 4, 5, 6});
        createLoop(head, 4);
        startNodeLoop(head);
        break;
    }
    default:
        break;
    }
    return 0;
}
void reverseDLL(Node *head)
{
    Node *it = head;
    Node *last;
    if (!head || !head->next)
    {
        Node::display(head);
        return;
    }
    while (it)
    {
        last = it->prev;
        it->prev = it->next;
        it->next = last;
        it = it->prev;
    }
    head = last->prev;
    Node::display(head);
}
void addTwoNum(Node *head1, Node *head2)
{
    Node *it1 = head1;
    Node *it2 = head2;
    Node *dummyNode = new Node();
    Node *itr = dummyNode;
    int c = 0;
    while (it1 || it2)
    {
        int sum = c;
        if (it1)
        {
            sum += it1->data;
            it1 = it1->next;
        }
        if (it2)
        {
            sum += it2->data;
            it2 = it2->next;
        }
        c = sum / 10;
        Node *temp = new Node(sum % 10);
        itr->next = temp;
        itr = itr->next;
    }
    if (c)
    {
        Node *temp = new Node(c);
        itr->next = temp;
        itr = itr->next;
    }
    Node::display(dummyNode->next);
}
void nodeOddEven(Node *head)
{
    Node *odd = head;
    Node *even = head->next;
    Node *head_even = even;
    while (even && even->next)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = head_even;
    Node::display(head);
    /*
    while(odd && even)
    {
        odd->next = even->next ? even->next : nullptr;
        odd = even->next ? odd->next : odd;
        even->next = odd->next ? odd->next : nullptr;
        even = even->next;
    }
    odd->next = head_even
    */
}
void sortZeroOneTwo(Node *head)
{
    if (!head || !head->next)
    {
        Node::display(head);
        return;
    }
    Node *zeroHead = new Node();
    Node *oneHead = new Node();
    Node *twoHead = new Node();
    Node *zero = zeroHead, *one = oneHead, *two = twoHead;
    Node *it = head;
    while (it)
    {
        if (it->data == 0)
        {
            zero->next = it;
            zero = zero->next;
        }
        else if (it->data == 1)
        {
            one->next = it;
            one = one->next;
        }
        else
        {
            two->next = it;
            two = two->next;
        }
        it = it->next;
    }
    zero->next = oneHead->next ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = nullptr;
    Node *newHead = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    Node::display(newHead);
}
void removeNthNodeFromLast(Node *head, int k)
{
    Node *fast = head, *slow = head;
    while (k--)
        fast = fast->next;
    if (!fast)
    {
        Node::display(head->next);
        return;
    }
    while (fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    Node *deleteNode = slow->next;
    slow->next = slow->next->next;
    delete deleteNode;
    Node::display(head);
}
void reverseListIterative(Node *head)
{
    Node *it = head;
    Node *prev = nullptr, *front;
    while (it)
    {
        front = it->next;
        it->next = prev;
        prev = it;
        it = front;
    }
    Node::display(prev);
}
Node *reverseListRec(Node *head)
{
    if (!head || !head->next)
        return head;
    Node *newHead = reverseListRec(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = nullptr;
    return newHead;
}
void reverseListRecursive(Node *head)
{
    head = reverseListRec(head);
    Node::display(head);
}
Node *middleNode(Node *head)
{
    Node *fast = head, *slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
void middleOfList(Node *head)
{
    Node *middle = middleNode(head);
    cout << middle->data << endl;
}
void deleteMiddle(Node *head)
{
    if (!head || !head->next)
    {
        cout << nullptr << endl;
        return;
    }
    Node *dummy = new Node();
    dummy->next = head;
    Node *fast = head, *slow = dummy;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
    delete dummy;
    Node::display(head);
}
void palindromeList(Node *head)
{
    if (!head->next)
    {
        cout << true << endl;
        return;
    }
    Node *revList = reverseListRec(middleNode(head));
    // Node::display(revList);
    Node *frwd = head, *bkwd = revList;
    while (bkwd)
    {
        if (frwd->data != bkwd->data)
        {
            cout << false << endl;
            Node *newHead = reverseListRec(revList);
            // Node::display(head);
            return;
        }
        frwd = frwd->next;
        bkwd = bkwd->next;
    }
    Node *newHead = reverseListRec(revList);
    cout << true << endl;
    // Node::display(head);
}
int addOneRec(Node *head)
{
    if (!head)
        return 1;
    int carry = addOneRec(head->next);
    int sum = head->data + carry;
    head->data = sum % 10;
    return sum / 10;
}
void addOne(Node *head)
{
    int carry = addOneRec(head);
    if (carry)
    {
        Node *temp = new Node(carry);
        temp->next = head;
        head = temp;
    }
    Node::display(head);
}
void createIntersectionNode(Node *head1, Node *head2)
{
    Node *it1 = head1, *it2 = head2;
    while (it2->next)
        it2 = it2->next;
    while (it1)
    {
        if (it1->data == it2->data)
            break;
        it1 = it1->next;
    }
    it2->next = it1->next;
}
void intersectionNode(Node *head1, Node *head2)
{
    Node *it1 = head1, *it2 = head2;
    Node *temp;
    while (it1 != it2)
    {
        it1 = it1->next;
        it2 = it2->next;
        if (it1 == it2)
        {
            temp = it2;
            break;
        }
        if (!it1)
            it1 = head2;
        if (!it2)
            it2 = head1;
    }
    temp = it1;
    if (temp)
        cout << temp->data << endl;
    else
        cout << 0 << endl;
}
void createLoop(Node *head, int pos)
{
    Node *it = head;
    int c = 1;
    Node *temp;
    while (it->next)
    {
        if (c == pos)
            temp = it;
        c++;
        it = it->next;
    }
    if (c <= pos)
        return;
    else
        it->next = temp;
}
void detectLoop(Node *head)
{
    Node *fast = head, *slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            cout << true << endl;
            return;
        }
    }
    cout << false << endl;
}
int findLength(Node *fast, Node *slow)
{
    int c = 1;
    fast = fast->next;
    while (fast != slow)
    {
        c++;
        fast = fast->next;
    }
    return c;
}
void lengthLoop(Node *head)
{
    Node *fast = head, *slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            cout << findLength(fast, slow) << endl;
            return;
        }
    }
    cout << 0 << endl;
}
int startNode(Node *slow, Node *fast)
{
    while (fast != slow)
    {
        fast = fast->next;
        slow = slow->next;
        if (fast == slow)
            break;
    }
    return fast->data;
}
void startNodeLoop(Node *head)
{
    Node *fast = head, *slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            cout << startNode(head, fast) << endl;
            return;
        }
    }
    cout << 0 << endl;
}
