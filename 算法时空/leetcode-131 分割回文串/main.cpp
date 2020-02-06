//
//  main.cpp
//  leetcode-131 分割回文串
//
//  Created by 佐毅 on 2020/2/2.
//  Copyright © 2020 dfjr. All rights reserved.
//

/**
 ### 题目描述

 给定一个字符串 *s*，将 *s* 分割成一些子串，使每个子串都是回文串。

 返回 *s* 所有可能的分割方案。

 **示例:**
  yaml
 输入: "aab"
 输出:
 [
   ["aa","b"],
   ["a","a","b"]
 ]
 */

/**
 ### 题目解析
 
 首先，对于一个字符串的分割，肯定需要将所有分割情况都遍历完毕才能判断是不是回文数。不能因为 **abba** 是回文串，就认为它的所有子串都是回文的。

 既然需要将所有的分割方法都找出来，那么肯定需要用到DFS（深度优先搜索）或者BFS（广度优先搜索）。

 在分割的过程中对于每一个字符串而言都可以分为两部分：左边一个回文串加右边一个子串，比如 "abc" 可分为 "a" + "bc" 。 然后对"bc"分割仍然是同样的方法，分为"b"+"c"。

 在处理的时候去优先寻找更短的回文串，然后回溯找稍微长一些的回文串分割方法，不断回溯，分割，直到找到所有的分割方法。

 举个🌰：分割"aac"。

 1. 分割为 a + ac
 2. 分割为 a + a + c，分割后，得到一组结果，再回溯到  a + ac
 3. a + ac 中 ac 不是回文串，继续回溯，回溯到 aac
 4. 分割为稍长的回文串，分割为 aa + c 分割完成得到一组结果，再回溯到 aac
 5. aac 不是回文串，搜索结束
 
 采用回溯的思想，找不同的子串
 关键并不是一个个向上添加的，而是用下标来控制
 一个lastindex表示上一个已经添加进去的回文串结束的位置，当前可以从lastindex下标开始，取i在[lastindex, length()-1]之间的片段，判断是回文串的话就添加到cur里，然后修改lastindex向下递归
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void reverse_index(vector<vector<string>> vec){
    int i,j;
    cout << "Use index : " << endl;
    for (i = 0; i < vec.size(); i++)
    {
        for(j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << " \n";
        cout << endl;
    }
}

class Solution {
public:
    vector<vector<string> > result;
    vector<string > temp;
    string str;
    bool isHuiWen(int start, int end) {
        int left = start, right = end;
        while (left < right) {
            if (str[left++] != str[right--]) return false;
        }
        return true;
    }
    void dfs(int level, int deepth) {
        if (level == deepth) {
            result.push_back(temp);
            return;
        }
        for (int i = level; i < deepth; i++) {
            if (!isHuiWen(level, i)) {
                continue;
            }
            temp.push_back(str.substr(level, i - level + 1));
            dfs(i + 1, deepth);
            temp.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        if (s.size() <= 0) return result;
        this->str = s;
        dfs(0, s.size());
        return result;
    }
};


int main(int argc, const char * argv[]) {
     Solution solution;
     string a = "A man, a plan, a canal: Panama";
     reverse_index(solution.partition(a));
    
    return 0;
}
