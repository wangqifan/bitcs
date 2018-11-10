#include<iostream>
#include<vector>
using namespace std;
void quicksort(vector<int> &nums,int left,int right)
{
      if(left>=right)return;
      int vol=nums[right];
      int l=left-1;
      for(int i=left;i<right;i++)
      {
            if(nums[i]<vol)
            {
                l++;
                swap(nums[l],nums[i]);
            }
      }
      l++;
      swap(nums[right],nums[l]);
      quicksort(nums,left,l-1);
      quicksort(nums,l+1,right);
}
int main()
{
    vector<int> nums;
    for(int i=10;i>=0;i--)
    {
        nums.push_back(i);
    }
    quicksort(nums,0,nums.size()-1);
    for(int i=0;i<nums.size();i++)cout<<nums[i]<<" ";
    return 0;
}