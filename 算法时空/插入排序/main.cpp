//
//  main.cpp
//  插入排序
//
//  Created by 佐毅 on 2018/3/15.
//  Copyright © 2018年 dfjr. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

/*
 https://images2015.cnblogs.com/blog/973920/201608/973920-20160816094930406-658560183.gif
 
 
 
 1.1 插入排序
 
 直接插入排序(Straight Insertion Sort)的基本思想是：
    把n个待排序的元素看成为一个有序表和一个无序表。开始时有序表中只包含1个元素，无序表中包含有n-1个元素，
    排序过程中每次从无序表中取出第一个元素，将它插入到有序表中的适当位置，使之成为新的有序表，重复n-1次可完成排序过程。

 插入排序是一种简单直观的排序算法，它也是基于比较的排序算法。
 它的工作原理是通过不断扩张有序序列的范围，对于未排序的数据，在已排序中从后向前扫描，找到相应的位置并插入。
 插入排序在实现上通常采用就地排序，因而空间复杂度为O（1）。
 在从后向前扫描的过程中，需要反复把已排序元素逐步向后移动，为新元素提供插入空间，因此插入排序的时间复杂度为O（n^2）;
 
 循环不变式：
 保证左半部分是有序的，
 然后对尚未处理的进行排序，同时保证排序之后是有序的.
 
 排序前：7 1 9 5 2 0 12 6
 
 ：1 7 9 5 2 0 12 6
 ：1 5 7 9 2 0 12 6
 ：1 2 5 7 9 0 12 6
 ：0 1 2 5 7 9 12 6
 ：0 1 2 5 7 9 12 6
 ：0 1 2 5 6 7 9 12
 ：0 1 2 5 6 7 9 12
 
 排序后：0 1 2 5 6 7 9 12
 
 2.2. 复杂度分析
 插入排序的最好情况是数组已经有序，此时只需要进行n-1次比较，时间复杂度为O（n）;
 最坏情况是数组逆序排序，此时需要进行n(n-1)/2次比较以及n-1次赋值操作（插入）；
 平均来说插入排序算法的复杂度为O(n^2)。
 插入排序不适合对大量数据进行排序应用，但排序数量级小于千时插入排序的效率还不错，可以考虑使用。
 插入排序在STL的sort算法和stdlib的qsort算法中，都将插入排序作为快速排序的补充，用于少量元素的排序（通常为8个或以下）。
 
 直接插入排序采用就地排序，空间复杂度为O（1）.
 
 2.3. 稳定性
 
 直接插入排序是稳定的，不会改变相同元素的相对顺序。
 */



/// 写法1
void insertSort_0(int arr[], int length)
{
    int i, j, key;
    for (i = 0; i < length; i++){
        key = arr[i];
        for (j = i - 1; j >= 0; j--){
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
            }
            else
                break;
        }
        arr[j + 1] = key;
    }
}

//// 写法2
void insertSort_1(int arr[], int length)
{
    int j, key;
    for (int i = 1; i < length; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

using namespace std;
template<typename T>
void insertionSort_2(T arr[], int n){
    
    for( int i = 1 ; i < n ; i ++ ) {
        for( int j = i ; j > 0 && arr[j] < arr[j-1] ; j -- )
            swap( arr[j] , arr[j-1] );
    }
}


/*
 上面的插入排序实现中，为了找到元素的合适的插入位置，
 我们采用从后到前遍历的顺序查找进行比较，为了减少比较的次数，
 我们可以换种查找策略：采用二分查找。
 我们定义一个二分查找函数，函数返回插入位置的下标：
 
 3.2. 复杂度分析
 
 我们这个二分查找的算法并不会因为等于某一个值而停止查找，它将查找整个序列直到start<=end条件不满足而得到插入的位置，
 所以对于长度为n的数组来说，比较次数为log2n ,时间复杂度为O（log2n）。
 二分插入排序的主要操作为比较+后移赋值，则：
 
 最坏情况：每次都在有序序列的起始位置插入，则整个有序序列的元素需要后移，时间复杂度为O（n^2）
 最好情况：待排序数组本身就是正序的，每个元素所在位置即为它的插入位置，此时时间复杂度仅为比较时的时间复杂度，为O(log2n)
 平均情况：O（n^2）
 空间复杂度上， 二分插入排序也是就地排序算法，它的空间复杂度为O（1）.
 
 3.3. 稳定性
 
 二分插入排序是稳定的。元素的相对顺序在排序后不会被改变。
 */
template <typename T>
int BinarySearch(T array[], int start, int end, T k)
{
    while (start <= end)
    {
        int middle = (start + end) / 2;
        int middleData = array[middle];
        if (middleData > k)
        {
            end = middle - 1;
        }
        else
            start = middle + 1;
    }
    return start;
}

//二叉查找插入排序
template <typename T>
void InsertSort(T array[], int length)
{
    if (array == nullptr || length < 0)
        return;
    int i, j;
    for (i = 1; i < length; i++)
    {
        if (array[i]<array[i - 1])
        {
            int temp = array[i];
            int insertIndex = BinarySearch(array, 0,i, array[i]);//使用二分查找在有序序列中进行查找，获取插入下标
            for (j = i - 1; j>=insertIndex; j--) //移动元素
            {
                array[j + 1] = array[j];
            }
            array[insertIndex] = temp;    //插入元素
        }
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    

    
    int iArr[] = { 7, 1, 9, 5, 2, 0, 12, 6};
    int len = sizeof iArr / sizeof(iArr[0]);
    
    cout << "排序前：";
    for (int i = 0; i < len; i++)    {
        cout <<  iArr[i] << " ";
    }
    
    cout << "\n排序后：";
    insertSort_1(iArr, len);
    for (int j = 0; j < len; j++)    {
        cout << iArr[j] << " ";
    }
    cout << endl;

    return 0;
}
