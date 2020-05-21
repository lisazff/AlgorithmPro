//
//  main.cpp
//  leetcode- 122 买卖股票的最佳时机
//
//  Created by 佐毅 on 2020/2/9.
//  Copyright © 2020 dfjr. All rights reserved.
//

/**
 买卖股票的最佳时机

 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

 如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

 注意你不能在买入股票前卖出股票。

 示例 1:

 输入: [7,1,5,3,6,4]
 输出: 5
 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
      注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
 示例 2:

 输入: [7,6,4,3,1]
 输出: 0
 解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。

 思路：数组中找到一组可以获得利润的值，然后不断更新他的最大值和最小值，两者最后之差就是他的结果。
 　　
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int cnt=0;
        for (int i=0;i<prices.size()-1;++i){
            if(prices[i]<prices[i+1])
                cnt += prices[i+1]-prices[i];
        }
        return cnt;
    }
};


int main(int argc, const char * argv[]) {
 
    //[7,1,5,3,6,4]
    
    vector<int> prices ;
    prices.push_back(7);
    prices.push_back(1);
    prices.push_back(5);
    prices.push_back(3);
    prices.push_back(6);
    prices.push_back(4);

    Solution solution;
    
    cout << solution.maxProfit(prices) << endl ;

    return 0;
}
