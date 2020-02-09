//
//  main.cpp
//  leetcode- 120 三角形最小路径和
//
//  Created by 佐毅 on 2020/2/9.
//  Copyright © 2020 dfjr. All rights reserved.
//

/**
 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
 
 例如，给定三角形：
 
 [
 [2],
 [3,4],
 [6,5,7],
 [4,1,8,3]
 ]
 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
 
 说明：
 
 如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
 */

/**
 
 (线性dp) 时间：O(n^2) & 空间：O(n*m)
 
 从上往下走的最小和 等价于 从下往上走的最小和
 状态表示: dp(i, j): 从最下层走到坐标i, j的所有路径中的 最小和
 dp(0, 0) 为所求
 转移方程: dp(i, j) = min(dp(i+1, j), dp(i+1, j+1)) + triangle(i, j)
 转移方程: 当前的位置(i, j)路径, 要不从左下角(i+1, j)或者是从右下角(i+1, j+1)转移过来.
 
 优化方案：
 
 一维动归。题目说明可O(n)的空间复杂度,又考虑到dp[i][j]经过dp[i+1][j+1],第i层从i+1层计算所得，计算完，i+1层就没用了，空间开始浪费。能不能利用这一块空间储存i层的最小路径呢？
 
 存储倒数第二行时，我们只需要前面的n-1个空间……以此类推，第一行只需要一个空间来存储最小路径和，这也正是我们要求解的结果。
 
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // 动态规划, 自底向上  递推式 dp[i][j] = min(dp[i+1][j], dp[i+1[j+1]) + triangle[i][j];
        int rowSize = (int)triangle.size();
        vector<vector<int>> dp(triangle);
        
        for(int i=rowSize-2;i>=0;i--) {
            for(int j=0; j<triangle[i].size(); j++) {
                dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
            }
        }
        return dp[0][0];
    }
    
    int minimumTotals(vector<vector<int>>& triangle) {
        vector<int> dp = triangle[triangle.size()-1]; // 倒数第二行开始计算
        for (int i = (int)triangle.size() - 2; i >= 0 ; i--){ // 自底向上
            for (int j = 0; j <= i; j++){
                dp[j] = (dp[j] < dp[j+1] ? dp[j] : dp[j+1]) + triangle[i][j];
            }
        }
        
        return dp[0];
    }
    
};

int main(int argc, const char * argv[]) {
    
    vector<vector<int> > vec(4); //初始化row * col二维动态数组，初始化值为0
    for(int i=0;i<4;i++){
        vec[i].resize(i+1);
    }
        
    vec[0][0] = 2;
    vec[1][0] = 3;
    vec[1][1] = 4;
    vec[2][0] = 6;
    vec[2][1] = 5;
    vec[2][2] = 7;
    vec[3][0] = 4;
    vec[3][1] = 1;
    vec[3][2] = 8;
    vec[3][3] = 3;
    
    Solution solution;
    
    cout << solution.minimumTotals(vec) << endl;
    
    return 0;
}
