#include <iostream>
#include <algorithm>
#include <vector>
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
//重点+++++++++++++++++++++++++++++++++++++++++++++++++++++++start
int getHeight(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right)); //记得加1！！！！！！！！！！！
}
//++++++++++++++end
TreeNode *buildfromVector(vector<int> &num, int left, int right)
{
    if (left > right)
        return NULL;
    int mid = (left + right) / 2;
    TreeNode *root = new TreeNode(num[mid]);
    root->left = buildfromVector(num, left, mid - 1);
    root->right = buildfromVector(num, mid + 1, right);
    return root;
}
int main()
{
    vector<int> num;
    TreeNode *root = buildfromVector(num, 0, num.size() - 1);
    cout << getHeight(root) << endl;
    num.push_back(1);
    root = buildfromVector(num, 0, num.size() - 1);
    cout << getHeight(root) << endl;
    num.push_back(2);
    num.push_back(3);
    num.push_back(4);
    root = buildfromVector(num, 0, num.size() - 1);
    cout << getHeight(root) << endl;
    return 0;
}
