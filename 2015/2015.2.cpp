#include <iostream>
using namespace std;
struct node
{
    int val;
    node *pre, *next;
    node(int _val)
    {
        val = _val;
        pre = NULL;
        next = NULL;
    }
};
void InsertNode(node *&head, int i, node *s)
{
    if (head == NULL)
    {
        if (i == 1)
        {
            head = s;
            head->pre = NULL;
            head->next = NULL;
        }
        return;
    }
    if (i <= 0)
        return;
    if (i == 1)
    {
        head->pre = s;
        s->next = head;
        head = s;
        return;
    }
    int index = 1;
    node *cur = head;
    while (cur != NULL)
    {
        if (index == i - 1)
        {
            s->next = cur->next;
            s->pre = cur;
            if (cur->next != NULL)
                cur->next->pre = s;
            cur->next = s;
            break;
        }
        index++;
        cur = cur->next;
    }
}
void visited(node *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    node *head = NULL;
    node *temp = new node(1);
    InsertNode(head, 1, temp);
    visited(head);
    temp = new node(3);
    InsertNode(head, 2, temp);
    visited(head);
    temp = new node(2);
    InsertNode(head, 2, temp);
    visited(head);
    return 0;
}