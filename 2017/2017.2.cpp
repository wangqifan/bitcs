#include<vector>
#include<string>

//牛客网上面已经通过了   https://www.nowcoder.com/practice/c77ac599d0764433a5946610a7626768
//原理  就是横着竖着，斜着不能在一块哦  ，你就一个一个试试
//每一排放一个
//每一排可以放8个，8个有的地方不可以放，不可以放就跳过
//可以放的话我们这里就有一个分支继续去下一排试试，如果没有合适地方可以放 那么这条路断了  
//本质上就是一棵多叉树 从根往下找呗 
class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string>> result;
        vector<int> C(n,-1);
        dfs(result,C,0);
        return result;
    }
    
    void dfs(vector<vector<string>> &result,vector<int> &C,int row)
    {
        if(row==C.size())  //已经到8了 跳出递归
        { 
            vector<string> solution;
            for(int i=0;i<C.size();i++)
            {
                string s(C.size(),'.');
                s[C[i]]='Q';
                solution.push_back(s);
            }
            result.push_back(solution);
         }
        for(int i=0;i<C.size();i++)
        {
            if(isvaild(C,row,i))//如果这个可以放的话，放一个试试，这里开一个分支下去继续试试
            {
               C[row]=i;
                dfs(result,C,row+1);
            }
        }
    }
    bool isvaild(vector<int> &C,int row,int col)//判断是否符合要求
    {
        for(int i=0;i<row;i++)
        {
            if(col==C[i])return false;
            if(abs(row-i)==abs(col-C[i]))return false;
        }
        return true;
    }
};