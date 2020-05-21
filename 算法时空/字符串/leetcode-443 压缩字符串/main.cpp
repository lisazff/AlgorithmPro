//
//  main.cpp
//  leetcode-443 压缩字符串
//
//  Created by 佐毅 on 2020/2/7.
//  Copyright © 2020 dfjr. All rights reserved.
//

/**
 给定一组字符，使用原地算法将其压缩。
 
 压缩后的长度必须始终小于或等于原数组长度。
 
 数组的每个元素应该是长度为1 的字符（不是 int 整数类型）。
 
 在完成原地修改输入数组后，返回数组的新长度。
 
  
 
 进阶：
 你能否仅使用O(1) 空间解决问题？
 
 示例 1：
 
 输入：
 ["a","a","b","b","c","c","c"]
 
 输出：
 返回6，输入数组的前6个字符应该是：["a","2","b","2","c","3"]
 
 说明：
 "aa"被"a2"替代。"bb"被"b2"替代。"ccc"被"c3"替代。
 示例 2：
 
 输入：
 ["a"]
 
 输出：
 返回1，输入数组的前1个字符应该是：["a"]
 
 说明：
 没有任何字符串被替代。
 
 示例 3：
 
 输入：
 ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
 
 输出：
 返回4，输入数组的前4个字符应该是：["a","b","1","2"]。
 
 说明：
 由于字符"a"不重复，所以不会被压缩。"bbbbbbbbbbbb"被“b12”替代。
 注意每个数字在数组中都有它自己的位置。
 注意：
 
 所有字符都有一个ASCII值在[35, 126]区间内。
 1 <= len(chars) <= 1000。
 */

/**
 解题思路
 
 1.使用两个指针 read 和 write 分别标记读和写的位置，使用anchor用于标记连续出现字符的其实位置指针。
 2.read用于读取字符串，write用于写出内容，利用anchor计算相同字符的个数。
 3.返回write即是压缩后字符串的长度。
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = (int)chars.size();
        int cur = 0;
        for(int i = 0, j = 0; i < n; j = i) {
            while(i < n && chars[i] == chars[j]) {
                i++;
            }
            chars[cur++] = chars[j];
            if(i - j == 1) {
                continue;
            }
            string s = to_string(i - j);
            for(int t = 0; t < s.size(); t++) {
                chars[cur++] = s[t];
            }
        }
        return cur;
    }
    
    void reverse_index(vector<char>& vec){
        int i;
        cout << "reverse index : " << endl;
        for (i = 0; i < vec.size(); i++){
            cout << vec[i] << " ";
        }
    }
};

int main(int argc, const char * argv[]) {
    
    Solution s;
    vector<char> str;
    
    str.push_back('a');
    str.push_back('b');
    str.push_back('b');
    str.push_back('b');
    str.push_back('c');
    str.push_back('c');
    
    
    int rtn = s.compress(str);
    cout << endl;
    
    cout << rtn << endl;
    cout << endl;
    return 0;
}
