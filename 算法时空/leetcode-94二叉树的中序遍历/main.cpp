//
//  main.cpp
//  leetcode-94二叉树的中序遍历
//
//  Created by 佐毅 on 2019/12/14.
//  Copyright © 2019年 dfjr. All rights reserved.
//

/**
 ### 题目描述

 给定一个二叉树，返回它的*中序* 遍历。
 
 给定二叉树: [3,9,20,null,null,15,7],
     3
    / \
   9  20
     /  \
    15   7
 返回其层次遍历结果：
 [9,3,15,20,7]
*/

/**
 ### 题目解析

 用**栈(Stack)**的思路来处理问题。

 中序遍历的顺序为**左-根-右**，具体算法为：

 - 从根节点开始，先将根节点压入栈
 - 然后再将其所有左子结点压入栈，取出栈顶节点，保存节点值
 - 再将当前指针移到其右子节点上，若存在右子节点，则在下次循环时又可将其所有左子结点压入栈中
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void dfs(TreeNode* root, vector<int>& ans){
        if(root == NULL)
            return;
        dfs(root->left, ans);
        ans.push_back(root->val);
        dfs(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
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
    // 给定二叉树: [3,9,20,null,null,15,7],
       TreeNode *headNodel = new TreeNode(3);
       TreeNode *node2 = new TreeNode(9);
       TreeNode *node3 = new TreeNode(20);
       TreeNode *node4 = new TreeNode(15);
       TreeNode *node5 = new TreeNode(7);
       
       node2->left = nullptr;
       node2->right = nullptr;
       
       node4->left = nullptr;
       node4->right = nullptr;
       
       node5->left = nullptr;
       node5->right = nullptr;

       headNodel->left = node2;
       headNodel->right = node3;
       
       node3->left = node4;
       node3->right = node5;
       
       Solution solution;
       
       vector<int> vec = solution.inorderTraversals(headNodel);
       solution.reverse_index(vec);
    return 0;
}
