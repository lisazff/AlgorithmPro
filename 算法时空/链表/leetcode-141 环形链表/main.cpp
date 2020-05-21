//
//  main.cpp
//  leetcode-141 环形链表
//
//  Created by 佐毅 on 2020/2/6.
//  Copyright © 2020 dfjr. All rights reserved.
//

#include <iostream>
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
    /**
     一个检测指针 k，遍历指针 q，count记录遍历指针q走的步数
     遍历指针每走一步，检测指针 k 就走遍历指针 q 之前走过的节点，若发现相同的节点便说明有环
     知道遍历节点 q 为 NULL 停止
     */
    bool hasCycle(ListNode *head) {
        if(head==NULL||head->next==NULL)
            return false;
        ListNode *k=head;//检测节点
        ListNode *q=head->next;//遍历节点
        int count=0;//记录检测节点走了多少步
        while(q)
        {
            for(int i=count;i>0;i--)
            {
                k=k->next;
                if(k==q)
                    return true;
            }
            k=head;//还原
            q=q->next;
            count++;
        }
        return false;
    }
    
    //方法三：快慢指针
    /**
     初始化 slow = head->next,每次走一步
     初始化 fast =head->next->next,每次走两步，每走一步判断一次
     存在环 fast 和 slow 会相遇
     */
    
    bool hasCycles(ListNode *head) {
        if(head==NULL||head->next==NULL)
            return false;
        ListNode *fast=head->next->next;
        ListNode *slow=head->next;
        while(fast){
            slow=slow->next;
            for(int i=0;i<2;i++){
                if(fast->next==NULL)
                    return false;
                fast=fast->next;
                if(fast==slow)
                    return true;
            }
        }
        return false;
    }
};


int main(int argc, const char * argv[]) {
    
    ListNode *head0 =  new ListNode(1);
    ListNode *head1 = new ListNode(2);
    ListNode *head2 = new ListNode(3);
    ListNode *head3 = new ListNode(4);
    ListNode *head4 = new ListNode(5);
    ListNode *head5 = new ListNode(6);
    ListNode *head6 = new ListNode(7);
    
    head0->next = head1;
    head1->next = head2;
    head2->next = head3;
    head3->next = head4;
    head4->next = head5;
    head5->next = head6;
    head6->next = head2;
    
    Solution solution;
    cout<< solution.hasCycles(head0) <<endl;
    
    return 0;
}
