//
//  main.cpp
//  leetcode- 242 有效的字母异位词
//
//  Created by 佐毅 on 2020/5/21.
//  Copyright © 2020 dfjr. All rights reserved.
//

/**
 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 
 示例 1:
 
 输入: s = "anagram", t = "nagaram"
 输出: true
 示例 2:
 
 输入: s = "rat", t = "car"
 输出: false
 说明:
 你可以假设字符串只包含小写字母。
 
 进阶:
 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/valid-anagram
 */
#include <iostream>
#include <string>
using namespace std;

/**
 构造哈希
 构建一个数组，索引0-25分别对应26个字母，
 分别遍历s和t两个string，第一轮对应字母出现一次++，第二轮出现一次--
 两个数组如果完全相等，则数组中所有元素的值应为0，
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        
        int hash[26]={0};       //构建哈希数组
        for(auto n:s)
            hash[n-'a']++;
        for(auto n:t)
            hash[n-'a']--;
        for(int i=0;i<26;i++)
            if(hash[i]!=0)   return false;          //如果两数组不完全相等
        return true;
    }
};

int main(int argc, const char * argv[]) {
    string s = "anagram";
    string t = "nagaram";

    Solution solution;
    cout << solution.isAnagram(s,t) << endl;
    return 0;
}
