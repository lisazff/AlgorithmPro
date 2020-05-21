//
//  main.cpp
//  LeetCode-102二叉树的层次遍历
//
//  Created by 佐毅 on 2019/12/17.
//  Copyright © 2019年 dfjr. All rights reserved.
//

/**
 给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。

 给定二叉树: [3,9,20,null,null,15,7],
     3
    / \
   9  20
     /  \
    15   7
 返回其层次遍历结果：
 [
   [3],
   [9,20],
   [15,7]
 ]
 
 二叉树层次遍历：按照二叉树的层次，从根节点所在的层，逐层进行遍历。逐层遍历时按照从左至右的顺序。

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

    void getTreeNode(TreeNode* node, vector<vector<int>> &vec, int depth) {
        if(node != NULL) {
            if(vec.size() <= depth){ // 一维长度表示深度
                vec.push_back(vector<int>()); // 增加一维长度
            }
            vec[depth].push_back(node->val);
        }
        else
            return;
        getTreeNode(node->left,vec,depth+1);
        getTreeNode(node->right,vec,depth+1);
    }
    
    vector<vector<int>> levelOrders(TreeNode* root) {
        vector<vector<int>> vec;
        getTreeNode(root,vec,0);
        return vec;
    }
    
    
    vector<vector<int>> levelOrderss(TreeNode* root) {

        vector<vector<int>> res;
        if(root == NULL)
            return res;

        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root, 0));

        while(!q.empty()){

            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();

            if(level == res.size())
                res.push_back(vector<int>());
            assert( level < res.size() );

            res[level].push_back(node->val);
            if(node->left)
                q.push(make_pair(node->left, level + 1 ));
            if(node->right)
                q.push(make_pair(node->right, level + 1 ));
        }

        return res;
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
    
    vector<vector<int>> vec = solution.levelOrders(headNodel);
    reverse_index(vec);
    
    return 0;
}
