//
//  main.cpp
//  leetcode-53最大子序和
//
//  Created by 佐毅 on 2018/3/20.
//  Copyright © 2018年 dfjr. All rights reserved.
//


/*
 
 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 
 示例:
 
 输入: [-2,1,-3,4,-1,2,1,-5,4],
 输出: 6
 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
 
 进阶:
 
 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 */

#include <iostream>
#include <vector>

using namespace std;

//它只对数据进行一次扫描，一旦A[i]被读入处理，它就不再需要被记忆。因此，如果数组在磁盘或者磁带上，它就可以被顺序读入，在主存中不必储存数组的任何部分。不仅如此，在任意时刻，算法都能对它已经读入的数据给出子序列问题的正确答案
int MaxSubsequenceSum(int a[],int N){
    
    int tempSum,maxSum,j;
    
    int l = 0;
    
    tempSum=maxSum=0;
    
    for(j=0;j<N;j++){
        tempSum+=a[j];
        if(tempSum>maxSum){
            maxSum=tempSum;
        }else if(tempSum<0){
            tempSum=0;
        }
    }
    
    if(l == N){
        return 0;
    }
    else{
        return maxSum;
    }
}

int main(int argc, const char * argv[]) {
    
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    int ilen = (sizeof(a)) / (sizeof(a[0]));
    
    cout << MaxSubsequenceSum(a, ilen) << endl;
    return 0;
}
