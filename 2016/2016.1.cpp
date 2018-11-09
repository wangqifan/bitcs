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
void reverse(ListNode *head) //head指向头节点
{
    if (head == NULL)
        return;
    if (head->next == NULL)
        return;
    ListNode *node = head->next;
    while (node->next != NULL) //头插法
    {
        ListNode *temp = node->next;
        node->next = temp->next;
        temp->next = head->next;
        head->next = temp;
    }
}
void visited(ListNode *head)
{
    while (head->next != NULL)
    {
        cout << head->next->val << " ";
        head = head->next;
    }
    cout << endl;
}
int main()
{
    ListNode *head = new ListNode(0);
    ListNode *tail = head;
    for (int i = 0; i < 10; i++)
    {
        ListNode *temp = new ListNode(i + 1);
        tail->next = temp;
        tail = temp;
    }
    visited(head);
    reverse(head);
    visited(head);
}