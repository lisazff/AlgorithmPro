//
//  main.cpp
//  leetcode-107 二叉树的层次遍历 II
//
//  Created by 佐毅 on 2020/2/2.
//  Copyright © 2020 dfjr. All rights reserved.
//

/**
 ### 题目描述
 
 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 
 例如：
 给定二叉树 `[3,9,20,null,null,15,7]`,
 
 ```
 3
 / \
 9  20
 /  \
 15   7
 ```
 
 返回其自底向上的层次遍历为：
 [
 [15,7],
 [9,20],
 [3]
 ]
 */

/**
 ### 题目解析
 
 该问题需要用到**队列**，解法与上篇[每天一算：Binary Tree Level Order Traversal](https://xiaozhuanlan.com/topic/8579460312)类似，区别在于最后存储方式的不同。
 
 - 建立一个 queue
 - 先把根节点放进去，这时候找根节点的左右两个子节点
 - 去掉根节点，此时queue里的元素就是下一层的所有节点
 - 用 for 循环遍历，将结果存到一个一维向量里
 - 遍历完之后再把这个一维向量**插入**到二维向量里
 - 以此类推，可以完成层序遍历
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

class Solution{
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root){
        vector<vector<int>> res;//结果
        if(root==NULL)
            return res;
        
        queue<TreeNode*> q;//定义一个队列，用来放树
        q.push(root);//先把整棵树放进去
        while(!q.empty()){
            vector<int> temp;//临时变量
            long len = q.size();//队列的长度（队列中树的个数）
            for(int i=0;i<len;i++){
                TreeNode* now = q.front();//获取队列的第一个
                q.pop();//队列弹出
                temp.push_back(now->val);//临时变量保存第一颗树的根节点
                if(now->left!=NULL) //左子树非空
                    q.push(now->left);
                if(now->right!=NULL)//右子树非空
                    q.push(now->right);
            }
            res.insert(res.begin(), temp);//将临时变量保存到结果中(从前面插入)
        }
        return res;
    }
    
    vector<vector<int>> levelOrderBottoms(TreeNode* root) {
        vector<vector<int>> res;
        levelorder(root,0,res);
        return vector<vector<int>>(res.rbegin(),res.rend());
    }
    
    void levelorder(TreeNode* node, int level, vector<vector<int>>& res){
        if(!node) return ;
        if(res.size()==level) res.push_back({});
        res[level].push_back(node->val);
        if(node->left) levelorder(node->left,level+1, res);
        if(node->right) levelorder(node->right,level+1,res);
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
       
       vector<vector<int>> vec = solution.levelOrderBottom(headNodel);
       reverse_index(vec);
       
    return 0;
}
