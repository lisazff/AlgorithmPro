//
//  main.cpp
//  leetcode- 654 最大二叉树
//
//  Created by 佐毅 on 2020/5/21.
//  Copyright © 2020 dfjr. All rights reserved.
//

/**
 给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：

 二叉树的根是数组中的最大元素。
 左子树是通过数组中最大值左边部分构造出的最大二叉树。
 右子树是通过数组中最大值右边部分构造出的最大二叉树。
 通过给定的数组构建最大二叉树，并且输出这个树的根节点。
 
 示例 ：

 输入：[3,2,1,6,0,5]
 输出：返回下面这棵树的根节点：

       6
     /   \
    3     5
     \    /
      2  0
        \
         1
 提示：

 给定的数组的大小在 [1, 1000] 之间。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/maximum-binary-tree
 */

#include <iostream>
#include <queue>
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
    
    /**
     首先在数组nums中找到最大值max或者它的索引index，并以max构造根节点root；
     root->left: 接着对index左端的部分数组找最大值，并构造节点
     root->right: 接着对index右端的部分数组找最大值，并构造节点
     */
    // 递归解法
    TreeNode* constructMaximumBinaryTrees(const vector<int>& nums, long l, long r) {
        if (r - l <= 0) {
            return nullptr;
        }
        long index = l, value = nums[l];
        for (long i = l + 1; i < r; ++i) {
            if (nums[i] > value) {
                index = i;
                value = nums[i];
            }
        }
        auto node = new TreeNode(nums[index]);
        node->left = constructMaximumBinaryTrees(nums, l, index);
        node->right = constructMaximumBinaryTrees(nums, index + 1, r);
        return node;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
       return constructMaximumBinaryTrees(nums, 0, nums.size());
    }
    
    
    TreeNode* constructMaximumBinaryTree1(vector<int>& nums) {
        TreeNode root(INT_MAX);
        stack<TreeNode*> s;
        s.push(&root);
        for (int i = 0; i < nums.size(); ++i) {
            while (s.top()->val < nums[i]) {
                s.pop();
            }
            TreeNode *node = new TreeNode(nums[i]);
            node->left = s.top()->right;
            s.top()->right = node;
            s.push(node);
        }
        return root.right;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
