//
//  main.cpp
//  leetcode- 59 滑动窗口最大值
//
//  Created by 佐毅 on 2020/5/21.
//  Copyright © 2020 dfjr. All rights reserved.
//

/**
 
 提示：
 
 你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。
 
 给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。
 
 示例:
 
 输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
 输出: [3,3,5,5,6,7]
 解释:
 
 滑动窗口的位置                最大值
 ---------------               -----
 [1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof
 */
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size() == 0) return {};
        vector<int> ans;
        for(int i = 0; i <= nums.size() - k; i ++){
            int maxNum = nums[i];
            for(int j = i; j < i + k; j ++){
                maxNum = max(maxNum, nums[j]);
            }
            ans.push_back(maxNum);
        }
        return ans;
    }
    
    /**
     为了降低时间复杂度，我们观察一下窗口移动的过程类似于队列出队入队的过程，每次队尾出一个元素，然后队头插入一个元素，求该队列中的最大值，这个和 包含min函数的栈 有点类似，我们可以维护一个递减队列，队列用来保存可能是最大值的数字的index。当前窗口最大值的index在队首，当窗口滑动时，会进入一个新值，出去一个旧值，我们需要给出当前窗口的最大值。
     
     需要先检查队首（上一窗口的最大值）的index是否还在当前窗口内，如果不在的话需要淘汰。
     然后新进入的值要和队尾元素做比较，如果比队尾元素大，那么队尾元素出队（用到双端队列特性的地方），直到队列为空或者前面的值不比他小为止。
     */
    
    vector<int> maxSlidingWindows(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> deq;
        long n = nums.size();
        for (int i = 0; i < n; i++){
            //新元素入队时如果比队尾元素大的话就替代队尾元素
            while(!deq.empty() && nums[i] > nums[deq.back()]){
                deq.pop_back();
            }
            //检查队首的index是否在窗口内，不在的话需要出队
            if (!deq.empty() && deq.front() < i - k + 1) deq.pop_front();
            deq.push_back(i);
            if (i >= k -1) ans.push_back(nums[deq.front()]);
        }
        return ans;
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
    vector<int> results;
    results = solution.maxSlidingWindow(nums,3);
    for (int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }
    return 0;
}
