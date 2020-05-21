//
//  main.cpp
//  leetcode-20有效的括号
//
//  Created by 佐毅 on 2018/3/20.
//  Copyright © 2018年 dfjr. All rights reserved.
//

/*
 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 
 有效字符串需满足：
 
 
 左括号必须用相同类型的右括号闭合。
 左括号必须以正确的顺序闭合。
 
 
 注意空字符串可被认为是有效字符串。
 
 示例 1:
 
 输入: "()"
 输出: true
 
 
 示例 2:
 
 输入: "()[]{}"
 输出: true
 
 
 示例 3:
 
 输入: "(]"
 输出: false
 
 
 示例 4:
 
 输入: "([)]"
 输出: false
 
 
 示例 5:
 
 输入: "{[]}"
 输出: true
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> paren;
        for (char& c : s) {
            switch (c) {
                case '(':
                case '{':
                case '[': paren.push(c);
                     printf("%c\n",paren.top());
                    break;
                case ')': if (paren.empty() || paren.top()!='(') return false; else paren.pop(); break;
                case '}': if (paren.empty() || paren.top()!='{') return false; else paren.pop(); break;
                case ']': if (paren.empty() || paren.top()!='[') return false; else paren.pop(); break;
                default: ; //
            }
        }
        return paren.empty() ;
    }
    
    bool isValids(string s) {
            stack<char> stack;
            for( int i = 0 ; i < s.size() ; i ++ )
                if( s[i] == '(' || s[i] == '{' || s[i] == '[')
                    stack.push(s[i]);
                else{

                    if( stack.size() == 0 )
                        return false;

                    char c = stack.top();
                    stack.pop();

                    char match;
                    if( s[i] == ')' ){
                        match = '(';
                    }
                    else if( s[i] == ']' ){
                        match = '[';
                    }
                    else{
                        match = '{';
                    }

                    if(c != match)  return false;
                }

            if( stack.size() != 0 )
                return false;

            return true;
        }
    };
};


int main(int argc, const char * argv[]) {
    
    Solution solu;
    string str("([)]");
    cout <<  solu.isValid(str) << endl;
    return 0;
}
