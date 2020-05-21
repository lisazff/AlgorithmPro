//
//  main.cpp
//  leetcode-110 平衡二叉树
//
//  Created by 佐毅 on 2020/2/2.
//  Copyright © 2020 dfjr. All rights reserved.
//

/**
 给定二叉树: [3,9,20,null,null,15,7],
     3
    / \
   9  20
     /  \
    15   7
 */

/**
 思路：
     对当前节点，分别求解左子树和右子树的深度，判断左右子树的高度差是否<=1。
     利用了104题中求解二叉树的深度的方法
     然后再对当前节点的左节点和右节点做同样操作。
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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        
        int d = abs(depth(root->left)-depth(root->right)); //当前节点的左右子树的高度差
        
        return (d<=1) && (isBalanced(root->left)) && (isBalanced(root->right));
    }
    
    // 求解二叉树深度（104题）
    int depth(TreeNode* node){
        if(node ==NULL) return 0;
        return max( depth(node->left), depth(node->right) )+1;
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
       cout << solution.isBalanced(headNodel) << " ";
       
       
    return 0;
}
