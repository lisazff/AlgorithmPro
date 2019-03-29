//
//  main.cpp
//  leetcode-83删除排序链表中的重复元素
//
//  Created by 佐毅 on 2018/3/21.
//  Copyright © 2018年 dfjr. All rights reserved.
//


/*
 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 
 示例 1:
 
 输入: 1->1->2
 输出: 1->2
 
 
 示例 2:
 
 输入: 1->1->2->3->3
 输出: 1->2->3
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


/*
 解题思路：
 
 移除有序链表中的重复项需要定义个指针指向该链表的第一个元素，
 然后第一个元素和第二个元素比较，如果重复了，
 则删掉第二个元素，如果不重复，指针指向第二个元素。
 这样遍历完整个链表，则剩下的元素没有重复项。
 */
ListNode *deleteDuplicates(ListNode *head){
 
    if (!head || !head->next) {
        return head;
    }
    
    ListNode *start = head;
    while (start && start->next) {
        if (start->val == start->next->val) {
            ListNode *tempNode = start->next;
            start->next = start->next->next;
            delete tempNode;
        }else{
            start = start->next;
        }
    }
    
    return head;
}

int main(int argc, const char * argv[]) {
  
    
    int myarray1[]={1,3,3,5,7};
    
    int num1=sizeof(myarray1)/sizeof(int);
    
    ListNode *head1;
    
    head1=CreateLinkList(myarray1,num1);
    cout<<"链表1内容为："<<endl;
    MYPrint(head1);
    
    
    deleteDuplicates(head1);
    
    
    return 0;
}
