//
//  main.cpp
//  leetcode - 572 另一个树的子树
//
//  Created by 佐毅 on 2020/2/8.
//  Copyright © 2020 dfjr. All rights reserved.
//

/**
 给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。
 
 示例 1:
 给定的树 s:
 
    3
 /   \
 4    5
/ \
1  2
 
 给定的树 t：
 
  4
 / \
1   2
 返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。
 
 示例 2:
 给定的树 s：
 
  3
 / \
 4   5
 / \
 1   2
 /
 0
 给定的树 t：
 
  4
 / \
 1   2
 返回 false。
 */

/**
 思路：
 
 首先寻找根节点相同节点。
 先判断根节点是否相等，如果相等，再判断子树是否相等。
 否则，判断子树是否等于原树左子树的子树。
 否则，判断子树是否等于原树右子树的子树。
 然后判断子树是否相等
 如果都为空，则相等。
 如果其中一个不为空，则不等。
 如果都不为空，但值不相等，则不等。
 递归判断对应左右节点是否相等。
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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!s) return false;
        return isSubtree(s->left, t) || SameTree(s, t) || isSubtree(s->right, t);
    }
    
    bool SameTree(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr) return true;
        if (s == nullptr || t == nullptr) return false;
        return s->val == t->val && SameTree(s->left, t->left) && SameTree(s->right, t->right);
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
    
    TreeNode *headNodel1 = new TreeNode(4);
    headNodel1->left = node4;
    headNodel1->right = node5;
    
    Solution solution;
    cout << solution.isSubtree(headNodel,headNodel1) << " ";

    return 0;
}
