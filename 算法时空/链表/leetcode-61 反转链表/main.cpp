//
//  main.cpp
//  leetcode-15 反转链表
//
//  Created by 佐毅 on 2019/12/17.
//  Copyright © 2019年 dfjr. All rights reserved.
//

/**
 解题思路
 设置三个节点pre、cur、next

 （1）每次查看cur节点是否为NULL，如果是，则结束循环，获得结果

 （2）如果cur节点不是为NULL，则先设置临时变量next为cur的下一个节点

 （3）让cur的下一个节点变成指向pre，而后pre移动cur，cur移动到next

 （4）重复（1）（2）（3）
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
    ListNode* reverseList(ListNode* pHead){
        // 反转指针
        ListNode* pNode=pHead;  // 当前节点
        ListNode* pPrev=nullptr;// 当前节点的上一个节点
        ListNode* pNext=nullptr;// 当前节点的下一个节点
        ListNode* pReverseHead=nullptr;//新链表的头指针
        
        // 反转链表
        while(pNode!=nullptr){
            pNext=pNode->next; // 建立链接
            　　　　　　　　　　
            if(pNext==NULL)    // 判断pNode是否是最后一个节点
                pReverseHead=pNode;
            pNode->next=pPrev; // 指针反转
            pPrev=pNode;
            pNode=pNext;
        }
        return pReverseHead;
    }
    
    ListNode* reverseList1(ListNode* head) {
        // 递归终止条件
        if(head == NULL || head->next == NULL)
              return head;
        ListNode* rhead = reverseList(head->next);
        // head->next此刻指向head后面的链表的尾节点
        // head->next->next = head把head节点放在了尾部
         head->next->next = head;
         head->next = NULL;
         return rhead;
      }
};

int main(int argc, const char * argv[]) {
   int myarray1[]={1,8,2,5,2,3,3,5,7};
          
       int num1=sizeof(myarray1)/sizeof(int);
          
       ListNode *head1, *newHead;
          
       head1=CreateLinkList(myarray1,num1);
       cout<<"链表1内容为："<<endl;
       MYPrint(head1);
       
       cout<<"新链表内容为："<<endl;
       Solution solution;
       newHead = solution.reverseList(head1);
       MYPrint(newHead);
    return 0;
}
