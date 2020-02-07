//
//  main.cpp
//  leetcode-680 验证回文字符串 Ⅱ
//
//  Created by 佐毅 on 2020/2/7.
//  Copyright © 2020 dfjr. All rights reserved.
//


/**
 给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
 
 示例 1:
 
 输入: "aba"
 输出: True
 示例 2:
 
 输入: "abca"
 输出: True
 解释: 你可以删除c字符。
 注意:
 
 字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。
 */

/**
 解题思路
 贪心算法：贪心算法（又称贪婪算法）是指，在对问题求解时，总是做出在当前看来是最好的选择。
 也就是说，不从整体最优上加以考虑，他所做出的是在某种意义上的局部最优解。

 例如:"abccaba" 当a!=c时，要考虑删除一个。删除a，还是删除c呢？答案是都尝试一遍。
 即，isPalindrome(s,low+1,high)||isPalindrome(s,low,high-1)。只要其中一个是，就可以。
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int isPalindrome(char *s,int low,int high){
        while(low<high){
            if(s[low++]!=s[high--])
                return 0;
        }
        return 1;
    }

    bool validPalindrome(char * s){
        for(int low=0,high=(int)strlen(s)-1;low<high;low++,high--){
            if(s[low]!=s[high])
                return (isPalindrome(s,low+1,high)||isPalindrome(s,low,high-1));
        }
        return 1;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solu;
    
    char a[] = "abca";
    char *s = a;
    
    std::cout << solu.validPalindrome(s);
    cout << endl;
    return 0;
}
