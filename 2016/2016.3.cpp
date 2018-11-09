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
void insertsort(ListNode *head) //带头节点
{
    ListNode *p, *q, *r, *u;
    p = head->next; //万一head是NULL嗯，题目竟然不先判空 渣渣
    head->next = NULL;
    while (p != NULL)
    {
        r = head;
        q = head->next;
        while (q != NULL && q->val <= p->val)
        {
            r = q;
            q = q->next;
        }
        u = p->next;
        p->next = r->next;
        r->next = p;
        p = u;
    }
}
int main()
{
    return 0;
}