//
//  main.cpp
//  leetcode-13罗马数字转整数
//
//  Created by 佐毅 on 2018/3/20.
//  Copyright © 2018年 dfjr. All rights reserved.
//
/*
 罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
 
 字符 数值
 I 1
 V 5
 X 10
 L 50
 C 100
 D 500
 M 1000
 
 例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
 
 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
 
 
 I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
 X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
 C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
 
 
 给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
 
 示例 1:
 
 输入: "III"
 输出: 3
 
 示例 2:
 
 输入: "IV"
 输出: 4
 
 示例 3:
 
 输入: "IX"
 输出: 9
 
 示例 4:
 
 输入: "LVIII"
 输出: 58
 解释: L = 50, V= 5, III = 3.
 
 
 示例 5:
 
 输入: "MCMXCIV"
 输出: 1994
 解释: M = 1000, CM = 900, XC = 90, IV = 4.

 */

/*
 组数规则
 
 有两条须注意掌握：
 1.基本数字 Ⅰ、X 、C 中的任何一个、自身连用构成数目、或者放在大数的右边连用构成数目、都不能超过三个；放在大数的左边只能用一个；
 2.不能把基本数字 V 、L 、D 中的任何一个作为小数放在大数的左边采用相减的方法构成数目；放在大数的右边采用相加的方式构成数目、只能使用一个；
 
考虑两种情况即可：
 第一，如果当前数字是最后一个数字，或者之后的数字比它小的话，则加上当前数字
 第二，其他情况则减去这个数字
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        if (s.empty()) { return 0; }
        unordered_map<char, int> mp { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
        int result =  0;
      
        for (long i = 0; i < s.size(); i++) {
            int value = mp[s[i]];
            if (i == s.size()-1 || mp[s[i + 1]] <= mp[s[i]] ) {
                result += value;
            }else {
                result -= value;
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
  
    string str2( "LVIII" );
     string str3( "MCMXCIV" );
    Solution sol;
  
    cout <<  sol.romanToInt(str2) << endl;
    cout <<  sol.romanToInt(str3) << endl;

    cout << endl;
    return 0;
}
