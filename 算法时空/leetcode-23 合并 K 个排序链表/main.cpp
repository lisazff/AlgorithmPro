//
//  main.cpp
//  leetcode-23 合并 K 个排序链表
//
//  Created by 佐毅 on 2020/2/1.
//  Copyright © 2020 dfjr. All rights reserved.
//

/**
 ### 题目描述

 合并 *k* 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

 **示例:**

 ```
 输入:
 [
   1->4->5,
   1->3->4,
   2->6
 ]
 输出: 1->1->2->3->4->4->5->6
 ```

 **输入**

 ![图一](https://blog-1257126549.cos.ap-guangzhou.myqcloud.com/blog/u2jnp.jpg)

 **输出**

 ![图二](https://blog-1257126549.cos.ap-guangzhou.myqcloud.com/blog/yc4ac.jpg)
 */

/**
 
 ### 题目解析

 ### 题目分析一

 这里需要将这 *k* 个排序链表整合成一个排序链表，也就是说有多个输入，一个输出，类似于漏斗一样的概念。

 因此，可以利用最小堆的概念。如果你对堆的概念不熟悉，可以戳这先了解一下~

 取每个 Linked List 的最小节点放入一个 heap 中，排序成最小堆。然后取出堆顶最小的元素，放入输出的合并 List 中，然后将该节点在其对应的 List 中的下一个节点插入到 heap 中，循环上面步骤，以此类推直到全部节点都经过 heap。

 由于 heap 的大小为始终为 k ，而每次插入的复杂度是 logk ，一共插入了 nk 个节点。时间复杂度为 O(nklogk)，空间复杂度为O(k)。
 
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
        p = new ListNode(-1) ;
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


struct cmp {
    bool operator () (ListNode *a, ListNode *b) {
        return a->val > b->val;
    }
};
 
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) q.push(lists[i]);
        }
        ListNode *head = NULL, *pre = NULL, *tmp = NULL;
        while (!q.empty()) {
            tmp = q.top();
            q.pop();
            if (!pre) head = tmp;
            else pre->next = tmp;
            pre = tmp;
            if (tmp->next) q.push(tmp->next);
        }
        return head;
    }
    
    ListNode *mergeKListss(vector<ListNode *> &lists) {
        if (lists.size() == 0) return NULL;
        long n = lists.size();
        while (n > 1) {
            long k = (n + 1) / 2;
            for (int i = 0; i < n / 2; ++i) {
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            }
            n = k;
        }
        return lists[0];
    }
    
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(-1);
        ListNode *cur = head;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;
        return head->next;
    }
};

int main(int argc, const char * argv[]) {
     int myarray1[]={1,3,5,7};
     int myarray2[]={1,2,4,6,7,8};
     int myarray3[]={8,5,12,19,33,};

     int num1=sizeof(myarray1)/sizeof(int);
     int num2=sizeof(myarray2)/sizeof(int);
     int num3=sizeof(myarray3)/sizeof(int);

     ListNode *head1,*head2,*head3,*newHead;
     
     head1=CreateLinkList(myarray1,num1);
     cout<<"链表1内容为："<<endl;
     
     cout<<"链表2内容为："<<endl;
     head2=CreateLinkList(myarray2,num2);
    
    cout<<"链表3内容为："<<endl;
    head3=CreateLinkList(myarray3,num3);
    
     vector<ListNode *> res;
     res.push_back(head1);
     res.push_back(head2);
     res.push_back(head3);

    Solution solution;
    newHead = solution.mergeKListss(res);
    
    cout<<"合并后链表内容为："<<endl;
    MYPrint(newHead);
    return 0;
}
