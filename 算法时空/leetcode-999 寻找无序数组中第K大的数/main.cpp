//
//  main.cpp
//  leetcode-999 寻找无序数组中第K大的数
//
//  Created by 佐毅 on 2020/2/6.
//  Copyright © 2020 dfjr. All rights reserved.
//

/**
 https://blog.csdn.net/weixin_43930512/article/details/91410153
 
 */

#include <iostream>

using namespace std;

class Solution{
public:
    
    //直接从大到小排序，排好序后，第k大的数就是arr[k-1]。
    int partition(int a[], int i, int j){
        int  temp = a[i];
        if (i < j){
            while (i < j){
                //从后往前扫找比枢轴值小的交换位置
                while (i<j&&a[j] >= temp)  j--;
                if (i < j)  a[i] = a[j];
                while (i < j&&a[i] < temp) i++;
                if (i < j)  a[j] = a[i];
            }
            a[i] = temp;
            return i;
        }
        return -1;
    }
    
    int search(int a[], int i, int j, int k){
        int m = partition(a, i, j);
        if (k==m-i+1)  return a[m];
        else if (k<m-i+1){
            return search(a, i, m-1,k );
        }else{//后半段
            return search(a, m+1, j, k-(m-i+1));
        }
    }
    
    
    /*分治法：
     1.利用快速排序的思想，每一次把数组分成较大和较小的两部分，以第一个元素A为基准，把大于A的元素都交换到数组左边，小于A的元素都交换到数组右边。
     2.判断K与A索引的大小，如果K小于A的索引，那么在A的左边再次利用分治法；反之，在A的右侧利用分治法
     */
    //把大的放在左边，小的放在右边
    int partition(int arr[], int i, int j){
        int temp = arr[i];
        while (i < j){
            while (i<j && temp >= arr[j]){
                j--;
            }
            swap(arr[i], arr[j]);
            while (i<j && temp<=arr[i]){
                i++;
            }
            swap(arr[i], arr[j]);
        }
        return  i;
    }
    
    int findMaxK(int arr[], int k, int start, int end){
        int q = partition(arr, start, end);
        
        if (q>k){
            return findMaxK(arr, k, start, q - 1);
        }
        else if (q<k){
            return findMaxK(arr, k, q + 1, end);
        }
        
        return q;
    }
    
    //小顶堆法
    void adjustHeap(int arr[], int index, int k){
        int min = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        if (left < k && arr[left] < arr[min]){
            min = left;
        }
        if (right <k && arr[right] < arr[min]){
            min = right;
        }
        
        if (min != index){
            swap(arr[min], arr[index]);
            adjustHeap(arr, min, k); //为了使得调整后依旧满足最小堆的特性，需要再次调整
        }
    }
    
    int findTopK(int arr[], int k,int len){
        //从最后一个叶子节点开始调整堆
        for (int i = k / 2 - 1; i >= 0; i--){
            adjustHeap(arr, i, k);
        }
        
        //遍历剩下的元素
        for (int i = k; i < len; i++){
            if (arr[i]>arr[0]){
                swap(arr[0], arr[i]);
                adjustHeap(arr, 0, k);
            }
        }
        return arr[0];
    }
};



int main(int argc, const char * argv[]) {
    int arr[] = { 7, 5, 15, 3, 17, 2, 20, 24, 1, 9, 12, 8 };
    int k = 7;
    int len = sizeof(arr) / sizeof(int);
    
    Solution solution;
    int target = solution.findTopK(arr, k,len);
    
    cout << target<<endl;
    return 0;
}
