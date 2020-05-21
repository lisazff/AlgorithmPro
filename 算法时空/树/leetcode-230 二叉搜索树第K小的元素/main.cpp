//
//  main.cpp
//  leetcode-230 二叉搜索树第K小的元素
//
//  Created by 佐毅 on 2020/2/8.
//  Copyright © 2020 dfjr. All rights reserved.
//

/**
 给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。
 
 说明：
 你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。
 
 示例 1:
 
 输入: root = [3,1,4,null,2], k = 1
 3
 / \
 1   4
 \
    2
 输出: 1
 示例 2:
 
 输入: root = [5,3,6,2,4,null,null,1], k = 3
 5
 / \
 3   6
 / \
 2   4
 /
 1
 输出: 3
 */

/**
 解题思路
 这里边有一个我们需要的知识：
 二叉搜索树按照中序遍历的结果就是一个递增的序列形式。
 所以根据这个知识，我们只要按照中序遍历的思想,设置一个计数器就可以顺利的找到第k个小的节点了，这里有个大坑，就是返回的是节点！！！！不是节点的值，如果是节点的值那么直接中序遍历，然后输出第K个元素即可，这样好像更好理解一点。但是本题需要的是节点，所以我们需要一个计数器来告诉我们现在到了第几个节点，到第k个的时候就返回。
 */


#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void reverse_index(vector<vector<int>> vec){
    int i,j;
    cout << "Use index : " << endl;
    for (i = 0; i < vec.size(); i++)
    {
        for(j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << " ";
        cout << endl;
    }
}
class Solution {
public:
    int n=0;
    int res;
    int kthSmallest(TreeNode* root, int k) {
        //递归
        dfs(root,k);
        return res;
    }
    
    void  dfs(TreeNode* root,int k){
        if(!root)return ;
        dfs(root->left,k);
        n++;
        if(n==k) res=root->val;
        dfs(root->right,k);
    }
    
    int kthSmallests(TreeNode* root, int k) {
        //迭代
        stack<TreeNode*>sk;
        int res;
        int n=0;
        TreeNode* cur=root;
        while(!sk.empty()||cur){
            while(cur){
                sk.push(cur);
                cur=cur->left;
            }
            cur=sk.top();
            sk.pop();
            n++;
            if(n==k)return cur->val;
            cur=cur->right;
        }
        return 0;
    }
};

int main(int argc, const char * argv[]) {
    
    TreeNode *headNodel = new TreeNode(3);
    TreeNode *node2 = new TreeNode(4);
    TreeNode *node3 = new TreeNode(5);
    TreeNode *node4 = new TreeNode(1);
    TreeNode *node5 = new TreeNode(2);
    
    
    headNodel->left = node2;
    headNodel->right = node3;
    
    node2->left = node4;
    node2->right = node5;
    
    node4->left = nullptr;
    node4->right = nullptr;
    
    node5->left = nullptr;
    node5->right = nullptr;
    
    
    Solution solution;
    cout << solution.kthSmallests(headNodel,2) << " ";
    return 0;
}
