//
//  main.cpp
//  leetcode-160 找到两个单链表相交的起始节点
//
//  Created by 佐毅 on 2020/2/6.
//  Copyright © 2020 dfjr. All rights reserved.
//

/**
 找到两个单链表相交的起始节点  https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/lian-biao-xiang-jiao-shuang-zhi-zhen-onshi-jian-fu/
 */

#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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
    //返回相交的节点 方法一: 暴力法
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *cur_a = headA;
        while (cur_a){
            ListNode *cur_b = headB;
            while (cur_b){
                if (cur_a == cur_b){
                    return cur_a;
                }
                cur_b = cur_b->next;
            }
            cur_a = cur_a->next;
        }
        return nullptr;
    }
    
    // 方法二: 哈希表法 使用一个hash set 遍历一个链表，set中存放其所有指针， 遍历另一个链表，去set中找相同指针 时间复杂度O(m + n) 空间复杂度O(m) 或 O(n)
    ListNode *getIntersectionNodes(ListNode *headA, ListNode *headB) {
        
        unordered_set<ListNode*> set;
        ListNode* cur_a = headA;
        
        while (cur_a){
            set.insert(cur_a);
            cur_a = cur_a->next;
        }
        
        ListNode* cur_b = headB;
        
        while (cur_b){
            if(set.find(cur_b) != set.end()){
                return cur_b;
            }
            cur_b = cur_b->next;
        }
        
        return nullptr;
    }
    
    // 方法三：双指针法
    /*
     A的指针遍历完A 接着从headB开始遍历
     B的指针遍历完B 接着从headA开始遍历
     两个指针都最多会运行m + n次，当都为空时，表示不相交；当相等时，表示相交
     */
    ListNode *getIntersectionNodess(ListNode *headA, ListNode *headB) {
        
        if(headA == nullptr || headB == nullptr)
            return nullptr;
        
        ListNode* cur_a = headA;
        ListNode* cur_b = headB;
        
        while(cur_a != cur_b){
            cur_a = (cur_a == nullptr ? headB : cur_a->next);
            cur_b = (cur_b == nullptr ? headA : cur_b->next);
        }
        
        return cur_a;
    }
};

int main(int argc, const char * argv[]) {
  
    ListNode *intersectionNode;
    
    ListNode *head0 =  new ListNode(4);
    ListNode *head1 = new ListNode(1);
    ListNode *head2 = new ListNode(8);
    ListNode *head3 = new ListNode(4);
    ListNode *head4 = new ListNode(5);

    head0->next = head1;
    head1->next = head2;
    head2->next = head3;
    head3->next = head4;


    ListNode *head00 = new ListNode(5);
    ListNode *head01 = new ListNode(0);
    ListNode *head02 = new ListNode(6);
    head00->next = head01;
    head01->next = head02;
    head02->next = head2;
 

    cout<<"链表1内容为："<<endl;
    MYPrint(head0);

    cout<<"链表2内容为："<<endl;
    MYPrint(head00);
    Solution solution;
    intersectionNode = solution.getIntersectionNodess(head0, head00);
    cout<< intersectionNode->val <<endl;
    
    return 0;
}
