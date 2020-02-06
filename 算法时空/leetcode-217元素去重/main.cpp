//
//  main.cpp
//  元素去重
//
//  Created by 佐毅 on 2018/3/15.
//  Copyright © 2018年 dfjr. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include<unordered_set>
#include <vector>

/*
 
 Leetcode 217. 存在重复元素
 给定一个整数数组，判断是否存在重复元素。
 
 如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。
 
 示例 1:
 
 输入: [1,2,3,1]
 输出: true
 
 示例 2:
 
 输入: [1,2,3,4]
 输出: false
 
 示例 3:
 
 输入: [1,1,1,3,3,4,3,2,4,2]
 输出: true

 
 先排序，然后判断相邻的两个数是否相同
 */
using namespace std;


bool hasDuplicateElement(vector<int>& nums){
    int N = 0;
    long len = nums.size();
    for (N = 0; N < len - 1; N++)
    {
        if (nums[N] == nums[N + 1])
        {
            return true;
        }
    }
    return false;
}

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> s;
    for (auto num : nums)
    {
        if (s.find(num) != s.end())
        {
            return true;
        }
        s.insert(num);
    }
    return false;
}


int main(int argc, const char * argv[]) {
    
    int a[10] = {1,1,1,3,3,4,3,2,4,2};
    sort(a,a+10);
    
    for( int i = 0 ; i < 10 ; i ++ )
        cout<<a[i]<<" ";
    cout<<endl;
 
    vector<int> b;
    for(int i=0;i< 10;i++){
        b.push_back(a[i]);
    }
   
    cout<<endl;
    bool result = hasDuplicateElement(b);
    cout<< result <<" ";
    
    return 0;
}
