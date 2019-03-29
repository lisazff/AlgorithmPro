//
//  main.cpp
//  归并排序
//
//  Created by 佐毅 on 2018/3/19.
//  Copyright © 2018年 dfjr. All rights reserved.
//

#include <iostream>

/*
 将两个的有序数列合并成一个有序数列，我们称之为"归并"。
 归并排序(Merge Sort)就是利用归并思想对数列进行排序。根据具体的实现，归并排序包括"从上往下"和"从下往上"2种方式。
 
 1. 从下往上的归并排序：将待排序的数列分成若干个长度为1的子数列，然后将这些数列两两合并；得到若干个长度为2的有序数列，再将这些数列两两合并；得到若干个长度为4的有序数列，再将它们两两合并；直接合并成一个数列为止。这样就得到了我们想要的排序结果。(参考下面的图片)
 
 2. 从上往下的归并排序：它与"从下往上"在排序上是反方向的。它基本包括3步：
 ① 分解 -- 将当前区间一分为二，即求分裂点 mid = (low + high)/2;
 ② 求解 -- 递归地对两个子区间a[low...mid] 和 a[mid+1...high]进行归并排序。递归的终结条件是子区间长度为1。
 ③ 合并 -- 将已排序的两个子区间a[low...mid]和 a[mid+1...high]归并为一个有序的区间a[low...high]。
 */

#include <stdio.h>
#include <stdlib.h>

// 数组长度
#define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )

/*
 * 将一个数组中的两个相邻有序区间合并成一个
 *
 * 参数说明：
 *     a -- 包含两个有序区间的数组
 *     start -- 第1个有序区间的起始地址。
 *     mid   -- 第1个有序区间的结束地址。也是第2个有序区间的起始地址。
 *     end   -- 第2个有序区间的结束地址。
 */
void merge(int a[], int start, int mid, int end)
{
    int *tmp = (int *)malloc((end-start+1)*sizeof(int));    // tmp是汇总2个有序区的临时区域
    int i = start;            // 第1个有序区的索引
    int j = mid + 1;        // 第2个有序区的索引
    int k = 0;                // 临时区域的索引
    
    while(i <= mid && j <= end)
    {
        if (a[i] <= a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }
    
    while(i <= mid)
        tmp[k++] = a[i++];
    
    while(j <= end)
        tmp[k++] = a[j++];
    
    // 将排序后的元素，全部都整合到数组a中。
    for (i = 0; i < k; i++)
        a[start + i] = tmp[i];
    
    free(tmp);
}

/*
 * 归并排序(从上往下)
 *
 * 参数说明：
 *     a -- 待排序的数组
 *     start -- 数组的起始地址
 *     endi -- 数组的结束地址
 */
void merge_sort_up2down(int a[], int start, int end)
{
    if(a==NULL || start >= end)
        return ;
    
    int mid = (end + start)/2;
    merge_sort_up2down(a, start, mid); // 递归排序a[start...mid]
    merge_sort_up2down(a, mid+1, end); // 递归排序a[mid+1...end]
    
    // a[start...mid] 和 a[mid...end]是两个有序空间，
    // 将它们排序成一个有序空间a[start...end]
    merge(a, start, mid, end);
}


/*
 * 对数组a做若干次合并：数组a的总长度为len，将它分为若干个长度为gap的子数组；
 *             将"每2个相邻的子数组" 进行合并排序。
 *
 * 参数说明：
 *     a -- 待排序的数组
 *     len -- 数组的长度
 *     gap -- 子数组的长度
 */
void merge_groups(int a[], int len, int gap)
{
    int i;
    int twolen = 2 * gap;    // 两个相邻的子数组的长度
    
    // 将"每2个相邻的子数组" 进行合并排序。
    for(i = 0; i+2*gap-1 < len; i+=(2*gap))
    {
        merge(a, i, i+gap-1, i+2*gap-1);
    }
    
    // 若 i+gap-1 < len-1，则剩余一个子数组没有配对。
    // 将该子数组合并到已排序的数组中。
    if ( i+gap-1 < len-1)
    {
        merge(a, i, i + gap - 1, len - 1);
    }
}

/*
 * 归并排序(从下往上)
 *
 * 参数说明：
 *     a -- 待排序的数组
 *     len -- 数组的长度
 */
void merge_sort_down2up(int a[], int len)
{
    int n;
    
    if (a==NULL || len<=0)
        return ;
    
    for(n = 1; n < len; n*=2)
        merge_groups(a, len, n);
}

void main()
{
    int i;
    int a[] = {80,30,60,40,20,10,50,70};
    int ilen = LENGTH(a);
    
    printf("before sort:");
    for (i=0; i<ilen; i++)
        printf("%d ", a[i]);
    printf("\n");
    
    merge_sort_up2down(a, 0, ilen-1);        // 归并排序(从上往下)
    //merge_sort_down2up(a, ilen);            // 归并排序(从下往上)
    
    printf("after  sort:");
    for (i=0; i<ilen; i++)
        printf("%d ", a[i]);
    printf("\n");
}
