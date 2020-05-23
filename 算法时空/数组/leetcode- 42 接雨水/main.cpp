//
//  main.cpp
//  leetcode- 42 接雨水
//
//  Created by 佐毅 on 2020/5/23.
//  Copyright © 2020 dfjr. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//https://leetcode-cn.com/problems/trapping-rain-water/solution/dan-diao-zhan-jie-jue-jie-yu-shui-wen-ti-by-sweeti/
class Solution {
public:
    int trap(vector<int>& height) {
        int ret = 0;
        stack<int> s;
        for (int i = 0; i < height.size(); i ++) {
            while (!s.empty() && height[i] > height[s.top()]) {
                int cur = height[s.top()];
                s.pop();
                int l = s.empty() ? -1 : s.top();
                ret += l == -1 ? 0 : (min(height[l], height[i]) - cur) * (i - l - 1);
            }
            s.push(i);
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    int a[7] = {1,3,4,6,9,10,12};
    
    vector<int> b;
    for(int i=0;i< 7;i++){
        b.push_back(a[i]);
    }
    cout<<endl;
    
    cout<< sol.trap(b) <<endl;
    return 0;
}
