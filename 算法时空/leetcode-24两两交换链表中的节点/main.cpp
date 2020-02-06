//
//  main.cpp
//  leetcode-24两两交换链表中的节点
//
//  Created by 佐毅 on 2020/2/1.
//  Copyright © 2020 dfjr. All rights reserved.
//

/**
 ### 题目描述

 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

 **你不能只是单纯的改变节点内部的值**，而是需要实际的进行节点交换。

 **示例:**

 ```
 给定 1->2->3->4, 你应该返回 2->1->4->3.
 ``
 */

/**
 ### 题目解析
 该题属于基本的链表操作题。

 - 设置一个虚拟头结点`dummyHead `
 - 设置需要交换的两个节点分别为`node1 `、`node2`，同时设置`node2`的下一个节点`next`

 在这一轮操作中

 - 将`node2`节点的next设置为`node1`节点
 - 将`node1`节点的next设置为`next `节点
 - 将`dummyHead `节点的next设置为`node2 `
 - 结束本轮操作

 接下来的每轮操作都按照上述进行。
 */
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) { val = x; }
};

//打印链表
void MYPrint(ListNode *p) {
    while(p!=NULL) {
        cout<<p->val<<" ";
        
        p=p->next;
    }
    cout<<endl<<endl;
    return;
}

ListNode *CreateLinkList(int myarray[],int num){
    //将数组myarray中的内容传递给链表
    //链表
    ListNode *head,*p,*lins = nullptr;  //首先建立一个头指针head指向链表的最开始。。当链表还没有建立的时候头指针为空。
    head=NULL;    //头指针初始为空
    for(int i=0; i<=num-1; i++){
        //建立一个结点，并用临时指针p指向这个结点。
        p = new ListNode(-1) ;
        p->val = myarray[i];   //将数据存储到当前结点的data域中
        p->next = NULL;    //设置当前结点的后继指针指向空，也就是当前结点的下一个结点为空。
        
        if(head==NULL)
        {
            head=p;   //如果这是第一个创建的结点，则将头指针指向这个结点
        }
        else{
            lins->next=p; //如果这不是第一个创建的结点，则将上一个结点的后继指针指向当前结点
        }
        lins=p;  //指针lins也指向当前结点.
    }
    return head;
}

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode* p = dummyHead;
        while(p->next && p->next->next){
            ListNode* node1 = p->next;
            ListNode* node2 = node1->next;
            ListNode* next = node2->next;
            node2->next = node1;
            node1->next = next;
            p->next = node2;
            p = node1;
        }

        ListNode* retHead = dummyHead->next;
        delete dummyHead;
        return retHead;
    }
    
     ListNode* swapPairss(ListNode* head) {
            if(!head || !head->next)   return head;
            ListNode* first = head;
            ListNode* second = head->next;
            head = second;
            first->next = swapPairs(second->next);
            second->next = first;
            return head;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solution;
    int myarray1[]={1,3,5,7};

    int num1=sizeof(myarray1)/sizeof(int);

    ListNode *head1,*newHead;
    
    head1=CreateLinkList(myarray1,num1);

    newHead = solution.swapPairs(head1);
    
    cout<<"链表1内容为："<<endl;
    
    MYPrint(newHead);
        
    return 0;
}
