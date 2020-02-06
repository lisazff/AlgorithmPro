//
//  main.cpp
//  leetcode-104 二叉树的深度
//
//  Created by 佐毅 on 2020/2/2.
//  Copyright © 2020 dfjr. All rights reserved.
//

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
    // 递归方式
    int depth(TreeNode* node){
        if(node ==NULL) return 0;
        return max( depth(node->left), depth(node->right) )+1;
    }
    
    //深度优先：用栈的循环版
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        stack<pair<TreeNode*,int>> s;
        TreeNode* p=root;
        int Maxdeep=0;
        int deep=0;
        while(!s.empty()||p!=NULL)//若栈非空，则说明还有一些节点的右子树尚未探索；若p非空，意味着还有一些节点的左子树尚未探索
        {
            while(p!=NULL)//优先往左边走
            {
                s.push(pair<TreeNode*,int>(p,++deep));
                p=p->left;
            }
            p=s.top().first;//若左边无路，就预备右拐。右拐之前，记录右拐点的基本信息
            deep=s.top().second;
            if(Maxdeep<deep) Maxdeep=deep;//预备右拐时，比较当前节点深度和之前存储的最大深度
            s.pop();//将右拐点出栈；此时栈顶为右拐点的前一个结点。在右拐点的右子树全被遍历完后，会预备在这个节点右拐
            p=p->right;
        }
        return Maxdeep;
    }
    
    //广度优先：使用队列
    int maxDepths(TreeNode* root) {
        if(root==NULL) return 0;
        deque<TreeNode*> q;
        q.push_back(root);
        int deep=0;
        while(!q.empty()){
            deep++;
            int num=q.size();
            for(int i=1;i<=num;i++){
                TreeNode* p=q.front();
                q.pop_front();
                if(p->left) q.push_back(p->left);
                if(p->right) q.push_back(p->right);
            }
        }
        return deep;
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
