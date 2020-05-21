//
//  main.cpp
//  leetcode-07整数反转
//
//  Created by 佐毅 on 2018/3/19.
//  Copyright © 2018年 dfjr. All rights reserved.
//

/*
 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 
 示例 1:
 
 输入: 123
 输出: 321
 
 示例 2:
 
 输入: -123
 输出: -321
 
 示例 3:
 
 输入: 120
 输出: 21
 注意:
 
 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
     long long  reverse(int x) {
        long long res = 0;
        while (x)
        {
            int temp = x % 10;
            x /= 10;
            if (res*10 + temp  > INT_MAX || res*10+temp < INT_MIN)
                return 0;
            res = 10* res + temp;
        }
        return res;
    }
};
int main(int argc, const char * argv[]) {
   
    Solution sol;
    
    int num  =  -235;
    cout << sol.reverse(num) << endl;
    return 0;
}
