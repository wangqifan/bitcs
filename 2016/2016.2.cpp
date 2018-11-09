#include<iostream>
using namespace std;
struct queue
{
    int *num;
    int count;
    int front;
    int m;
    queue(int _m)//m是队的长度
    { 
        m=_m;
        num=new int[m];
        count=0;
        front=-1;
    }
};
bool isempty(queue *q)
{
       return q->count==0;    
}
bool push(queue *q,int val)
{
    if(q->count==q->m)return false;//队列已满
    q->num[(q->front+q->count+1)%q->m]=val;
    q->count++;
    return true;
}
int pop(queue *q)
{
    if(isempty(q))//队列为空 无法出队
    {
        exit(0);
    }
    q->front=(q->front+1)%q->m;
    int val=q->num[q->front];
    q->count-=1;
    return val;
}
int main()
{
    queue *q=new queue(10);
    cout<<isempty(q)<<endl;
    for(int i=0;i<10;i++)
    {
        push(q,i);
    }
    for(int i=0;i<10;i++)
    {
        cout<<pop(q)<<"  ";
    }
    return 0;
}