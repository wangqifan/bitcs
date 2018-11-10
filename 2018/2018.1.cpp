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
void deletmin(ListNode *&head)
{
    if (head == NULL)
        return;
    int min = head->val;     //记录最小值
    ListNode *minptr = head; //记录最小值前一个节点
    ListNode *index = head;
    while (index->next != NULL)
    {
        if (index->next->val < min)
        {
            min = index->next->val;
            minptr = index;
        }
        index = index->next;
    }
    if (min == head->val)
        head = head->next;
    else
    {
        minptr->next = minptr->next->next;
    }
}
int main()
{
    ListNode *head = new ListNode(3);
    ListNode *temp = new ListNode(2);
    head->next = temp;
    deletmin(head);
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}