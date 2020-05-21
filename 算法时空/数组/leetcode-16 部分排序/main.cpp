//
//  main.cpp
//  leetcode-16 部分排序
//
//  Created by 佐毅 on 2020/5/17.
//  Copyright © 2020 dfjr. All rights reserved.
//

/**
 给定一个整数数组，编写一个函数，找出索引m和n，只要将索引区间[m,n]的元素排好序，整个数组就是有序的。注意：n-m尽量最小，也就是说，找出符合条件的最短序列。函数返回值为[m,n]，若不存在这样的m和n（例如整个数组是有序的），请返回[-1,-1]。
 
 示例：
 
 输入： [1,2,4,7,10,11,7,12,6,7,16,18,19]
 输出： [3,9]
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/sub-sort-lcci
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        if (array.empty()) return {-1,-1};
        
        // 1.从左向右 寻找最大的max (默认第一个是最大index)
        // 2.记录max 如果后面有比这个小的 说明是逆序（记住当前ndex）
        int max = array[0];
        int length = (int)array.size();
        int rightIndex = -1;
        for (int i = 1; i<=length-1; i++) {
            int v = array[i];
            if (v >= max) {
                max = v;
            }else {
                rightIndex = i;
            }
        }
        
        if (rightIndex == -1) return {-1,-1};
        
        // 这里没必要合并到上面 逻辑清晰些，，性能一样
        // 3.从右向左和上面完全一样(修改运算逻辑)
        int min = array[length-1];
        int leftIndex = -1;
        for (int i = length-2; i >= 0; --i) {
            int v = array[i];
            if (v <= min) {
                min = v;
            }else {
                leftIndex = i;
            }
        }
        
        return {leftIndex,rightIndex};
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
    vector<int> result;
    
    result = solution.subSort(nums);
    
    for (int i = 0; i < result.size(); i++){
        cout << result[i] << endl;
    }
    return 0;
}
