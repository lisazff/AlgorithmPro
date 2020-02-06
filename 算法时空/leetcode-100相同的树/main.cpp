//
//  main.cpp
//  leetcode-100相同的树
//
//  Created by 佐毅 on 2018/3/25.
//  Copyright © 2018年 dfjr. All rights reserved.
//

/*
 给定两个二叉树，编写一个函数来检验它们是否相同。
 
 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
 
 示例 1:
 
  1         1
 / \       / \
 2   3     2   3
 
 [1,2,3],   [1,2,3]
 
 输出: true
 示例 2:
 
  1          1
 /           \
 2             2
 
 [1,2],     [1,null,2]
 
 输出: false
 示例 3:
 
  1         1
 / \       / \
 2   1     1   2
 
 [1,2,1],   [1,1,2]
 
 输出: false

 */

/*
思路： 从输入的结果来看，使用的是中序遍历的方式
 */
#include <iostream>

using namespace std;

#include<iostream>
using namespace std;
struct StructNode{
    int data;
    StructNode *left;
    StructNode *right;
    StructNode(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

class BinTree{
public:
    
    StructNode *root;
    StructNode* CreateTree();
    void preOrder(StructNode *r);//递归实现先序遍历
    void InOrder(StructNode *r);//递归实现中序遍历
    void PostOrder(StructNode *r);//递归实现后续遍历
    bool isSameTree(StructNode* p, StructNode* q);
};

//创建一棵二叉树
StructNode* BinTree::CreateTree(){
    
    StructNode *p1=new StructNode(1);
    StructNode *p2=new StructNode(2);
    StructNode *p3=new StructNode(3);
    StructNode *p4=new StructNode(4);
    StructNode *p5=new StructNode(5);
    StructNode *p6=new StructNode(6);
    StructNode *p7=new StructNode(7);
    StructNode *p8=new StructNode(8);
    StructNode *p9=new StructNode(9);
    p1->left=p2;
    p1->right=p3;
    p2->left=p4;
    p2->right=p5;
    p5->left=p6;
    p3->left=p7;
    p3->right=p8;
    p8->right=p9;
    root=p1;
    return p1;
}

//递归实现先序遍历
void BinTree::preOrder(StructNode *r){
    if(r==NULL){
        return ;
    }else{
        cout<<r->data<<" ";
        preOrder(r->left);
        preOrder(r->right);
    }
}

//递归实现中序遍历
void BinTree::InOrder(StructNode *r){
    if(r==NULL){
        return ;
    }
    else{
        InOrder(r->left);
        cout<<r->data<<" ";
        InOrder(r->right);
    }
}

//递归实现后序遍历
void BinTree::PostOrder(StructNode *r){
    if(r==NULL){
        return ;
    }
    else{
        PostOrder(r->left);
        PostOrder(r->right);
        cout<<r->data<<" ";
    }
}

bool isSameTree(StructNode* p, StructNode* q) {
    
    if (p == NULL && q == NULL)
        return true;
    else if (p != NULL && q != NULL) {
        if (p->data != q->data)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    else
        return false;
}

int main(){
    
    BinTree t;
    t.CreateTree();//创建二叉树
    cout<<"先序遍历:";
    t.preOrder(t.root);//先序遍历
    cout<<endl;
    
    cout<<"中序遍历:";
    t.InOrder(t.root);//中序遍历
    cout<<endl;
    
    cout<<"后序遍历:";
    t.PostOrder(t.root);//后序遍历
    cout<<endl;
    
    
    BinTree t1;
    t1.CreateTree();//创建二叉树
    cout<<"先序遍历:";
    t1.preOrder(t1.root);//先序遍历
    cout<<endl;
    
        
    return 0;
}


