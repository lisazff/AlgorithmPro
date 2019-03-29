//
//  main.cpp
//  leetcode-66加一
//
//  Created by 佐毅 on 2018/3/20.
//  Copyright © 2018年 dfjr. All rights reserved.
//


/*
 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 
 最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。
 
 你可以假设除了整数 0 之外，这个整数不会以零开头。
 
 示例 1:
 
 输入: [1,2,3]
 输出: [1,2,4]
 解释: 输入数组表示数字 123。
 
 
 示例 2:
 
 输入: [4,3,2,1]
 输出: [4,3,2,2]
 解释: 输入数组表示数字 4321。
 */

/*
    解题思路：
 
    该算法也是从后向前判断，
    但是它是判断该元素是否等于9，若不等于那么就直接加一跳出循环；
    若等于把该元素赋值为0继续向前循环。
    最后还需判断首位数字若是等于0，说明首位有进位则需插入1
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        bool carry = true;
        
        for(long i=digits.size()-1; i >= 0 && carry; i--) {
            cout << digits[i] << endl;
            carry = (++digits[i]%=10) == 0;
            print(digits);
        }
        
        if(carry) {
            digits.insert(digits.begin(), 1);
        }
        
        return digits;
    }
    
    void print( vector<int> vector1){
        for(int i=0 ;i<vector1.size();i++)
            cout<<vector1[i]<<" ";
        
        cout<<endl;
    }
};


int main(int argc, const char * argv[]) {
   
    Solution sol;
    
    int a[] = {4,3,2,1};
    int ilen = (sizeof(a)) / (sizeof(a[0]));
    vector<int> b;
    for(int i=0;i< ilen;i++){
        b.push_back(a[i]);
    }
    cout<<endl;
    
    vector<int> d = sol.plusOne(b);
    sol.print(d);
    
    return 0;
}
