//
//  main.cpp
//  leetcode- 671 二叉树中第二小的节点
//
//  Created by 佐毅 on 2020/2/8.
//  Copyright © 2020 dfjr. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
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
private:
    int fir = INT_MAX;
    int sec = INT_MAX;
    int secIsChange = false;
    
    void dfs(TreeNode* root)
    {
        if (!root)  return;
        if ((root->val > fir && root->val < sec) || root->val == INT_MAX)  {
            sec = root->val;
            secIsChange = true;
        }
        else if (root->val < fir) {
            fir = root->val;
        }
        dfs(root->left);
        dfs(root->right);
    }
public:
    int findSecondMinimumValue(TreeNode* root){
        dfs(root);
        return secIsChange?sec:-1;
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
    cout << solution.findSecondMinimumValue(headNodel) << " ";
    return 0;
}
