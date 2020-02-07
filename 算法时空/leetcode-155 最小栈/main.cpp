//
//  main.cpp
//  leetcode-155 最小栈
//
//  Created by 佐毅 on 2020/2/7.
//  Copyright © 2020 dfjr. All rights reserved.
//

/**
 最小栈
 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

 push(x) -- 将元素 x 推入栈中。
 pop() -- 删除栈顶的元素。
 top() -- 获取栈顶元素。
 getMin() -- 检索栈中的最小元素。
 */

#include <iostream>
#include <stack>

using namespace std;
class MinStack {
public:
    stack<int> s;//数据栈
    stack<int> min;//辅助栈
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if(min.empty()||x<=min.top())
        {
            min.push(x);
        }
    }
    
    void pop() {
        if(s.top()==min.top())
            min.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    int getMin() {
        return min.top();
    }
};


int main(int argc, const char * argv[]) {
    
    MinStack minStack ;
    
    minStack.push(2);
    minStack.push(1);
    minStack.push(5);
    minStack.push(4);
    minStack.push(0);
    
    cout<< minStack.getMin() <<endl;
    return 0;
}
