#include <iostream>
#include <vector>
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

ListNode *buildlist(vector<int> &nums)
{
    if (nums.size() == 0)
        return NULL;
    ListNode *head = new ListNode(nums[0]);
    ListNode *rear = head;
    for (int i = 1; i < nums.size(); i++)
    {
        ListNode *temp = new ListNode(nums[i]);
        rear->next = temp;
        rear = temp;
    }
    return head;
}
bool ListNodeInsert(ListNode *&L, int i, int val)
{
    if (i < 1)
        return false;
    ListNode *temp = new ListNode(val);
    if (i == 1)
    {
        temp->next = L;
        L = temp;
        return true;
    }
    int index = 1;
    ListNode *node = L;

    while (node != NULL)
    {
        if (index + 1 == i)
        {
            temp->next = node->next;
            node->next = temp;
            return true;
        }
        index++;
        node = node->next;
    }
    return false;
}
void visited(ListNode *L)
{
    while (L != NULL)
    {
        cout << L->val << " ";
        L = L->next;
    }
    cout << endl;
}
int main()
{
    vector<int> nums;
    ListNode *head = buildlist(nums);
    visited(head);
    ListNodeInsert(head, -1, 1);
    visited(head);

    nums.push_back(1);
    head = buildlist(nums);
    visited(head);
    ListNodeInsert(head, -1, 1);
    visited(head);
    ListNodeInsert(head, 1, 2);
    visited(head);
    ListNodeInsert(head, 4, 4);
    visited(head);
    ListNodeInsert(head, 3, 3);
    visited(head);
    return 0;
}
