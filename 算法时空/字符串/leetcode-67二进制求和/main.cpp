//
//  main.cpp
//  leetcode-67二进制求和
//
//  Created by 佐毅 on 2018/3/21.
//  Copyright © 2018年 dfjr. All rights reserved.
//



/*
 给定两个二进制字符串，返回他们的和（用二进制表示）。
 
 输入为非空字符串且只包含数字 1 和 0。
 
 示例 1:
 
 输入: a = "11", b = "1"
 输出: "100"
 
 示例 2:
 
 输入: a = "1010", b = "1011"
 输出: "10101"
 */


/*
    解题思路：
    用了两个指针分别指向a和b的末尾，然后每次取出一个字符，转为数字，若无法取出字符则按0处理，然后定义进位carry，
    初始化为0，将三者加起来，对2取余即为当前位的数字，
    对2取商即为当前进位的值，记得最后还要判断下carry，如果为1的话，要在结果最前面加上一个1。
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    
    string addBinary(string a, string b) {
        string res = "";
        long m = a.size() - 1, n = b.size() - 1, carry = 0;
        while (m >= 0 || n >= 0) {
            //用了两个指针分别指向a和b的末尾
            //然后每次取出一个字符，转为数字，若无法取出字符则按0处理，然后定义进位carry
            int p = m >= 0 ? a[m--] - '0' : 0;
            int q = n >= 0 ? b[n--] - '0' : 0;
           
            // 初始化为0，将三者加起来，对2取余即为当前位的数字
            long sum = p + q + carry;
            //对2取商即为当前进位的值，记得最后还要判断下carry，如果为1的话，要在结果最前面加上一个1
            res = to_string(sum % 2) + res;
            carry = sum / 2;
        }
        return carry == 1 ? "1" + res : res;
    }
};



int main(int argc, const char * argv[]) {
    
    
    Solution solu;
    
    string str1("1010");
    string str2("1011");
    
    cout << solu.addBinary(str1, str2) << endl;
    return 0;
}
