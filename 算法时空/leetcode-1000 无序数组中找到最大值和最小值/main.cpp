//
//  main.cpp
//  leetcode-1000 无序数组中找到最大值和最小值
//
//  Created by 佐毅 on 2020/2/6.
//  Copyright © 2020 dfjr. All rights reserved.
//

/**
 在一个又N个数的无序数组中，最少需要比较多少次可以求出这个数组的最大值和最小值？
 
 此题在《编程之美》上有，并且LZ最近在面百度的时候也被问到了类似的题目，微软面试好像也考到了这题。
 
 那么我们来分析，如果实在一个没有重复元素出现的数组中，我们发现一般情况下，最大的和最小的一般不是同一个，所以有好几种方法来求。
 
 第一种：整个数组扫两遍，那么时间复杂度为O(2*N)。肯定不行。
 
 第二种：用分而治之的方法，先让相邻的两个数进行比较，并将大的数放在偶数位置上，将小的数放在奇数位置上，那么就需要N/2次，然后再从奇偶位置上求出最大最小值，这样就还需要比较N/2，所以我们可以发现一共需要1.5N次比较。
 
 第三种，也是用分而治之的思想，但是比较次数并没有减少，先将所有数分成两部分，分别对前一部分和后一部分分别求最大、最小值，最后再做一次比较。但是这样的比较次数并不会少，也是N/2次。
 
 这题可以引申为另一种类型，赛马问题。
 
 首先有25匹马，但是一共只有5条跑道，也就是每次只能有5匹马同时进行赛马比赛，那么最少需要比赛几次才能比出所有25匹马中的最快的3匹马？
 
 分析：首先我们将所有25匹马分成5批次，每一个批次都有5匹马，那么这样就需要比5次，可以决出每一组中的最快的那一匹马，然后再对5个组中的第一名再进行一次赛马比赛，也就是再比一次，那么可以决出前三名来，那么这次比赛的后两名肯定没戏了，连同这两匹马所在那两组里的所有马都是没有希望了，因为这两匹马已经是这两组里跑得最快的了，所以现在我们只需要考虑前三名的马匹即可。那么我们现在可以确定第一名一定是所有马中跑得最快的那一匹马，但是题目需要求前三名，所以我们还需要比。那么我们接下来需要拿第一名所在那一组中的第二名和第三名，然后是第二名以及它所在的那组的第二名，第三名进行加赛一场，正好是5匹马，也就是需要7场，那么这样比下来是一定可以确定前三名来的。这道题主要考的是逻辑。
 
 1、首先5个跑道同时进行比赛，这样就是跑了5次，我们可以分别得到每个跑道的第一名：A1，B1，C1，D1，E1。

 2、再将5个跑道的第一名放到一个跑道进行比赛，这样我们就可以得到第一名了A1。 输入图片说明

 3、此时总共跑了6次，我们已经知道第一名A1，但第二、三名还不知道。

 4、第6次比赛我们得知A1>B1>C1>D1>E1,很明显D和E组被淘汰了，现在还剩下A2、A3、B1、B2、C1这5个争第二、三名。

 5、将A2、A3、B1、B2、C1进行比赛，得到A2>A3>B1>B2>C1,这样我们就知道第二、三名就是A2和A3了，此时总共比赛了7次，这是最理想的次数。
 */


#include <iostream>
#include <vector>

using namespace std;

template <class T>
int getArrayLen(T&array){
    return sizeof(array) / sizeof(array[0]);
}

class Solution{
public:
    bool GetMaxAndMin(int *arr, int len, int& Max, int& Min){
        // 参数检验
        if(arr == nullptr || len <= 0){
            return false;
        }
        
        if(len <= 1){
            Max = Min = arr[len-1];
            return true;
        }
        
        //Max和Min初始化
        Max = arr[0] > arr[1] ? arr[0] : arr[1];
        Min = arr[0] > arr[1] ? arr[1] : arr[0];
        
        int i;
        int n;
        
        //判断数组长度为奇数还是偶数
        if(len % 2)
            n = len - 1;
        else
            n = len;
        
        for(i=2; i<n; i+=2){
            if(arr[i] > arr[i+1]){
                Max = Max > arr[i] ? Max : arr[i];
                Min = Min > arr[i + 1] ? arr[i + 1] : Min;
            }else{
                Max = Max > arr[i + 1] ? Max : arr[i + 1];
                Min = Min > arr[i] ? arr[i] : Min;
            }
        }
        
        /*如果length为奇数，则剩下最后一个元素没有做过比较*/
        if(i < len){
            Max = Max > arr[i] ? Max : arr[i];
            Min = Min > arr[i] ? arr[i] : Min;
        }
        
        return true;
    }
};

int main(int argc, const char * argv[]) {
    
    int a[] = {8,11,5,2,1,15,22};
    
    Solution b;
    
    int Max = 0;
    int Min = 0;
    
    if(b.GetMaxAndMin(a, getArrayLen(a), Max, Min)){
        cout << "Max : " << Max <<  endl;
        cout << "Min : " << Min <<  endl;
    }
    
    return 0;
    
}
