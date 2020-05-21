//
//  main.cpp
//  leetcode-27移除元素
//
//  Created by 佐毅 on 2018/3/20.
//  Copyright © 2018年 dfjr. All rights reserved.
//


/*
 给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
 
 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
 
 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
 
 示例 1:
 
 给定 nums = [3,2,2,3], val = 3,
 
 函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
 
 你不需要考虑数组中超出新长度后面的元素。
 
 
 示例 2:
 
 给定 nums = [0,1,2,2,3,0,4,2], val = 2,
 
 函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
 
 注意这五个元素可为任意顺序。
 
 你不需要考虑数组中超出新长度后面的元素。
 
 
 说明:
 
 为什么返回数值是整数，但输出的答案是数组呢?
 
 请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。
 */



#include <iostream>
#include <vector>

using namespace std;


void print( vector<int> vector1){
    for(int i=0 ;i<vector1.size();i++)
        cout<<vector1[i]<<" ";
    
    cout<<endl;
}

int removeElement(vector<int>& nums, int val) {
    int idx=0;
    for(int i=0;i<nums.size();i++) {
        if(nums[i]!=val) {
            nums[idx] = nums[i];
            idx ++;
        }
    }
    return idx;
}

int main(int argc, const char * argv[]) {
    int a[10] = {1,1,1,3,3,4,3,2,4,2};
    sort(a,a+10);
    
    vector<int> b;
    for(int i=0;i< 10;i++){
        b.push_back(a[i]);
    }
    cout<<endl;

    cout << removeElement(b ,4) << endl;
    return 0;
}
