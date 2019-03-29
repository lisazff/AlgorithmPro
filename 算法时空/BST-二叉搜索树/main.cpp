//
//  main.cpp
//  BST-二叉搜索树
//
//  Created by 佐毅 on 2018/3/26.
//  Copyright © 2018年 dfjr. All rights reserved.
//



// 104. Maximum Depth of Binary Tree
// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
// 时间复杂度: O(n), n是树中的节点个数
// 空间复杂度: O(h), h是树的高度

/// 112. Path Sum
/// https://leetcode.com/problems/path-sum/description/
/// 时间复杂度: O(n), n为树的节点个数
/// 空间复杂度: O(h), h为树的高度

/// 226. Invert Binary Tree
/// https://leetcode.com/problems/invert-binary-tree/description/
/// 时间复杂度: O(n), n为树中节点个数
/// 空间复杂度: O(h), h为树的高度

/// 235. Lowest Common Ancestor of a Binary Search Tree
/// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
/// 时间复杂度: O(lgn), 其中n为树的节点个数
/// 空间复杂度: O(h), 其中h为树的高度

/// 257. Binary Tree Paths
/// https://leetcode.com/problems/binary-tree-paths/description/
/// 时间复杂度: O(n), n为树中的节点个数
/// 空间复杂度: O(h), h为树的高度


/// 437. Path Sum III
/// https://leetcode.com/problems/path-sum-iii/description/
/// 时间复杂度: O(n), n为树的节点个数
/// 空间复杂度: O(h), h为树的高度

#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <ctime>
#include <queue>
#include "BST.h"
#include "SequenceST.h"
#include "FileOps.h"
#include <fstream>

