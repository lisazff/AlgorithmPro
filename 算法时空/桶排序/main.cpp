//
//  main.cpp
//  桶排序
//
//  Created by 佐毅 on 2018/3/19.
//  Copyright © 2018年 dfjr. All rights reserved.
//

/*
 桶排序(Bucket Sort)的原理很简单，它是将数组分到有限数量的桶子里。
 
 假设待排序的数组a中共有N个整数，并且已知数组a中数据的范围[0, MAX)。在桶排序时，创建容量为MAX的桶数组r，并将桶数组元素都初始化为0；将容量为MAX的桶数组中的每一个单元都看作一个"桶"。
 在排序时，逐个遍历数组a，将数组a的值，作为"桶数组r"的下标。当a中数据被读取时，就将桶的值加1。例如，读取到数组a[3]=5，则将r[5]的值+1。
 
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 数组长度
#define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )

/*
 * 桶排序
 *
 * 参数说明：
 *     a -- 待排序数组
 *     n -- 数组a的长度
 *     max -- 数组a中最大值的范围
 */
void bucket_sort(int a[], int n, int max)
{
    int i, j;
    int *buckets;
    
    if (a==NULL || n<1 || max<1)
        return ;
    
    // 创建一个容量为max的数组buckets，并且将buckets中的所有数据都初始化为0。
    if ((buckets=(int *)malloc(max*sizeof(int)))==NULL)
        return ;
    memset(buckets, 0, max*sizeof(int));
    
    // 1. 计数
    for(i = 0; i < n; i++)
         printf("%d ", a[i]);
        buckets[a[i]]++;
    
    
    
    
    // 2. 排序
    for (i = 0, j = 0; i < max; i++)
        while( (buckets[i]--) >0 )
            a[j++] = i;
    
    free(buckets);
}

int main()
{
    int i;
    int a[] = {8,2,3,4,3,6,6,3,9};
    int ilen = LENGTH(a);
    
    printf("before sort:");
    for (i=0; i<ilen; i++)
        printf("%d ", a[i]);
    printf("\n");
    
    bucket_sort(a, ilen, 10); // 桶排序
    
    printf("after  sort:");
    for (i=0; i<ilen; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
