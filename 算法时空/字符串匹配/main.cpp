//
//  main.cpp
//  字符串匹配
//
//  Created by 佐毅 on 2019/12/13.
//  Copyright © 2019年 dfjr. All rights reserved.
//

/*---------------------------------------------
 *   日期：2015-02-14
 *   作者：SJF0115
 *   题目: 字符串匹配
 *   来源：腾讯
 *   博客：
 -----------------------------------------------*/
#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    bool StrMatch(string str1,string str2){
        unsigned int size1 = str1.size();
        unsigned int size2 = str2.size();
        
        if(size1 <= 0 || size2 <= 0 || size1 != size2){
            return false;
        }//if
        
        int count[256];
        // 初始化
        memset(count,0,sizeof(count));
        // 前者加
        for(int i = 0;i < size1;++i){
            ++count[str1[i]];
        }//for
        //后者减
        for(int i = 0;i < size2;++i){
            --count[str2[i]];
        }//for
        // 全部为0则匹配
        for(int i = 0;i < 256;++i){
            if(count[i] != 0){
                return false;
            }//if
        }//for
        return true;
    }
    void naiveSearch(const char* T,const char* P)
    {
        int n = strlen(T);
        int m = strlen(P);
        for (int s = 0; s < n - m+1; ++s)
        {
            int i = s, j = 0;
            for (;j < m-1;)
            {
                if (T[i] == P[j]) ++i, ++j;
                else break;
            }
            if (T[i] == P[j])
                printf("%d\n",s);
        }
    }
};


int main(int argc, const char * argv[]) {
    Solution solution;
    string str1("bilibili");
    string str2("bbiliili");
    
//    char *str11 = "bilibili";
//    char *str12 = "bbiliili";
    cout<<solution.StrMatch(str1,str2)<<endl;
//    solution.naiveSearch(str11, str12);
    
    return 0;
}
