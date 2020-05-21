//
//  main.m
//  Fibonacci （斐波那契数列实现）
//
//  Created by 佐毅 on 2019/12/5.
//  Copyright © 2019年 dfjr. All rights reserved.
//


/*
 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 
 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 
 注意：给定 n 是一个正整数。
 
 示例 1：
 输入： 2
 输出： 2
 解释： 有两种方法可以爬到楼顶。
 
 1 阶 + 1 阶
 2 阶
 示例 2：
 输入： 3
 输出： 3
 解释： 有三种方法可以爬到楼顶。
 
 1 阶 + 1 阶 + 1 阶
 1 阶 + 2 阶
 2 阶 + 1 阶
 示例 3：
 输入： 4
 输出： 5
 解释： 有五种方法可以爬到楼顶。
 
 1 阶 + 1 阶 + 1 阶+ 1 阶
 1 阶 + 1 阶 + 2 阶
 1 阶 + 2 阶 + 1 阶
 2 阶 + 1 阶 + 1 阶
 2 阶 + 2 阶
 
 很明显，这是一个斐波那契数列，即a[n] = a[n-2] + a[n-1]。n的结果都是由前两个值相加得到的。
 */

#include <iostream>
using namespace std;

long long Fibonacci(unsigned n){
    
    int result[2] = {0, 1};
    
    if(n < 2){
        return result[n];
    }
    
    long long  fibNMinusOne = 0;
    long long  fibNMinusTwo = 1;
    
    long long  fibN = 0;
    
    for(unsigned int i = 0; i < n; i++){
        
        fibN = fibNMinusOne + fibNMinusTwo;
        fibNMinusOne = fibNMinusTwo;
        fibNMinusTwo = fibN;
    }
    
    return fibN;
}

int main(){
    
    cout << Fibonacci(4) << " ";
    return 0;
}
