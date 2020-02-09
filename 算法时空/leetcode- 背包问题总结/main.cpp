//
//  main.cpp
//  leetcode- 背包问题总结
//
//  Created by 佐毅 on 2020/2/9.
//  Copyright © 2020 dfjr. All rights reserved.
//

/**
 题目描述：
 
 一个小偷面前有一堆（n个）财宝，每个财宝有重量w和价值v两种属性，而他的背包只能携带一定重量的财宝（Capacity），
 在已知所有财宝的重量和价值的情况下，如何选取财宝，可以最大限度的利用当前的背包容量，取得最大价值的财宝（或求出能够获取财宝价值的最大值）。
 
 0-1背包问题
 即限定每个物品要么拿（1个）要么不拿（0个）。
 
 乍一看这个问题有两个维度，一个是当前物品i，另一个是当前容量c，于是我们可以用f[n,C]来表示将n个物品放入容量为C的背包可以得到的最大收益，而第i个物品无非拿与不拿两种情况，因此可以表示为：
 
 f[i][c] = max( f[i - 1][c], f[i - 1][c - w[i]] + v[i] )
 这便是我们的最优子结构，即不拿第 i 件物品和拿第 i 件物品中的最大值，当然，这里要保证w[i] <= c，否则f[i][c] = f[i - 1][c]。
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int knapsack(vector<int> v, vector<int> w, int n, int C){
        vector<vector<int> > f(n, vector<int>(C + 1));
        for(int i = 0; i < n; i++)
            f[i][0] = 0;
        for(int j = 1; j <= C; j++)
            if(j >= w[0])
                f[0][j] = v[0];
            else
                f[0][j] = 0;
        for(int i = 1; i < n; i++){
            for(int j = 1; j <= C; j++){
                if(j < w[i]){
                    f[i][j] = f[i - 1][j];
                }
                else{
                    f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]] + v[i]);
                }
            }
        }
        return f[n - 1][C];
    }
};


int main(int argc, const char * argv[]) {
    
    vector<int> w ;
    w.push_back(3000);
    w.push_back(2000);
    w.push_back(1500);
    
 
    vector<int> v ;
    v.push_back(4);
    v.push_back(3);
    v.push_back(1);
    
    Solution solution;
    
    cout << solution.knapsack(w, v, 3, 4) << endl ;
    return 0;
}
