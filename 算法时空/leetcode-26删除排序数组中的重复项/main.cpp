//
//  main.cpp
//  leetcode-26删除排序数组中的重复项
//
//  Created by 佐毅 on 2018/3/20.
//  Copyright © 2018年 dfjr. All rights reserved.
//

/*
 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
 
 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
 
 示例 1:
 
 给定数组 nums = [1,1,2],
 
 函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。
 
 你不需要考虑数组中超出新长度后面的元素。
 
 示例 2:
 
 给定 nums = [0,0,1,1,1,2,2,3,3,4],
 
 函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
 
 你不需要考虑数组中超出新长度后面的元素。
 
 
 说明:
 
 为什么返回数值是整数，但输出的答案是数组呢?
 
 请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int i = !nums.empty();
    cout<<endl;
    for (int n : nums){
        if (n > nums[i-1]){
            nums[i++] = n;
        }
    }
    return i;
}

class Solution {
public:
    long removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        long pre = 0, cur = 0, n = nums.size();
        while (cur < n) {
            if (nums[pre] == nums[cur]){
              cur++;
            } else{
                ++pre;
                nums[pre] = nums[cur];
                cur++;
            }
        }
        return pre + 1;
    }
};

void print( vector<int> vector1){
    for(int i=0 ;i<vector1.size();i++)
        cout<<vector1[i]<<" ";
    
    cout<<endl;
}

int main(int argc, const char * argv[]) {
    int a[10] = {1,1,1,3,3,4,3,2,4,2};
    sort(a,a+10);
    
    vector<int> b;
    for(int i=0;i< 10;i++){
        b.push_back(a[i]);
    }
    cout<<endl;
        
    cout<< removeDuplicates(b)  <<" ";
    cout<<endl;
    
    return 0;
}
