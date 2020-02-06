//
//  main.cpp
//  leetcode-101 对称二叉树
//
//  Created by 佐毅 on 2020/2/1.
//  Copyright © 2020 dfjr. All rights reserved.
//

/**
 ### 题目描述

 给定一个二叉树，检查它是否是镜像对称的。

 例如，二叉树 `[1,2,2,3,4,4,3]` 是对称的。
    1
    / \
   2    2
  / \     / \
 3  4   4  3
 */

/**
 ### 题目解析
 用递归做比较简单：一棵树是对称的**等价**于它的左子树和右子树两棵树是对称的，问题就转变为判断两棵树是否对称。
 解题思路：
 若一个二叉树root是镜像对称的，则与克隆体rootcopy有：
 根节点相同
 root每个右子树与rootcopy左子树镜像对称
 root每个左子树与rootcopy右子树镜像对称
 */

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    
    bool isSymmetric(TreeNode* root) {
        return ismirror(root,root);
    }
    
    bool ismirror(TreeNode* t1,TreeNode* t2){
        if(t1==NULL&&t2==NULL)//都为空
            return true;
        if(t1==NULL||t2==NULL)//有一个为空
            return false;
        return (t1->val==t2->val)&&ismirror(t1->left,t2->right)&&ismirror(t1->right,t2->left);
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
    cout << "该树是对成二叉树: " << endl ;
    cout << solution.isSymmetric(headNodel) << endl;
    return 0;
}
