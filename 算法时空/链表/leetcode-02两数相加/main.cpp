//
//  main.cpp
//  leetcode-02两数相加
//
//  Created by 佐毅 on 2019/12/14.
//  Copyright © 2019年 dfjr. All rights reserved.
//

/*
 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 
 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 
 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 
 示例：
 
 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 输出：7 -> 0 -> 8
 原因：342 + 465 = 807
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/add-two-numbers
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode *p1 = l1, *p2 = l2;
       ListNode *dummyHead = new ListNode(-1);
       ListNode* cur = dummyHead;
       int carried = 0;
       while(p1 || p2 ){
           int a = p1 ? p1->val : 0;
           int b = p2 ? p2->val : 0;
           cur->next = new ListNode((a + b + carried) % 10);
           carried = (a + b + carried) / 10;

           cur = cur->next;
           p1 = p1 ? p1->next : NULL;
           p2 = p2 ? p2->next : NULL;
       }

       cur->next = carried ? new ListNode(1) : NULL;
       ListNode* ret = dummyHead->next;
       delete dummyHead;
       return ret;
    }
};


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
    Solution s;
    newHead=s.addTwoNumbers(head1,head2);
    MYPrint(newHead);
    
    
    
    return 0;
}
