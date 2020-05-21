//
//  main.cpp
//  leetcode-138 复制带随机指针的链表
//
//  Created by 佐毅 on 2020/2/6.
//  Copyright © 2020 dfjr. All rights reserved.
//
/**
 给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
 
 要求返回这个链表的 深拷贝。
 
 我们用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val, random_index] 表示：
 
 val：一个表示 Node.val 的整数。
 random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。
 */
#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    struct ListNode *random;
    ListNode(int x) : val(x), next(NULL) ,random(NULL) {};
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

ListNode *createLinkList(int myarray[],int num){
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
    ListNode* copyRandomList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode *cur = head;
        unordered_map<ListNode*, ListNode*> ump;
        //1. 遍历链表，将原节点作为key，拷贝节点作为value保存在map中
        while (cur != nullptr) {
            ListNode *copy = new ListNode(cur->val);
            ump[cur] = copy;
            cur = cur->next;
        }
        //2. 复制链表next和random指针
        cur = head;
        while (cur != nullptr) {
            ump[cur]->next = ump[cur->next];
            ump[cur]->random = ump[cur->random];
            cur = cur->next;
        }
        return ump[head];
    }
    
    /**
     当然，如果使用 HashMap 占用额外的空间，如果这道题限制了空间的话，就要考虑别的方法。下面这个方法很巧妙，可以分为以下三个步骤：

     1. 在原链表的每个节点后面拷贝出一个新的节点。

     2. 依次给新的节点的随机指针赋值，而且这个赋值非常容易 cur->next->random = cur->random->next。

     3. 断开链表可得到深度拷贝后的新链表。

     举个例子来说吧，比如原链表是 1(2) -> 2(3) -> 3(1)，括号中是其 random 指针指向的结点，那么这个解法是首先比遍历一遍原链表，在每个结点后拷贝一个同样的结点，但是拷贝结点的 random 指针仍为空，则原链表变为 1(2) -> 1(null) -> 2(3) -> 2(null) -> 3(1) -> 3(null)。然后第二次遍历，是将拷贝结点的 random 指针赋上正确的值，则原链表变为 1(2) -> 1(2) -> 2(3) -> 2(3) -> 3(1) -> 3(1)，注意赋值语句为：

     cur->next->random = cur->random->next;

     这里的 cur 是原链表中结点，cur->next 则为拷贝链表的结点，cur->next->random 则为拷贝链表的 random 指针。cur->random 为原链表结点的 random 指针指向的结点，因为其指向的还是原链表的结点，所以我们要再加个 next，才能指向拷贝链表的结点。最后再遍历一次，就是要把原链表和拷贝链表断开即可，参见代码如下
     */
    ListNode* copyRandomLists(ListNode* head) {
        if (!head) return nullptr;
        ListNode *cur = head;
        while (cur) {
            ListNode *t = new ListNode(cur->val);
            t->next = cur->next;
            cur->next = t;
            cur = t->next;
        }
        cur = head;
        while (cur) {
            if (cur->random) cur->next->random = cur->random->next;
            cur = cur->next->next;
        }
        cur = head;
        ListNode *res = head->next;
        while (cur) {
            ListNode *t = cur->next;
            cur->next = t->next;
            if (t->next) t->next = t->next->next;
            cur = cur->next;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    
    ListNode *head0 =  new ListNode(7);
    ListNode *head1 = new ListNode(13);
    ListNode *head2 = new ListNode(11);
    ListNode *head3 = new ListNode(10);
    ListNode *head4 = new ListNode(1);
    
    head0->next = head1;
    head1->next = head2;
    head2->next = head3;
    head3->next = head4;
    head4->next = nullptr;
    
    head0->random = nullptr;
    head1->random = head0;
    head2->random = head4;
    head3->random = head2;
    head4->random = head0;
    
    Solution solution;
    ListNode *head;
    head = solution.copyRandomList(head0);
    MYPrint(head);
    return 0;
}
