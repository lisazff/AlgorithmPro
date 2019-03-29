//
//  main.cpp
//  leetcode-21合并两个有序链表
//
//  Created by 佐毅 on 2018/3/19.
//  Copyright © 2018年 dfjr. All rights reserved.
//

/*
 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
 
 示例：
 
 输入：1->2->4, 1->3->4
 输出：1->1->2->3->4->4
 */


#include <iostream>
#include <vector>


using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
};


void MYPrint(ListNode *p)   //打印链表
{
    while(p!=NULL)
    {
        cout<<p->val<<" ";
        
        p=p->next;
    }
    cout<<endl<<endl;
    return;
}


ListNode *CreateLinkList(int myarray[],int num)
{
    
    //将数组myarray中的内容传递给链表
    //链表
    ListNode *head,*p,*lins = nullptr;  //首先建立一个头指针head指向链表的最开始。。当链表还没有建立的时候头指针为空。
    head=NULL;    //头指针初始为空
    for(int i=0; i<=num-1; i++)
    {
        //建立一个结点，并用临时指针p指向这个结点。
        p = new ListNode ;
        p->val = myarray[i];   //将数据存储到当前结点的data域中
        p->next = NULL;    //设置当前结点的后继指针指向空，也就是当前结点的下一个结点为空。
        
        if(head==NULL)
        {
            head=p;   //如果这是第一个创建的结点，则将头指针指向这个结点
        }
        else
        {
            lins->next=p; //如果这不是第一个创建的结点，则将上一个结点的后继指针指向当前结点
        }
        lins=p;  //指针lins也指向当前结点.
    }
    return head;
    
}

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    ListNode* newpHead=NULL;
    if(pHead1==NULL&&pHead2==NULL)
        return NULL;
    if(pHead1==NULL)
        return pHead2;
    if(pHead2==NULL)
        return pHead1;
    
    if(pHead1->val<pHead2->val)
    {
        newpHead=pHead1;
        pHead1=pHead1->next;
        newpHead->next=Merge(pHead1,pHead2);
    }
    else
    {
        newpHead=pHead2;
        pHead2=pHead2->next;
        newpHead->next=Merge(pHead1, pHead2);
    }
    return newpHead;
}

int main(int argc, const char * argv[]) {
   
    int myarray1[]={1,3,5,7};
    int myarray2[]={1,2,4,6,7,8};
    
    int num1=sizeof(myarray1)/sizeof(int);
    int num2=sizeof(myarray2)/sizeof(int);
    
    ListNode *head1,*head2,*newHead;
    
    head1=CreateLinkList(myarray1,num1);
    cout<<"链表1内容为："<<endl;
    MYPrint(head1);
    
    cout<<"链表2内容为："<<endl;
    head2=CreateLinkList(myarray2,num2);
    MYPrint(head2);
    
    cout<<"合并后链表内容为："<<endl;
    newHead=Merge(head1, head2);
    MYPrint(newHead);
    
    return 0;
}
