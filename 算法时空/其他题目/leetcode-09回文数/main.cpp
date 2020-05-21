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
#include <string>

using namespace std;
class Solution {
public:
    //将数倒转
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
    
    bool isPalindromes(int x) {
        //边界判断
        if (x < 0) return false;
        int div = 1;
        while (x / div >= 10) div *= 10;
        while (x > 0) {
            int left = x / div;
            int right = x % 10;
            if (left != right) return false;
            x = (x % div) / 10;
            div /= 100;
        }
        return true;
    }
    
    // 转字符串
    bool isPalindromess (int x) {
        string tmp=to_string(x);
        string tmp2=tmp;
        reverse(tmp2.begin(),tmp2.end());
        if(tmp==tmp2) return true;
        return false;
    }
    
    //利用vector，直接比较首尾
    bool isPalindromesss (int x) {
        if(x<0) return false;
        if(x/10==0) return true;
        vector<int> tmp;
        while(x>0){
            tmp.emplace_back(x%10);
            x=x/10;
        }
        for(long i=tmp.size()-1,j=0;static_cast<void>(i>0),j<i;i--,j++)
            if(tmp[i]!=tmp[j]) return false;
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    
    int num  =  121;
    cout << sol.isPalindrome(num) << endl;
    
    return 0;
}
