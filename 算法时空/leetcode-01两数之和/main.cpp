//
//  main.cpp
//  leetcode-01两数之和
//
//  Created by 佐毅 on 2018/3/19.
//  Copyright © 2018年 dfjr. All rights reserved.
//


/*
 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 
 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
 
 示例:
 
 给定 nums = [2, 7, 11, 15], target = 9
 
 因为 nums[0] + nums[1] = 2 + 7 = 9
 所以返回 [0, 1]
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        vector<int> result;
        size_t size = nums.size();
        if (size < 2){
            return result;
        }
        
        for (int i = 0; i < size; ++i){
            for (int j = i + 1; j < size; ++j){
                if ((nums[i] + nums[j]) == target){
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        
        return result;
    }
    
    vector<int> twoSums(vector<int>& nums, int target) {
        unordered_map<int,int> record;
        vector<int> result;
        for(int i = 0 ; i < nums.size() ; i ++){
            int complement = target - nums[i];
            if(record.find(complement) != record.end()){
                int res[] = {i, record[complement]};
                return vector<int>(res, res + 2);
            }
            
            record[nums[i]] = i;
        }
        return result;
    }
    
    
    
    vector<int> twoNumWithMap(vector<int> &numbers,int target){
        unordered_map<int, int> m;
        vector<int> result;
        for(int i=0; i<numbers.size(); i++){
            // not found the second one
            
            if (m.find(numbers[i])==m.end() ) {
                 std::cout <<numbers[i] << "\n";
                  cout << endl;
                // store the first one poisition into the second one's key
                m[target - numbers[i]] = i;
            }else {
                // found the second one
                result.push_back(m[numbers[i]]);
                result.push_back(i);
                break;
            }
        }
        
     
        for (const auto& n : m) {
            std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
        }
        
        return result;
    };

};


int main()
{
    
    Solution sol;
    std::vector<int> result;
    std::vector<int> result1;
    std::vector<int> nums;
    
  
    
    nums.push_back(2);
    nums.push_back(11);
    nums.push_back(7);
    nums.push_back(15);
    
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << endl;
    }
    
     cout << endl;
//    result = sol.twoSum(nums, 19);
    result = sol.twoSums(nums, 9);
    result1 = sol.twoNumWithMap(nums, 26);
    //result = sol.twoSum(nums, 19);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
      cout << endl;
    
    for (int i = 0; i < result1.size(); i++)
    {
        cout << result1[i] << endl;
    }

     cout << endl;
    
    
    int a[6]={1,2,3,4,5,6};
    vector<int> b(a,a+4);
    for(int i=0;i<=b.size()-1;i++)
        cout<<b[i]<<" ";
    
    return 0;
}
