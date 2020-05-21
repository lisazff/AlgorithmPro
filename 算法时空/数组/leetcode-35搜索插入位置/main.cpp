//
//  main.cpp
//  leetcode-35搜索插入位置
//
//  Created by 佐毅 on 2018/3/20.
//  Copyright © 2018年 dfjr. All rights reserved.
//

/*
 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
 
 你可以假设数组中无重复元素。
 
 示例 1:
 输入: [1,3,5,6], 5
 输出: 2
 
 
 示例 2:
 输入: [1,3,5,6], 2
 输出: 1
 
 
 示例 3:
 输入: [1,3,5,6], 7
 输出: 4
 
 
 示例 4:
 输入: [1,3,5,6], 0
 输出: 0
 
 */
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    long searchInsert(vector<int>& nums, int target) {
        //end() 函数返回一个指向当前vector末尾元素的下一位置的迭代器.要访问末尾元素,需要先将此迭代器减1。
        auto first = nums.begin(), last = nums.end();  //end()返回尾地址，尾地址不指向任何存储的元素，而是标志vector的结束。
        while (first < last) {
            auto mid = first + ((last - first) >> 1); //二分查找法
            if (*mid < target) {
                first = mid + 1;
            } else {
                last = mid;
            }
        }
        return first - nums.begin();
    }
};
int main(int argc, const char * argv[]) {
    
    Solution sol;
    int a[7] = {1,3,4,6,9,10,12};
    
    vector<int> b;
    for(int i=0;i< 7;i++){
        b.push_back(a[i]);
    }
    cout<<endl;
    
    cout<< sol.searchInsert(b, 5) <<endl;
    return 0;
}


