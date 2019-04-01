//
//  main.cpp
//  快速排序
//
//  Created by 佐毅 on 2018/3/18.
//  Copyright © 2018年 dfjr. All rights reserved.
//

#include <iostream>
using namespace std;

/*
 * 快速排序
 *
 * 参数说明：
 *     a -- 待排序的数组
 *     l -- 数组的左边界(例如，从起始位置开始排序，则l=0)
 *     r -- 数组的右边界(例如，排序截至到数组末尾，则r=a.length-1)
 */
void quickSort(int* a, int l, int r)
{
    if (l < r)
    {
        int i,j,x;
        
        i = l;
        j = r;
        x = a[i];
        while (i < j)
        {
            while(i < j && a[j] > x)
                j--; // 从右向左找第一个小于x的数
            if(i < j)
                a[i++] = a[j];
            while(i < j && a[i] < x)
                i++; // 从左向右找第一个大于x的数
            if(i < j)
                a[j--] = a[i];
        }
        a[i] = x;
        quickSort(a, l, i-1); /* 递归调用 */
        quickSort(a, i+1, r); /* 递归调用 */
    }
}


int partition(int arr[], int left, int right)  //找基准数 划分
{
    int i = left + 1 ;
    int j = right;
    int temp = arr[left];
    
    while(i <= j)
    {
        while (arr[i] < temp)
        {
            i++;
        }
        while (arr[j] > temp )
        {
            j--;
        }
        if (i < j)
            swap(arr[i++], arr[j--]);
        else i++;
    }
    swap(arr[j], arr[left]);
    return j;
    
}

void quick_sort(int arr[], int left, int right)
{
    if (left > right)
        return;
    int j = partition(arr, left, right);
    quick_sort(arr, left, j - 1);
    quick_sort(arr, j + 1, right);
}

int main()
{
    int i;
    int a[] = {30,40,60,10,20,50};
    int ilen = (sizeof(a)) / (sizeof(a[0]));
    
    cout << "before sort:";
    for (i=0; i<ilen; i++)
        cout << a[i] << " ";
    cout << endl;
    
//    quickSort(a, 0, ilen-1);
    
    quick_sort(a, 0, ilen-1);
    
    cout << "after  sort:";
    for (i=0; i<ilen; i++)
        cout << a[i] << " ";
    cout << endl;
    
    return 0;
}
