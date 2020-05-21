//
//  main.cpp
//  leetcode-04 三数之和
//
//  Created by 佐毅 on 2020/2/1.
//  Copyright © 2020 dfjr. All rights reserved.
//

/**
 ### 题目描述

 给定一个包含 *n* 个整数的数组 `nums`，判断 `nums` 中是否存在三个元素 *a，b，c ，*使得 *a + b + c =* 0 ？找出所有满足条件且不重复的三元组。
 */

/**
 ### 题目解析
 
 题目需要我们找出三个数且和为 0 ，那么除了三个数全是 0 的情况之外，肯定会有负数和正数，所以一开始可以先选择一个数，然后再去找另外两个数，这样只要找到两个数且和为第一个选择的数的相反数就行了。也就是说需要枚举 a 和 b ，将 c 的存入 map 即可。

 需要注意的是返回的结果中，不能有有重复的结果。这样的代码时间复杂度是 O(n^2)。在这里可以先将原数组进行排序，然后再遍历排序后的数组，这样就可以使用双指针以线性时间复杂度来遍历所有满足题意的两个数组合。

 */

/**
 这道题和之前做过的twosum有点相似，只不过从twosum变成了threesum。回顾之前做twosum的做法，排序号数组后，我使用双指针头尾遍历数组，找到target值。但很显然我们没办法直接应用这个解法。需要一点变通。

 什么变通呢？其实我们只要先把数组排序好，然后先固定一个值，之后把target取这个值的相反数，就能用双指针来找到我们需要的target值了，就变成和twosum一样了。

 固定一个值的时候，我们可以做个剪枝优化，有以下几种情况需要优化。

 遍历到正数直接break，因为数字已经是有序的了，如果第一个要固定的数是正的话，那之后的数字也必然是正的，无需考虑。其次，如果在前几个固定的数中已经使用到后面为正数的数了，我们也不需要把这些正数作为固定的数，因为这些数在之前的解使用过了。

 从第二个数起，如果和前面的数字相等，就跳过。我们不想把相同数字固定两次。
 */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() < 3) return res;
        sort(nums.begin(),nums.end());//先排序
        for(vector<int>::iterator it = nums.begin(); it != nums.end()-2;){
            int tmp = *it;
            if(tmp > 0) break;
            int target = 0 - tmp;
            vector<int>::iterator left = it+1;
            vector<int>::iterator right = nums.end()-1;
            while(left < right){
                if(*right < 0) break;//如果右边小于0，break
                if(*left + *right < target){
                    int v= *left;
                    while(left != right && *left == v) left++; //跳过相等的元素
                }else if(*left + *right > target){
                    int v= *right;
                    while(left != right && *right == v) right --;//跳过相等的元素
                }else{
                    vector<int> tmp_res{tmp,*left,*right};//保存结果
                    res.push_back(tmp_res);
                    int v= *left;
                    while(left != right &&  *left == v) left++;//跳过相等的元素
                    v= *right;
                    while(left != right &&  *right == v) right --;//跳过相等的元素
                }
            }
            while(it != nums.end()-2 && *it == tmp) it++;//跳过相等的元素
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
     //从数组中获得初值
    int b[7]={1,2,3,4,5,6,7};
    vector<int> a(b,b+7);
    std::vector<vector<int>> result;
    result = solution.threeSum(a);
    cout << endl;
    std::cout << "Hello, World!\n";
    return 0;
}
