//
//  main.cpp
//  leetcode- 124 二叉树的最大路径和
//
//  Created by 佐毅 on 2020/2/8.
//  Copyright © 2020 dfjr. All rights reserved.
//

/**
 给定一个非空二叉树，返回其最大路径和。
 
 本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
 
 示例 1:
 
 输入: [1,2,3]
 
 1
 / \
 2   3
 
 输出: 6
 示例 2:
 
 输入: [-10,9,20,null,null,15,7]
 
    -10
    / \
   9  20
     /  \
    15   7
 
 输出: 42
 */

/**
 解题思路：

 二叉树 abc，a 是根结点（递归中的 root），bc 是左右子结点（代表其递归后的最优解）。
 最大的路径，可能的路径情况：

     a
    / \
   b   c
 b + a + c。
 b + a + a 的父结点。
 a + c + a 的父结点。
 其中情况 1，表示如果不联络父结点的情况，或本身是根结点的情况。
 这种情况是没法递归的，但是结果有可能是全局最大路径和。
 情况 2 和 3，递归时计算 a+b 和 a+c，选择一个更优的方案返回，也就是上面说的递归后的最优解啦。

 另外结点有可能是负值，最大和肯定就要想办法舍弃负值（max(0,x)）。
 但是上面 3 种情况，无论哪种，a 作为联络点，都不能够舍弃。

 代码中使用 val 来记录全局最大路径和。
 ret 是情况 2 和 3。
 lmr 是情况 1。

 所要做的就是递归，递归时记录好全局最大和，返回联络最大和。
 */

#include <iostream>
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
    int maxPathSum(TreeNode* root, int &val){
        if (root == nullptr) return 0;
        int left = maxPathSum(root->left, val);
        int right = maxPathSum(root->right, val);
        int lmr = root->val + max(0, left) + max(0, right);
        int ret = root->val + max(0, max(left, right));
        val = max(val, max(lmr, ret));
        return ret;
    }
    
    int maxPathSum(TreeNode* root){
        int val = INT_MIN;
        maxPathSum(root, val);
        return val;
    }
};

int main(int argc, const char * argv[]) {
    
    TreeNode *headNodel = new TreeNode(-3);
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
    cout << solution.maxPathSum(headNodel) << " ";
    
    return 0;
}
