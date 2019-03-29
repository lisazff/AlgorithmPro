//
//  main.cpp
//  选择排序
//
//  Created by 佐毅 on 2018/3/15.
//  Copyright © 2018年 dfjr. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

/*排序思想：
 每一次从无序组的数据元素中选出最小（或最大）的一个元素，存放在无序组的起始位置，无序组元素
 减少，有序组元素增加，直到全部待排序的数据元素排完。

 */

void selectionSort(int arr[], int n){
    for(int i = 0 ; i < n ; i ++){
        // 寻找[i, n)区间里的最小值
        int minIndex = i;
        for( int j = i + 1 ; j < n ; j ++ ){
            if( arr[j] < arr[minIndex] ){
                minIndex = j;
                swap( arr[i] , arr[minIndex] );
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    selectionSort(a,10);
    for( int i = 0 ; i < 10 ; i ++ )
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
