//
//  main.cpp
//  leetcode-1003 调整数组顺序使奇数位于偶数前面
//
//  Created by 佐毅 on 2020/3/23.
//  Copyright © 2020 dfjr. All rights reserved.
//

#include <iostream>

/**
 解题思路
 j保存当前待交换的位置， i向后滑动寻找奇数，找到后交换nums[i]和nums[j]
 每次交换后j向后滑动1，[j,i)之间绝对不会出现奇数
 
 尾双指针
 定义头指针 leftleft ，尾指针 rightright .
 leftleft 一直往右移，直到它指向的值为偶数
 rightright 一直往左移， 直到它指向的值为奇数
 交换 nums[left]nums[left] 和 nums[right]nums[right] .
 重复上述操作，直到 left == rightleft==right .


 */
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size(); ++i) {
            if (nums[i] % 2) swap(nums[i], nums[j++]);
        }
        return nums;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
