//
//  main.cpp
//  leetcode-109 有序链表转换二叉搜索树
//
//  Created by 佐毅 on 2020/2/3.
//  Copyright © 2020 dfjr. All rights reserved.
//

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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==nullptr) return nullptr;
        if(head->next == nullptr) return new TreeNode(head->val);
        ListNode *start = new ListNode(0);
        start ->next=head;
        ListNode *fast = start, *slow = start, *slow_pre = nullptr;
        while(fast!=nullptr&&fast->next!=nullptr){
            fast = fast->next->next;
            slow_pre = slow;
            slow = slow->next;
        }
        TreeNode *root = new TreeNode(slow->val);
        slow_pre->next = nullptr;
        root->left = sortedListToBST(start->next);
        root->right = sortedListToBST(slow->next);
        return root;
    }
    vector<int> inorderTraversals(TreeNode* root) {
        vector<int> ans;
        TreeNode* p = root;
        stack<TreeNode*> st;
        while(p || !st.empty()){
            while(p){
                st.push(p);
                p = p->left;
            }
            p = st.top();
            st.pop();
            ans.push_back(p->val);
            p = p->right;
        }
        return ans;
    }
    
    void reverse_index(vector<int> vec){
        int i;
        cout << "reverse index : " << endl;
        for (i = 0; i < vec.size(); i++){
           cout << vec[i] << " ";
        }
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
    

    solution.reverse_index(solution.inorderTraversals(solution.sortedListToBST(head1)));
    
    return 0;
}
