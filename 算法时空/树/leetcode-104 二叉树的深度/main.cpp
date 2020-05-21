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
#include <stack>

/**
 Example:
 
 输入一个二叉树 [3,9,20,null,null,15,7],
 
 3
 / \
 9  20
 /  \
 15   7
 return its depth = 2.
 
 */

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
    for (i = 0; i < vec.size(); i++){
        for(j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << " ";
        cout << endl;
    }
}

class Solution {
public:
    
    // 递归方式
    int maxDepth0(TreeNode* node){
        if(node ==NULL) return 0;
        return max( maxDepth0(node->left), maxDepth0(node->right) )+1;
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
    
    //广度优先：使用队列 主要说说BFS的实现，实际上二叉树的最大深度就是树的层数，依靠这个关系我们可以借助队列进行层序遍历，最后的层数就是题目中要求的最大深度。
    //具体实现的时候，我们对每一层进行如下操作：将根结点放入队列，然后对队列里的每个元素执行------弹出队列首元素---------放入其对应的孩子节点（如果有的话，为了对下一层进行遍历)---------每执行一层，层数+1。
    int maxDepths(TreeNode* root) {
        if(root==NULL) return 0;
        deque<TreeNode*> q;
        q.push_back(root);
        int deep=0;
        while(!q.empty()){
            deep++;
            int num=(int)q.size();
            for(int i=1;i<=num;i++){
                TreeNode* p=q.front();
                q.pop_front();
                if(p->left) q.push_back(p->left);
                if(p->right) q.push_back(p->right);
            }
        }
        return deep;
    }
    
    
    int minDepth0(TreeNode* root) {
        if(root == NULL) return 0;
        return min(1+minDepth0(root->left), 1+minDepth0(root->right));
    }
    
    int minDepth1(TreeNode *root) {
        if(root==NULL) return 0;
        if(root->left==NULL) return 1 + minDepth1(root->right); //如果只有右孩子
        if(root->right==NULL) return 1 + minDepth1(root->left); // 如果只有左孩子
        return 1+min(minDepth1(root->left),minDepth1(root->right));
    }
    
    int minDepth2(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        int res = 0; // 标记高度最大值
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())// 迭代操作标志
        {
            ++ res; // 每执行一层，深度+1。
            for(int i = 0, n = (int)q.size(); i < n; ++ i) //对队列里的每个元素进行操作。
            {
                TreeNode *p = q.front(); // 具体的队列操作是
                q.pop();                // 弹出根节点，然后放入孩子节点（如果有）
                if(p->left == NULL && p->right==NULL)
                    return res;
                if(p -> left != NULL)
                    q.push(p -> left);
                if(p -> right != NULL)
                    q.push(p -> right);
            }
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
    cout << solution.maxDepth(headNodel) << " ";
    
    
    return 0;
}
