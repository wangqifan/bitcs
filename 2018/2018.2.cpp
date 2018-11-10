#include <iostream>
#include <stack>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int _val)
    {
        val = _val;
        left = right = NULL;
    }
};
void inorder(TreeNode *root)
{
    if (root == NULL)
        return;
    stack<TreeNode *> s;
    TreeNode *p = root;
    while (p != NULL || !s.empty())
    {
        if (p != NULL)
        {
            s.push(p);
            p = p->left;
        }
        else
        {
            p = s.top();
            s.pop();
            cout << p->val << " ";
            p = p->right;
        }
    }
}
int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *root1 = new TreeNode(2);
    TreeNode *root2 = new TreeNode(3);
    TreeNode *root3 = new TreeNode(4);
    TreeNode *root4 = new TreeNode(5);
    root->left = root1;
    root->right = root2;
    root1->left = root3;
    root1->right = root4;
    inorder(root);
    return 0;
}