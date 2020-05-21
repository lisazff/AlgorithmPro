//
//  main.cpp
//  leetcode-75 颜色分类
//
//  Created by 佐毅 on 2020/2/1.
//  Copyright © 2020 dfjr. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

/**
 ### 题目描述

 给定一个包含红色、白色和蓝色，一共 *n* 个元素的数组，**原地**对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。

 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。

 **注意:**
 不能使用代码库中的排序函数来解决这道题。

 **示例:**

 输入: [2,0,2,1,1,0]
 输出: [0,0,1,1,2,2]
 */

/**
 ### 题目解析

 结合三路快排 partition 思路的应用。

 设定两个索引，一个从左往右滑动`zero`，一个从右往左滑动`two`。

 * 遍历`nums`，当`nums[i]`的值为1时，`i++`；
 * 当`nums[i]`的值为2时，`two`的值先减1，而后交换`nums[i]`与`nums[two]`，此时在观察`nums[i]`的值；
 * 当`nums[i]`的值为0时，`zero++`，而后交换`nums[i]`与`nums[zero]`，`i++`;当 `i = two`时，结束循环。
 */
using namespace std;

class Solution {
public:
    void sortColors(vector<int> &nums) {

        int zero = -1;          // [0...zero] == 0
        long two = nums.size();  // [two...n-1] == 2
        for(int i = 0 ; i < two ; ){
            if(nums[i] == 1){
                 i ++;
            }else if (nums[i] == 2){
                 two--;
                 swap( nums[i] , nums[two]);
            }else{ // nums[i] == 0
                 zero++;
                 swap(nums[zero] , nums[i]);
                 i++;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
  int a[10] = {0,1,1,0,2,1,0,1,2};
     sort(a,a+9);
     
     vector<int> b;
     for(int i=0;i< 9;i++){
         b.push_back(a[i]);
     }
     cout<<endl;
    
    Solution solution;
    solution.sortColors(b);
    
    for(int i=0;i< 9;i++){
        cout<< b[i] <<endl;
    }
    return 0;
}
