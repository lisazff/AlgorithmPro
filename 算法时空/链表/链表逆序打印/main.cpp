//
//  main.cpp
//  链表逆序打印
//
//  Created by 佐毅 on 2019/12/19.
//  Copyright © 2019年 dfjr. All rights reserved.
//



/*
 如何将链表逆序，取决于题目的要求。如果面试官只要求打印，一般不改动链表结构为好，如果要求改变链表的方向，则需要改变结构，再顺序打印。
 
 方法1：只逆序打印，不改变结构。采用递归，到达尾结点时打印输出，否则进入下一个结点的递归，当递归一层层退出的时候，便可以实现从尾到头的打印。
 
 方法2：头插法，改变结构。从第二个结点开始往后，依次把每个结点移至链表头部，要注意最后链表不要是断裂的。
 
 方法3：改变指针方向。从头结点开始，依次把结点的next指针断开指向该结点的前结点。要注意保存好，前结点、当前结点和下一个结点。
 
 方法4：只逆序打印，不改变结构。利用栈的后进先出来实现逆序。
 */

#include<iostream>
using namespace std;
struct ListNode
{
    int value;
    ListNode *next;
};
void ReversePrint(ListNode *pHead) //递归实现逆序打印（不改变链表结构）
{
    if(pHead!=NULL)
    {
        if(pHead->next!=NULL){
            ReversePrint(pHead->next);
        }
        cout<<pHead->value<<" ";
    }
}
ListNode *ReverseList1(ListNode *pHead)//头插法（改变链表结构）
{
    if(pHead==NULL)
        return NULL;
    ListNode *p=pHead->next;
    ListNode *newHead=pHead;
    
    while(p!=NULL){            //将p结点移到链表最前方
        pHead->next=p->next;//头结点指向p的下一个结点
        p->next=newHead;    //p插入链表最前方
        newHead=p;        //链表新头结点更新为p
        p=pHead->next;//处理下一个结点，该结点位于头结点后
    }
    return newHead;
}
ListNode *ReverseList2(ListNode *pHead)//依次改变指针方向（改变链表结构）
{
    ListNode *pre=NULL;
    ListNode *p=NULL;
    while(pHead!=NULL){
        p=pHead->next;    //保存剩余链表
        pHead->next=pre;//断开剩余链表头结点pHead，指向pre
        pre=pHead;    //pre更新
        pHead=p;    //head更新
    }
    return pre;
}




int main()//主函数
{
    int n;
    cin>>n;    //输入元素个数
    ListNode* head=NULL;
    ListNode* p=NULL;
    ListNode* q=NULL;
    for(int i=0;i<n;i++)//分配内存，依次输入元素
    {
        q=new ListNode;
        cin>>q->value;
        if(head==NULL)
        {
            head=q;
            p=head;
        }
        else
        {
            p->next=q;
            p=p->next;
        }
    }
    if(head==NULL)
        return 0;
    p->next=NULL;
    //验证
    cout<<"递归逆序打印: "<<endl;
    ReversePrint(head);
    cout<<endl<<"头插法反转链表: "<<endl;
    ListNode* reverseHead;
    reverseHead = ReverseList1(head);
    p=reverseHead;
    while(p!=NULL)
    {
        cout<<p->value<<" ";
        p=p->next;
    }
    cout<<endl<<"改变指针方向反转链表（将链表再次反转）: "<<endl;
    p = ReverseList2(reverseHead);    //改变指针方向反转链表
    while(p!=NULL)
    {
        cout<<p->value<<" ";
        q=p;
        p=p->next;
        delete q;//释放内存
    }
    cout<<endl;
    return 0;
}

