//
//  main.cpp
//  leetcode- 243 回文链表
//
//  Created by 佐毅 on 2020/5/17.
//  Copyright © 2020 dfjr. All rights reserved.
//

/**
 请判断一个链表是否为回文链表。
 
 示例 1:
 
 输入: 1->2
 输出: false
 示例 2:
 
 输入: 1->2->2->1
 输出: true
 进阶：
 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/palindrome-linked-list
 */
#include <iostream>
#include <queue>
#include <vector>
#include <stack>

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
        
        if(head==NULL){
            head=p;   //如果这是第一个创建的结点，则将头指针指向这个结点
        }else{
            lins->next=p; //如果这不是第一个创建的结点，则将上一个结点的后继指针指向当前结点
        }
        lins=p;  //指针lins也指向当前结点.
    }
    return head;
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // 方法1. 使用数组
        /*
         vector<int> v;
         while(head){
         v.push_back(head->val);
         head = head->next;
         }
         // 判断是否回文
         for(int i=0; i<v.size()/2; ++i){
         if(v[i] != v[v.size()-1-i]){
         return false;
         }
         }
         return true;
         */
        
        // 方法2. 反转链表
        if(!head || !head->next) return true;
        ListNode* slow = head, * fast = head;
        // 将slow指针移动到链表中间位置
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        // 反转后半部分
        ListNode* curNode = slow, *nextNode = slow->next;
        while(nextNode){
            ListNode* tmp = nextNode->next;
            nextNode->next = curNode;
            curNode = nextNode;
            nextNode = tmp;
        }
        slow->next = nullptr;
        // 开始比较是否相等
        while(head && curNode){
            if(head->val != curNode->val)
                return false;
            head = head->next;
            curNode = curNode->next;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    int myarray1[]={1,2,3,4,7};
    
    int num1=sizeof(myarray1)/sizeof(int);
    
    ListNode *head1;
    
    head1=CreateLinkList(myarray1,num1);
    cout<<"链表1内容为："<<endl;
    MYPrint(head1);
    Solution solution;
    
    bool isPalindrome =  solution.isPalindrome(head1);
    
    cout << isPalindrome << " ";

    return 0;
}
