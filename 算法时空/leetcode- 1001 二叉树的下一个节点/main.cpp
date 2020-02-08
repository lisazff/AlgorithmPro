//
//  main.cpp
//  leetcode- 1001 二叉树的下一个节点
//
//  Created by 佐毅 on 2020/2/8.
//  Copyright © 2020 dfjr. All rights reserved.
//

/**
 二叉树的下一个节点
 题目要求
 给定一个二叉树和其中一个节点，如何找出中序遍历序列的下一个节点？树中的节点除了有两个分别指向左右孩子的指针，以及一个指向父节点的指针。

  示例 1:
  给定的树 s:
  
     3
  /   \
  4    5
 / \
 1  2
 
 解题思路
 根据中序遍历的特点，我们能知道，在树结构中的节点，求其下一个节点我们有如下3种情况：
 1. 这个节点有右子树，那么下一个节点就是这个右子树的左孩子节点。
 2. 这个节点没有右子树，并且这个点是父节点的左孩子，那么他的下一个节点就是其父节点。
 3. 这个节点没有右子树，并且这个点是父节点的右孩子，则情况稍微复杂一点，沿着其父节点向上遍历，找到一个是它父节点的左孩子节点的节点，则他下一个节点就是该节点的父亲节点。
 4.如果不是以上三类情况，那么说明该节点没有下一个节点，返回NULL或nullptr.
 */
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) {}
};

class Solution {
public:
    TreeNode* getNextNode(TreeNode* node){
        if(node == nullptr)
            return nullptr;
        TreeNode* pnext = nullptr;
        if(node->right!=nullptr) // 情况1，有右子树，取其左孩子节点
        {
            TreeNode* currentright = node->right;
            while(currentright ->left != nullptr)
                currentright = currentright ->left;
            pnext = currentright ;
        }
        else // 情况2和3，没有右子树
        {
            TreeNode* current = node;
            while(current->parent != nullptr)
            {
                if(current == current->parent->left)//情况2 当前节点是左孩子
                {
                    pnext = current->parent;
                    break;
                }
                current = current->parent;// 情况3 向上搜索
            }
        }
        return pnext;
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
      cout << solution.getNextNode(node2)->val << " ";

    return 0;
}
