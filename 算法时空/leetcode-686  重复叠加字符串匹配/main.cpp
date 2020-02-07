//
//  main.cpp
//  leetcode-686  重复叠加字符串匹配
//
//  Created by 佐毅 on 2020/2/7.
//  Copyright © 2020 dfjr. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        
        int la=A.size(),lb=B.size();
        int len=0,k=0,f,LEN;
        string tmp=""; //存储拼接后的A
        for(int i=1;i<=lb/la+(lb%la!=0);i++){
            tmp+=A;
            k++;
            len+=la;
        }
        //将tmp拼接成满足 len>=lb 且 k 最小的情况
        LEN=len+la;     //最多再拼接一次A就可以了， 之后再多拼接就已经重复了，无意义，此时找不到说明B不可能出现了
        while(len<=LEN){
            f=tmp.find(B,0);
            if(f>=0)  //tmp中找到B，返回k次
                return k;
            tmp+=A;
            k++;
            len+=la;
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
   
    string a = "abcd";
    string b = "cdabcdab";
    
    Solution solution;
    
    cout << solution.repeatedStringMatch(a, b) << endl;
    return 0;
}
