//
//  main.cpp
//  leetcode-344 反转字符串
//
//  Created by 佐毅 on 2020/2/7.
//  Copyright © 2020 dfjr. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string reverseString(string s) {
        int length = (int)s.size();
        for (int i = 0; i< length/2; i++) {
            char ch = s[i];
            s[i] = s[length -i-1];
            s[length -i-1] = ch;
        }
        return s;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution solu;
    string str("abcabcbb");
    std::cout << solu.reverseString(str);
    cout << endl;
    return 0;
}