using namespace std;
/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    
    TreeNode* invertTree(TreeNode* root) {
        
        if(root == NULL)
            return NULL;
        
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
        
        return root;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        assert(p != NULL && q != NULL);
        
        if(root == NULL)
            return NULL;
        
        if(p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        if(p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        
        assert(p->val == root->val || q->val == root->val
               || (root->val - p->val) * (root->val - q->val) < 0);
        
        return root;
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        
        if(root == NULL)
            return false;
        
        if(root->left == NULL && root->right == NULL)
            return sum == root->val;
        
        return hasPathSum(root->left, sum - root->val)
        || hasPathSum(root->right, sum - root->val);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> res;
        
        if(root == NULL)
            return res;
        
        if(root->left == NULL && root->right == NULL){
            res.push_back(to_string(root->val));
            return res;
        }
        
        vector<string> leftPaths = binaryTreePaths(root->left);
        for(int i = 0 ; i < leftPaths.size() ; i ++)
            res.push_back(to_string(root->val) + "->" + leftPaths[i]);
        
        vector<string> rightPaths = binaryTreePaths(root->right);
        for(int i = 0 ; i < rightPaths.size() ; i ++)
            res.push_back(to_string(root->val) + "->" + rightPaths[i]);
        
        return res;
    }
    
    // 在以root为根节点的二叉树中,寻找和为sum的路径,返回这样的路径个数
    int pathSum(TreeNode* root, int sum) {
        
        if(root == NULL)
            return 0;
        
        return findPath(root, sum)
        + pathSum(root->left , sum)
        + pathSum(root->right , sum);
    }
private:
    
    // 在以node为根节点的二叉树中,寻找包含node的路径,和为sum
    // 返回这样的路径个数
    int findPath(TreeNode* node, int num){
        
        if(node == NULL)
            return 0;
        
        int res = 0;
        if(node->val == num)
            res += 1;
        
        res += findPath(node->left , num - node->val);
        res += findPath(node->right , num - node->val);
        
        return res;
    }
};



/*----------------------------------------------------------*/

// 二分查找法,在有序数组arr中,查找target
// 如果找到target,返回相应的索引index
// 如果没有找到target,返回-1
template<typename T>
int binarySearch(T arr[], int n, T target){
    
    // 在arr[l...r]之中查找target
    int l = 0, r = n-1;
    while( l <= r ){
        
        //int mid = (l + r)/2;
        // 防止极端情况下的整形溢出，使用下面的逻辑求出mid
        int mid = l + (r-l)/2;
        
        if( arr[mid] == target )
            return mid;
        
        if( arr[mid] > target )
            r = mid - 1;
        else
            l = mid + 1;
    }
    
    return -1;
}


// 用递归的方式写二分查找法
template<typename T>
int __binarySearch2(T arr[], int l, int r, T target){
    
    if( l > r )
        return -1;
    
    //int mid = (l+r)/2;
    // 防止极端情况下的整形溢出，使用下面的逻辑求出mid
    int mid = l + (r-l)/2;
    
    if( arr[mid] == target )
        return mid;
    else if( arr[mid] > target )
        return __binarySearch2(arr, l, mid-1, target);
    else
        return __binarySearch2(arr, mid+1, r, target);
}

template<typename T>
int binarySearch2(T arr[], int n, T target){
    
    return __binarySearch2( arr , 0 , n-1, target);
}


/*-----------------------------------------------------------------------------------*/

// 比较非递归和递归写法的二分查找的效率
// 非递归算法在性能上有微弱优势

void binarySearch(){
    
    int n = 1000000;
    int* a = new int[n];
    for( int i = 0 ; i < n ; i ++ )
        a[i] = i;
    
    // 测试非递归二分查找法
    clock_t startTime = clock();
    
    // 对于我们的待查找数组[0...N)
    // 对[0...N)区间的数值使用二分查找，最终结果应该就是数字本身
    // 对[N...2*N)区间的数值使用二分查找，因为这些数字不在arr中，结果为-1
    for( int i = 0 ; i < 2*n ; i ++ ){
        int v = binarySearch(a, n, i);
        if( i < n )
            assert( v == i );
        else
            assert( v == -1 );
    }
    clock_t endTime = clock();
    cout << "Binary Search (Without Recursion): " << double(endTime - startTime) / CLOCKS_PER_SEC << " s"<<endl;
    
    
    // 测试递归的二分查找法
    startTime = clock();
    
    // 对于我们的待查找数组[0...N)
    // 对[0...N)区间的数值使用二分查找，最终结果应该就是数字本身
    // 对[N...2*N)区间的数值使用二分查找，因为这些数字不在arr中，结果为-1
    for( int i = 0 ; i < 2*n ; i ++ ){
        int v = binarySearch2(a, n, i);
        if( i < n )
            assert( v == i );
        else
            assert( v == -1 );
    }
    endTime = clock();
    cout << "Binary Search (Recursion): " << double(endTime - startTime) / CLOCKS_PER_SEC << " s"<<endl;
    
    delete[] a;
}
/*---------------------------------------------------------------------*/

// 二分搜索树
template <typename Key, typename Value>
class BSTS{
    
private:
    // 树中的节点为私有的结构体, 外界不需要了解二分搜索树节点的具体实现
    struct Node{
        Key key;
        Value value;
        Node *left;
        Node *right;
        
        Node(Key key, Value value){
            this->key = key;
            this->value = value;
            this->left = this->right = NULL;
        }
        
        //copy一个节点
        Node(Node *node){
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
        }
    };
    
    Node *root; // 根节点
    int count;  // 树中的节点个数
    
public:
    // 构造函数, 默认构造一棵空二分搜索树
    BSTS(){
        root = NULL;
        count = 0;
    }
    
    // 析构函数, 释放二分搜索树的所有空间
    ~BSTS(){
        destroy( root );
    }
    
    // 返回二分搜索树的节点个数
    int size(){
        return count;
    }
    
    // 返回二分搜索树是否为空
    bool isEmpty(){
        return count == 0;
    }
    
    // 向二分搜索树中插入一个新的(key, value)数据对
    void insert(Key key, Value value){
        root = insert(root, key, value);
    }
    
    // 查看二分搜索树中是否存在键key
    bool contain(Key key){
        return contain(root, key);
    }
    
    // 在二分搜索树中搜索键key所对应的值。如果这个值不存在, 则返回NULL
    Value* search(Key key){
        return search( root , key );
    }
    
    // 二分搜索树的前序遍历
    void preOrder(){
        preOrder(root);
    }
    
    // 二分搜索树的中序遍历
    void inOrder(){
        inOrder(root);
    }
    
    // 二分搜索树的后序遍历
    void postOrder(){
        postOrder(root);
    }
    
    // 二分搜索树的层序遍历
    void levelOrder(){
        
        queue<Node*> q;
        q.push(root);
        while( !q.empty() ){
            
            Node *node = q.front();
            q.pop();
            
            cout<<node->key<<endl;
            
            if( node->left )
                q.push( node->left );
            if( node->right )
                q.push( node->right );
        }
    }
    
    // 寻找二分搜索树的最小的键值
    Key minimum(){
        assert( count != 0 );
        Node* minNode = minimum( root );
        return minNode->key;
    }
    
    // 寻找二分搜索树的最大的键值
    Key maximum(){
        assert( count != 0 );
        Node* maxNode = maximum(root);
        return maxNode->key;
    }
    
    // 从二分搜索树中删除最小值所在节点
    void removeMin(){
        if( root )
            root = removeMin( root );
    }
    
    // 从二分搜索树中删除最大值所在节点
    void removeMax(){
        if( root )
            root = removeMax( root );
    }
    
    // 从二分搜索树中删除键值为key的节点
    void remove(Key key){
        root = remove(root, key);
    }
    
private:
    // 向以node为根的二分搜索树中, 插入节点(key, value), 使用递归算法
    // 返回插入新节点后的二分搜索树的根
    Node* insert(Node *node, Key key, Value value){
        
        if( node == NULL ){
            count ++;
            return new Node(key, value);
        }
        
        if( key == node->key )
            node->value = value;
        else if( key < node->key )
            node->left = insert( node->left , key, value);
        else    // key > node->key
            node->right = insert( node->right, key, value);
        
        return node;
    }
    
    // 查看以node为根的二分搜索树中是否包含键值为key的节点, 使用递归算法
    bool contain(Node* node, Key key){
        
        if( node == NULL )
            return false;
        
        if( key == node->key )
            return true;
        else if( key < node->key )
            return contain( node->left , key );
        else // key > node->key
            return contain( node->right , key );
    }
    
    // 在以node为根的二分搜索树中查找key所对应的value, 递归算法
    // 若value不存在, 则返回NULL
    Value* search(Node* node, Key key){
        
        if( node == NULL )
            return NULL;
        
        if( key == node->key )
            return &(node->value);
        else if( key < node->key )
            return search( node->left , key );
        else // key > node->key
            return search( node->right, key );
    }
    
    // 对以node为根的二分搜索树进行前序遍历, 递归算法
    void preOrder(Node* node){
        
        if( node != NULL ){
            cout<<node->key<<endl;
            preOrder(node->left);
            preOrder(node->right);
        }
    }
    
    // 对以node为根的二分搜索树进行中序遍历, 递归算法
    void inOrder(Node* node){
        
        if( node != NULL ){
            inOrder(node->left);
            cout<<node->key<<endl;
            inOrder(node->right);
        }
    }
    
    // 对以node为根的二分搜索树进行后序遍历, 递归算法
    void postOrder(Node* node){
        
        if( node != NULL ){
            postOrder(node->left);
            postOrder(node->right);
            cout<<node->key<<endl;
        }
    }
    
    // 释放以node为根的二分搜索树的所有节点
    // 采用后续遍历的递归算法
    void destroy(Node* node){
        
        if( node != NULL ){
            destroy( node->left );
            destroy( node->right );
            
            delete node;
            count --;
        }
    }
    
    // 返回以node为根的二分搜索树的最小键值所在的节点, 递归算法
    Node* minimum(Node* node){
        if( node->left == NULL )
            return node;
        
        return minimum(node->left);
    }
    
    // 返回以node为根的二分搜索树的最大键值所在的节点, 递归算法
    Node* maximum(Node* node){
        if( node->right == NULL )
            return node;
        
        return maximum(node->right);
    }
    
    // 删除掉以node为根的二分搜索树中的最小节点, 递归算法
    // 返回删除节点后新的二分搜索树的根
    Node* removeMin(Node* node){
        
        if( node->left == NULL ){
            
            Node* rightNode = node->right;
            delete node;
            count --;
            return rightNode;
        }
        
        node->left = removeMin(node->left);
        return node;
    }
    
    // 删除掉以node为根的二分搜索树中的最大节点, 递归算法
    // 返回删除节点后新的二分搜索树的根
    Node* removeMax(Node* node){
        
        if( node->right == NULL ){
            
            Node* leftNode = node->left;
            delete node;
            count --;
            return leftNode;
        }
        
        node->right = removeMax(node->right);
        return node;
    }
    
    // 删除掉以node为根的二分搜索树中键值为key的节点, 递归算法
    // 返回删除节点后新的二分搜索树的根
    Node* remove(Node* node, Key key){
        
        if( node == NULL )
            return NULL;
        
        if( key < node->key ){
            node->left = remove( node->left , key );
            return node;
        }
        else if( key > node->key ){
            node->right = remove( node->right, key );
            return node;
        }
        else{   // key == node->key
            
            // 待删除节点左子树为空的情况
            if( node->left == NULL ){
                Node *rightNode = node->right;
                delete node;
                count --;
                return rightNode;
            }
            
            // 待删除节点右子树为空的情况
            if( node->right == NULL ){
                Node *leftNode = node->left;
                delete node;
                count--;
                return leftNode;
            }
            
            // 待删除节点左右子树均不为空的情况
            
            // 找到比待删除节点大的最小节点, 即待删除节点右子树的最小节点
            // 用这个节点顶替待删除节点的位置
            Node *successor = new Node(minimum(node->right));
            count ++;
            
            successor->right = removeMin(node->right);
            successor->left = node->left;
            
            delete node;
            count --;
            
            return successor;
        }
    }
};


void shuffle( int arr[], int n ){
    
    srand( time(NULL) );
    for( int i = n-1 ; i >= 0 ; i -- ){
        int x = rand()%(i+1);
        swap( arr[i] , arr[x] );
    }
}

void BSTTest(){
    
    srand(time(NULL));
    BST<int,int> bst = BST<int,int>();
    
    // 取n个取值范围在[0...n)的随机整数放进二分搜索树中
    int n = 10000;
    for( int i = 0 ; i < n ; i ++ ){
        int key = rand()%n;
        // 为了后续测试方便,这里value值取和key值一样
        int value = key;
        bst.insert(key,value);
    }
    // 注意, 由于随机生成的数据有重复, 所以bst中的数据数量大概率是小于n的
    
    // order数组中存放[0...n)的所有元素
    int order[n];
    for( int i = 0 ; i < n ; i ++ )
        order[i] = i;
    // 打乱order数组的顺序
    shuffle( order , n );
    
    // 乱序删除[0...n)范围里的所有元素
    for( int i = 0 ; i < n ; i ++ )
        if( bst.contain( order[i] )){
            bst.remove( order[i] );
            cout<<"After remove "<<order[i]<<" size = "<<bst.size()<<endl;
        }
    
    // 最终整个二分搜索树应该为空
    cout << bst.size() << endl;
}

/*--------------------------------------------------------------*/

void BTSSearchTest(){
    // 我们使用文本量更小的共产主义宣言进行试验:)
    string filename = "/Users/kevin/Desktop/插入排序/BST-二叉搜索树/communist.txt";
    vector<string> words;
    
    if( FileOps::readFile(filename, words) ) {
        
        cout << "There are totally " << words.size() << " words in " << filename << endl;
        cout << endl;
        
        
        // 测试1, 我们按照文本原有顺序插入进二分搜索树
        time_t startTime = clock();
        BST<string, int> *bst = new BST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = (*bst).search(*iter);
            if (res == NULL)
                (*bst).insert(*iter, 1);
            else
                (*res)++;
        }
        
        // 我们查看unite一词的词频
        if( bst->contain("unite") )
            cout << "'unite' : " << *(*bst).search("unite") << endl;
        else
            cout << "No word 'unite' in " + filename << endl;
        time_t endTime = clock();
        
        cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
        cout << endl;
        
        delete bst;
        
        
        // 测试2, 我们按照文本原有顺序插入顺序查找表
        startTime = clock();
        SequenceST<string, int> *sst = new SequenceST<string, int>();
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = (*sst).search(*iter);
            if (res == NULL)
                (*sst).insert(*iter, 1);
            else
                (*res)++;
        }
        
        // 我们查看unite一词的词频
        if( sst->contain("unite") )
            cout << "'unite' : " << *(*sst).search("unite") << endl;
        else
            cout << "No word 'unite' in " + filename << endl;
        endTime = clock();
        
        cout << "SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
        cout << endl;
        
        delete sst;
        
        
        // 测试3, 我们将原文本排序后插入二分搜索树, 查看其效率
        startTime = clock();
        BST<string, int> *bst2 = new BST<string, int>();
        
        sort( words.begin() , words.end() );
        for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
            int *res = (*bst2).search(*iter);
            if (res == NULL)
                (*bst2).insert(*iter, 1);
            else
                (*res)++;
        }
        
        // 我们查看unite一词的词频
        cout << "'unite' : " << *(*bst2).search("unite") << endl;
        endTime = clock();
        
        cout << "BST2 , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
        cout << endl;
        
        delete bst2;
    }
}

int main(int argc, const char * argv[]) {

    
    // 手动创建Leetcode题页上的测试用例。
    // 当然, 有更好的更智能的创建二叉树的方式, 有兴趣的同学可以自行研究编写程序:)
    
    /*****************
     * 测试用例:
     *
     *       10
     *      /  \
     *     5   -3
     *    / \    \
     *   3   2   11
     *  / \   \
     * 3  -2   1
     *****************/
    TreeNode* node1 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(-2);
    
    TreeNode* node3 = new TreeNode(3);
    node3->left = node1;
    node3->right = node2;
    
    TreeNode* node4 = new TreeNode(1);
    TreeNode* node5 = new TreeNode(2);
    node5->right = node4;
    
    TreeNode* node6 = new TreeNode(5);
    node6->left = node3;
    node6->right = node5;
    
    TreeNode* node7 = new TreeNode(11);
    TreeNode* node8 = new TreeNode(-3);
    node8->right = node7;
    
    TreeNode* node9 = new TreeNode(10);
    node9->left = node6;
    node9->right = node8;
    
    cout << Solution().pathSum(node9, 8) << endl;
    
    binarySearch();
    
    BSTTest();
    
    
    BTSSearchTest();
    
    return 0;
}

