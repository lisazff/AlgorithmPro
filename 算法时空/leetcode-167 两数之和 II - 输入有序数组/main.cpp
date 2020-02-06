//
//  main.cpp
//  leetcode-167 两数之和 II - 输入有序数组
//
//  Created by 佐毅 on 2020/2/4.
//  Copyright © 2020 dfjr. All rights reserved.
//

/**
 ### 题目描述
 
 给定一个已按照**升序排列** 的有序数组，找到两个数使得它们相加之和等于目标数。
 
 函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2*。*
 
 **说明:**
 
 - 返回的下标值（index1 和 index2）不是从零开始的。
 - 你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
 
 **示例:**
 输入: numbers = [2, 7, 11, 15], target = 9
 输出: [1,2]
 解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
 */

/**
 ### 题目解析
 初始化左指针 left 指向数组起始，初始化右指针 right 指向数组结尾。
 
 根据**已排序**这个特性，
 
 - （1）如果 numbers[left] 与 numbers[right] 的和 tmp 小于 target ，说明应该增加 tmp ，因此 left 右移指向一个较大的值。
 - （2）如果 tmp大于 target ，说明应该减小 tmp ，因此 right 左移指向一个较小的值。
 - （3）tmp 等于 target ，则找到，返回 left + 1 和 right + 1。（注意以 1 为起始下标）
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unsigned long l = 0, r = numbers.size() - 1;
        vector<int> nums;
        while(l < r){
            if(numbers[l] + numbers[r] == target){
                int res[2] = {static_cast<int>(l+1), static_cast<int>(r+1)};
                return vector<int>(res, res+2);
            }
            else if(numbers[l] + numbers[r] < target)
                l ++;
            else
                r --;
        }
        return nums;
    }
};

int main(int argc, const char * argv[]) {
     vector<int> nums;
     nums.push_back(2);
     nums.push_back(11);
     nums.push_back(7);
     nums.push_back(15);
     
     for (int i = 0; i < nums.size(); i++){
         cout << nums[i] << endl;
     }
     
     cout << endl;
    
    Solution solution;
    vector<int> result;

    result = solution.twoSum(nums, 18);
    
    for (int i = 0; i < result.size(); i++){
        cout << result[i] << endl;
    }
    return 0;
 }
