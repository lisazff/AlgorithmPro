//
//  main.cpp
//  leetcode-164  最大间距
//
//  Created by 佐毅 on 2020/5/17.
//  Copyright © 2020 dfjr. All rights reserved.
//

/**
 给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。

 如果数组元素个数小于 2，则返回 0。

 示例 1:

 输入: [3,6,9,1]
 输出: 3
 解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9) 之间都存在最大差值 3。
 示例 2:

 输入: [10]
 输出: 0
 解释: 数组元素个数小于 2，因此返回 0。
 说明:

 你可以假设数组中所有元素都是非负整数，且数值在 32 位有符号整数范围内。
 请尝试在线性时间复杂度和空间复杂度的条件下解决此问题。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/maximum-gap
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        sort(&nums[0],&nums[0]+nums.size());
        int maxdif=0;
        for(int i=1;i<nums.size();i++)   maxdif=max(maxdif,abs(nums[i]-nums[i-1]));
        return maxdif;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(7);
    nums.push_back(10);
    nums.push_back(11);
    nums.push_back(7);
    nums.push_back(12);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(16);
    nums.push_back(18);
    nums.push_back(19);

    for (int i = 0; i < nums.size(); i++){
        cout << nums[i] << endl;
    }
    
    cout << endl;
    
    Solution solution;
    int maxdif = solution.maximumGap(nums);
    cout << maxdif << endl;;
    return 0;
}
