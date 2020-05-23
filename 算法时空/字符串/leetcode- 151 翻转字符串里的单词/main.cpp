//
//  main.cpp
//  leetcode- 151 翻转字符串里的单词
//
//  Created by 佐毅 on 2020/5/21.
//  Copyright © 2020 dfjr. All rights reserved.
//

/**
 给定一个字符串，逐个翻转字符串中的每个单词。
 示例 1：

 输入: "the sky is blue"
 输出: "blue is sky the"
 示例 2：

 输入: "  hello world!  "
 输出: "world! hello"
 解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 示例 3：

 输入: "a good   example"
 输出: "example good a"
 解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
  

 说明：

 无空格字符构成一个单词。
 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/reverse-words-in-a-string
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int n = s.size();
        int pos = 0;
        for (int begin = 0; begin < n; ++begin) {
            if (s[begin] != ' ') {//找到了下一个字符串的起点
                if (pos != 0) { //放一个空格做间隔
                    s[pos++] = ' ';
                }
                int end = begin;
                while (end < n && s[end] != ' ') {//前移
                    s[pos++] = s[end++];
                }
                reverse(s.begin() + pos - (end - begin), s.begin() + pos); //局部反转
                begin = end;
            }
        }
        s.erase(s.begin() + pos, s.end());//末尾可能有多余空格
        return s;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
