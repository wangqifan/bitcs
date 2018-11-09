#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int _val)
    {
        val = _val;
        next = NULL;
    }
};
void merge(ListNode *a, ListNode *b, ListNode *&c)
{
    if (c == NULL)
        c = new ListNode(0);
    ListNode *rear = c;
    if (a == NULL || a->next == NULL)
        c = b;
    if (b == NULL || b->next == NULL)
        c = a;
    a = a->next;
    b = b->next;
    while (a != NULL && b != NULL)
    {
        if (a->val < b->val)
        {
            rear->next = a;
            a = a->next;
        }
        else
        {
            rear->next = b;
            b = b->next;
        }
        rear = rear->next;
        rear->next = NULL;
    }
    if (a == NULL)
        rear->next = b;
    else
        rear->next = a;
}
void visited(ListNode *head)
{
    head = head->next;
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    ListNode *a = new ListNode(0);
    ListNode *rear = a;
    for (int i = 0; i < 10; i += 2)
    {
        ListNode *temp = new ListNode(i);
        rear->next = temp;
        rear = temp;
    }
    ListNode *b = new ListNode(0);
    rear = b;
    for (int i = 1; i < 10; i += 2)
    {
        ListNode *temp = new ListNode(i);
        rear->next = temp;
        rear = temp;
    }
    ListNode *c = NULL;
    visited(a);
    visited(b);
    merge(a, b, c);
    visited(c);
    return 0;
}