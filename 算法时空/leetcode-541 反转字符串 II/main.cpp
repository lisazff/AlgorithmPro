//
//  main.cpp
//  leetcode-541 反转字符串 II
//
//  Created by 佐毅 on 2020/2/7.
//  Copyright © 2020 dfjr. All rights reserved.
//

/**
 给定一个字符串和一个整数 k，你需要对从字符串开头算起的每个 2k 个字符的前k个字符进行反转。如果剩余少于 k 个字符，则将剩余的所有全部反转。
 如果有小于 2k 但大于或等于 k 个字符，则反转前 k 个字符，并将剩余的字符保持原样。

 示例:

 输入: s = "abcdefg", k = 2
 输出: "bacdfeg"
 要求:

 该字符串只包含小写的英文字母。
 给定字符串的长度和 k 在[1, 10000]范围内。
 */

/**
 解题思路

 分治算法，逐步进行；设 low = 0, high = 2 * k - 1; 对s[low]~ s[low + k - 1] 进行字符串的反转，
 即reverse(s, low, low + k - 1)，然后 循环(low < s.size()) low = high + 1, high = high + 2 * k 重复以上步骤
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int low = 0, high = 2 * k - 1;
        while( low < s.size()) {
            reverse(s, low, low + k - 1);
            low = high + 1;
            high += 2 * k;
        }
        return s;
    }

    void reverse(string & s, int low, int high) {
        int i = low;
        int j = min((int)s.size() - 1, high);
        for(; i < j; i++, j--){
            char c = s[i];
            s[i] = s[j];
            s[j] = c;
        }
    }
};


int main(int argc, const char * argv[]) {
    
    Solution solu;
    string str("abcabcbb");
    
    std::cout << solu.reverseStr(str,3);
    cout << endl;
    return 0;
}
