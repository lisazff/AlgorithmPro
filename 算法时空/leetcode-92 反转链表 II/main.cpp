//
//  main.cpp
//  leetcode-92 反转链表 II
//
//  Created by 佐毅 on 2020/2/1.
//  Copyright © 2020 dfjr. All rights reserved.
//

/**
 ### 题目描述

 反转从位置 *m* 到 *n* 的链表。请使用一趟扫描完成反转。

 **说明:**
 1 ≤ *m* ≤ *n* ≤ 链表长度。

 **示例:**

 输入: 1->2->3->4->5->NULL, m = 2, n = 4
 输出: 1->4->3->2->5->NULL
 */

/**
 ### 题目解析

 **[Reverse Linked List](https://xiaozhuanlan.com/topic/7513064892)**的延伸题。

 可以考虑取出需要反转的这一小段链表，反转完后再插入到原先的链表中。

 **以本题为例：**

 变换的是 2，3，4这三个点，那么我们可以先取出 2 ，用 front 指针指向 2 ，然后当取出 3 的时候，我们把 3 加到 2 的前面，把 front 指针前移到 3 ，依次类推，到 4 后停止，这样我们得到一个新链表 4 -> 3 -> 2 ,  front 指针指向4。

 对于原链表来说，**有两个点的位置很重要**，需要用指针记录下来，分别是 1 和 5 ，把新链表插入的时候需要这两个点的位置。

 - 用 pre 指针记录 1 的位置
 - 当 4 结点被取走后，5 的位置需要记下来
 - 这样我们就可以把倒置后的那一小段链表加入到原链表中

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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy;
        ListNode *pre, *front, *last;
        pre = front = last = nullptr;
        for (int i = 1; i <= m - 1; ++i) cur = cur->next;
        pre = cur; //1
        last = cur->next; // 8
        for (int i = m; i <= n; ++i) {
            cur = pre->next;
            pre->next = cur->next;
            cur->next = front;
            front = cur;
        }
        cur = pre->next;
        pre->next = front;
        last->next = cur;
        return dummy->next;
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
    newHead = solution.reverseBetween(head1, 2,5);
    MYPrint(newHead);
    return 0;
}
