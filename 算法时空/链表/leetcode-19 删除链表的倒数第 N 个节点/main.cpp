//
//  main.cpp
//  leetcode-19 删除链表的倒数第 N 个节点
//
//  Created by 佐毅 on 2020/2/1.
//  Copyright © 2020 dfjr. All rights reserved.
//

/**

 ### 题目描述

 给定一个链表，删除链表的倒数第 *n* 个节点，并且返回链表的头结点。

 **示例：**

 ```
 给定一个链表: 1->2->3->4->5, 和 n = 2.

 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 ```

 **说明：**

 给定的 *n* 保证是有效的。
 */

/**
 ### 题目解析

 采取双重遍历肯定是可以解决问题的，但题目要求我们一次遍历解决问题，那我们的思路得发散一下。

 我们可以设想假设设定了双指针`p`和`q`的话，当`q`指向末尾的`NULL`，`p`与`q`之间相隔的元素个数为`n`时，那么删除掉`p`的下一个指针就完成了要求。

 - 设置虚拟节点`dummyHead`指向`head`
 - 设定双指针`p`和`q`，初始都指向虚拟节点`dummyHead`
 - 移动`q`，直到`p`与`q`之间相隔的元素个数为`n`
 - 同时移动`p`与`q`，直到`q`指向的为`NULL`
 - 将`p`的下一个节点指向下下个节点
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) { val = x; }
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
        p = new ListNode(-1);
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


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
     ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* p = dummyHead;
        ListNode* q = dummyHead;
        for( int i = 0 ; i < n + 1 ; i ++ ){
            q = q->next;
        }

        while(q){
            p = p->next;
            q = q->next;
        }

        ListNode* delNode = p->next;
        p->next = delNode->next;
        delete delNode;

        ListNode* retNode = dummyHead->next;
        delete dummyHead;

        return retNode;
    }
};

int main(int argc, const char * argv[]) {
    int myarray1[]={1,3,5,7,9};
    int num1=sizeof(myarray1)/sizeof(int);
    Solution solution;
    ListNode *head1,*head2;
    head1=CreateLinkList(myarray1,num1);
    cout<<"链表1内容为："<<endl;
    
    head2 = solution.removeNthFromEnd(head1, 2);
    
    MYPrint(head2);
    
    
    return 0;
}
