//
//  main.cpp
//  leetcode-383 赎金信
//
//  Created by 佐毅 on 2020/2/7.
//  Copyright © 2020 dfjr. All rights reserved.
//

/**
 给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串ransom能不能由第二个字符串magazines里面的字符构成。
 如果可以构成，返回 true ；否则返回 false。
 
 (题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。)
 
 注意：
 
 你可以假设两个字符串均只含有小写字母。
 
 canConstruct("a", "b") -> false
 canConstruct("aa", "ab") -> false
 canConstruct("aa", "aab") -> true
 
 思路：此题最难的就是读懂题，此题的意思是用后面字符串的字符是否可以组成前面一个字符，所以此题只需要判断后面各个字符的总数是否大于前面字符的即可，
 这又成了一个映射问题，字符映射个数，所以我们又可以用map来解决问题，只需要先遍历后面字符串统计所有字符出现的次数，
 然后在遍历前面一个字符串，然后每遍历一个字符串就减去1再判断是否小于0即可。遇到有映射关系的题就要优先考虑使用map
 
 */
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[26] = {0};
        for(int i = 0; i < magazine.length(); i++)
            cnt[magazine[i]-'a']++;
        for(int i = 0; i < ransomNote.length(); i++)
            if(--cnt[ransomNote[i]-'a'] < 0)
                return false;
        return true;
    }
};

int main(int argc, const char * argv[]) {
    
    string a = "aa";
    string b = "aabb";
    
    Solution solution;
    cout << solution.canConstruct(a, b) << endl;
    cout << endl;
    
    return 0;
}
