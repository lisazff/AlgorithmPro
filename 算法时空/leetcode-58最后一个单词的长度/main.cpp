//
//  main.cpp
//  leetcode-58最后一个单词的长度
//
//  Created by 佐毅 on 2018/3/20.
//  Copyright © 2018年 dfjr. All rights reserved.
//

/*
 给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
 
 如果不存在最后一个单词，请返回 0 。
 
 说明：一个单词是指由字母组成，但不包含任何空格的字符串。
 
 示例:
 输入: "Hello World"
 输出: 5
 */

#include <iostream>
#include <string>

/*
 解题思路：
 
  从s的尾部开始，向后移动以查找第一个非空格字符。
  然后，从这个字符向后移动并计算非空格字符的数量，直到我们通过S的头部或遇到空格字符为止。
  计数将是最后一个单词的长度。
 */

using namespace std;

class Solution {
public:
    long lengthOfLastWord(string s) {
        long len = 0, tail = s.length() - 1;
        while (tail >= 0 && s[tail] == ' ') tail--;
        while (tail >= 0 && s[tail] != ' ') {
            len++;
            tail--;
        }
        return len;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solu;
    
    string str("Hello World");
    
    cout << solu.lengthOfLastWord(str) << endl;
    return 0;
}
