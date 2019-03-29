//
//  main.cpp
//  leetcode-09回文数
//
//  Created by 佐毅 on 2018/3/19.
//  Copyright © 2018年 dfjr. All rights reserved.
//

/*
 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 
 示例 1:
 
 输入: 121
 输出: true
 示例 2:
 
 输入: -121
 输出: false
 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 示例 3:
 
 输入: 10
 输出: false
 解释: 从右向左读, 为 01 。因此它不是一个回文数。
 */



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)return false;
        if (x >= 0 && x < 10)return true;
        long long temp=0;
        int xx = x;
        while (x!=0)
        {
            int n = x % 10;
            temp = temp * 10 + n;
            x /= 10;
        }
        if (temp == xx)return true;
        else return false;
    }
};

int main(int argc, const char * argv[]) {
    
    
    Solution sol;
    
    int num  =  121;
    cout << sol.isPalindrome(num) << endl;
    
    return 0;
}
