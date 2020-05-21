//
//  main.cpp
//  leetcode-86 分割链表
//
//  Created by 佐毅 on 2020/2/1.
//  Copyright © 2020 dfjr. All rights reserved.
//


/**
 ### 题目描述
 
 给定一个链表和一个特定值 *x*，对链表进行分隔，使得所有小于 *x* 的节点都在大于或等于 *x* 的节点之前。
 
 你应当保留两个分区中每个节点的初始相对位置。
 
 **示例:**
 
 输入: head = 1->4->3->2->5->2, x = 3
 输出: 1->2->2->4->3->5
 */

/**
 ### 题目解析
 
 这道题要求我们划分链表，把所有小于给定值的节点都移到前面，大于该值的节点顺序不变，相当于一个局部排序的问题。
 
 - 设定两个虚拟节点，`dummyHead1 `用来保存小于于该值的链表，`dummyHead2 `来保存大于等于该值的链表
 - 遍历整个原始链表，将小于该值的放于`dummyHead1 `中，其余的放置在`dummyHead2 `中
 - 遍历结束后，将`dummyHead2 `插入到`dummyHead1 `后面
 
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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* dummyHead1 = new ListNode(-1);
        ListNode* dummyHead2 = new ListNode(-1);
        ListNode* prev1 = dummyHead1;
        ListNode* prev2 = dummyHead2;
        
        for(ListNode* cur = head ; cur != NULL ;){
            if(cur->val < x){
                prev1->next = cur;
                cur = cur->next;
                prev1 = prev1->next;
                prev1->next = NULL;
            }else{
                prev2->next = cur;
                cur = cur->next;
                prev2 = prev2->next;
                prev2->next = NULL;
            }
        }
        
        prev1->next = dummyHead2->next;
        ListNode* ret = dummyHead1->next;
        
        delete dummyHead1;
        delete dummyHead2;
        return ret;
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
    newHead = solution.partition(head1, 5);
    MYPrint(newHead);
    
    return 0;
}
