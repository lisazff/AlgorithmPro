//
//  main.cpp
//  leetcode-260 只出现一次的数字 III
//
//  Created by 佐毅 on 2020/2/3.
//  Copyright © 2020 dfjr. All rights reserved.
//
/**
 给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。

 示例 :
 输入: [1,2,1,3,2,5]
 输出: [3,5]
 注意：

 结果输出的顺序并不重要，对于上面的例子， [5, 3] 也是正确答案。
 你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？
 */
#include <iostream>
#include <vector>


class Solution {
public:
     int[] SingleNumber(int[] nums){
        int sign = 0;
        //取得数组中两个唯一数的按位异或结果
        for (int i = 0; i < nums.Length; i++){
            sign ^= nums[i];
        }
        //获取区分两个唯一数的比特位所代表的值
        //也可以写成：sign &= (~sign) + 1
        sign &= -sign;
        int[] result  = new int[2];
        //通过标识，区分两个数组
        for (int i = 0; i < nums.Length; i++){
            if ((nums[i] & sign) == sign)
                result[0] ^= nums[i];
            else
                result[1] ^= nums[i]; ;
        }
        return result;
    }
};


int main(int argc, const char * argv[]) {
    
    vector<int > temp;
    temp.push_back(1);
    temp.push_back(1);
    temp.push_back(1);
    temp.push_back(2);
    temp.push_back(3);
        
    Solution solution;
    
    std::cout << solution.singleNumber(temp);
    return 0;
}
