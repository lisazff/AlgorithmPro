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
struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

class BinTree{
public:
    
    Node *root;
    Node* CreateTree();
    void preOrder(Node *r);//递归实现先序遍历
    void InOrder(Node *r);//递归实现中序遍历
    void PostOrder(Node *r);//递归实现后续遍历
    bool isSameTree(Node* p, Node* q);
};

//创建一棵二叉树
Node* BinTree::CreateTree(){
    
    Node *p1=new Node(1);
    Node *p2=new Node(2);
    Node *p3=new Node(3);
    Node *p4=new Node(4);
    Node *p5=new Node(5);
    Node *p6=new Node(6);
    Node *p7=new Node(7);
    Node *p8=new Node(8);
    Node *p9=new Node(9);
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
void BinTree::preOrder(Node *r){
    if(r==NULL){
        return ;
    }else{
        cout<<r->data<<" ";
        preOrder(r->left);
        preOrder(r->right);
    }
}

//递归实现中序遍历
void BinTree::InOrder(Node *r){
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
void BinTree::PostOrder(Node *r){
    if(r==NULL){
        return ;
    }
    else{
        PostOrder(r->left);
        PostOrder(r->right);
        cout<<r->data<<" ";
    }
}

bool isSameTree(Node* p, Node* q) {
    
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


