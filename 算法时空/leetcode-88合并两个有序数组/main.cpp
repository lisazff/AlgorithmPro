//
//  main.cpp
//  leetcode-88合并两个有序数组
//
//  Created by 佐毅 on 2018/3/21.
//  Copyright © 2018年 dfjr. All rights reserved.
//


/*
 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
 
 说明:
 
 
 初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 
 
 示例:
 
 输入:
 nums1 = [1,2,3,0,0,0], m = 3
 nums2 = [2,5,6], n = 3
 
 输出: [1,2,2,3,5,6]
 */

/*
 解题思路：
 
 混合插入有序数组，由于两个数组都是有序的，所有只要按顺序比较大小即可。
 最先想到的方法是建立一个m+n大小的新数组，
 然后逐个从A和B数组中取出元素比较，
 把较小的加入新数组，
 然后在考虑A数组有剩余和B数组有剩余的两种情况，
 最后在把新数组的元素重新赋值到A数组中即可。
 */
#include <iostream>

using namespace std;

class Solution {
public:
    int* merge(int* nums1, int* nums2 ,int m, int n) {
        
        int i = m - 1, j = n - 1, tar = m + n - 1;
        
        while (j >= 0) {
            nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
        return  nums1;
    }
};

int main(int argc, const char * argv[]) {
    
    
    Solution solu;
    
    int A[10] = {1, 2, 3, 4, 5};
    int B[5] = {2, 3, 5, 7, 9};
    int* C = solu.merge(A, B, 5, 5);
    for (int i = 0; i < 10; i++) {
        cout << C[i] << endl;
    }
    
    
    return 0;
}
