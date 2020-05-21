//
//  main.cpp
//  leetcode- 739 每日温度
//
//  Created by 佐毅 on 2020/5/21.
//  Copyright © 2020 dfjr. All rights reserved.
//

/**
 根据每日 气温 列表，请重新生成一个列表，对应位置的输出是需要再等待多久温度才会升高超过该日的天数。如果之后都不会升高，请在该位置用 0 来代替。
 
 例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，
 
 你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。
 
 提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/daily-temperatures
 */


#include <iostream>
#include <vector>

using namespace std;
//https://leetcode-cn.com/problems/daily-temperatures/solution/leetcode-tu-jie-739mei-ri-wen-du-by-misterbooo/
class Solution {
public:
    /**
     * 根据题意，从最后一天推到第一天，这样会简单很多。因为最后一天显然不会再有升高的可能，结果直接为0。
     * 再看倒数第二天的温度，如果比倒数第一天低，那么答案显然为1，如果比倒数第一天高，又因为倒数第一天
     * 对应的结果为0，即表示之后不会再升高，所以倒数第二天的结果也应该为0。
     * 自此我们容易观察出规律，要求出第i天对应的结果，只需要知道第i+1天对应的结果就可以：
     * - 若T[i] < T[i+1]，那么res[i]=1；
     * - 若T[i] > T[i+1]
     *   - res[i+1]=0，那么res[i]=0;
     *   - res[i+1]!=0，那就比较T[i]和T[i+1+res[i+1]]（即将第i天的温度与比第i+1天大的那天的温度进行比较）
     */
    
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> st;
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                auto t = st.top(); st.pop();
                res[t] = i - t;
            }
            st.push(i);
        }
        return res;
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
    results = solution.dailyTemperatures(nums);
    for (int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }
    return 0;
}
