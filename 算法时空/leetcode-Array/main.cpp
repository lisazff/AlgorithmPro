//
//  main.cpp
//  leetcode-Array
//
//  Created by 佐毅 on 2020/2/7.
//  Copyright © 2020 dfjr. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdio.h>
#include <unordered_map>


/**
 1、移除数组中包含 K 的元素，并返回数组的长度
 
 譬如数组为1，2，2，3，2，4，我们需要删除2，首先初始 化i和j为0，指向第一个位置，因为第一个元素为1，所以A[0] = A[0]，i和j都加1，而 第二个元素为2，我们递增i，直到碰到3，此时A[1] = A[3]，也就是3，递增i和j，这 时候下一个元素又是2，递增i，直到碰到4，此时A[2] = A[5]，也就是4，再次递增i 和j，这时候数组已经遍历完毕，结束。这时候j的值为3，刚好就是新的数组的长 度。
 
 2、一个排序好的数组里面删除 重复的元素。 For example, Given input array A = [1,1,2],Your function should return length = 2, and A is now [1,2].
 首先我们需要知道，对于一个排好序的数组来说， A[N + 1] >= A[N] ，我们仍 然使用两个游标i和j来处理，假设现在i = j + 1，如果A[i] == A[j]，那么我们递增i， 直到A[i] != A[j]，这时候我们再设置A[j + 1] = A[i]，同时递增i和j，重复上述过程直 到遍历结束。
 
 3、同样是移除重复的元素，但是可以允许最多两次重复元素存在。 For example, Given sorted array A = [1,1,1,2,2,3],Your function should return length = 5, and A is now [1,1,2,2,3].
 仍然是第一题的思路，但是我们需要用一个计数器来记录重复的次数，如果重复次 数大于等于2，我们会按照第一题的方式处理，如果不是重复元素了，我们将计数 器清零。
 
 4、加1
 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 你可以假设除了整数 0 之外，这个整数不会以零开头。
 
 示例 1:
 
 输入: [1,2,3]
 输出: [1,2,4]
 解释: 输入数组表示数字 123。
 
 5、帕斯卡三角
 Given numRows, generate the first numRows of Pascal's triangle. For example, given numRows = 5, Return
 [
 [1],
 [1,1],
 [1,2,1],
 [1,3,3,1],
 [1,4,6,4,1]
 ]
 要得到一个帕斯卡三角，我们只需要找到规律即可。
 1、第k层有k个元素
 2、每层第一个以及最后一个元素值为1
 3、对于第k(k > 2)层第n(n > 1 && n < k)个元素A[k][n]，A[k][n] = A[k-1][n-1] + A[k-1][n]
 
 6、合并两个有序数组
 输入:
 nums1 = [1,2,3,0,0,0], m = 3
 nums2 = [2,5,6], n = 3
 
 输出: [1,2,2,3,5,6]
 
 
 7、两数之和
 Input: numbers={2, 7, 11, 15}, target=9 Output: index1=1, index2=2
 
 8、给定一个整型数组num，找出这个数组中满足这个条件的所有数字: num[i]+num[j]+num[k] = 0. 并且所有的答案是要和其他不同的，也就是说两个相同 的答案是不被接受的。
 
 
 9、寻找两个有序数组的中位数
 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
 
 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 
 你可以假设 nums1 和 nums2 不会同时为空。
 
 示例 1:
 
 nums1 = [1, 3]
 nums2 = [2]
 则中位数是 2.0
 示例 2:
 
 nums1 = [1, 2]
 nums2 = [3, 4]
 则中位数是 (2 + 3)/2 = 2.5
 
 算法:
 为了解决这个问题，我们需要理解 “中位数的作用是什么”。在统计中，中位数被用来：
 
 将一个集合划分为两个长度相等的子集，其中一个子集中的元素总是大于另一个子集中的元素。
 
 这其中又分为偶数组和奇数组：
 
 奇数组: [2 3 5] 对应的中位数为3
 
 偶数组: [1 4 7 9] 对应的中位数为 (4 + 7) /2 = 5.5
 */

#include <iostream>
#include <vector>

using namespace std;
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))


template <class T>
int getArrayLen(T&array){
    return sizeof(array) / sizeof(array[0]);
}

class Solution{
public:
    //1、移除数组中包含 K 的元素，并返回数组的长度
    int removeElement(int A[], int n, int elem) {
        int i = 0;
        int j = 0;
        for(i = 0; i < n; i++) {
            if(A[i] == elem) {
                continue;
            }
            A[j] = A[i];
            j++;
        }
        return j;
    }
    
    //2、一个排序好的数组里面删除 重复的元素。
    int removeDuplicates(int A[], int n) {
        if(n == 0) {
            return 0;
        }
        int j = 0;
        for(int i = 1; i < n; i++) {
            if(A[j] != A[i]) {
                A[++j] = A[i];
            }
        }
        return j + 1;
    }
    
    //3、同样是移除重复的元素，但是可以允许最多两次重复元素存在
    int removeDuplicatess(int A[], int n) {
        if(n == 0) {
            return 0;
        }
        int j = 0;
        int num = 0;
        for(int i = 1; i < n; i++) {
            if(A[j] == A[i]) {
                num++;
                if(num < 2) {
                    A[++j] = A[i];
                }
            } else {
                A[++j] = A[i];
                num = 0;
            }
        }
        return j + 1;
    }
    
    //4、加1
    vector<int> plusOne(vector<int> &digits) {
        vector<int> res(digits.size(), 0);
        int sum = 0;
        int one = 1;
        for(int  i = (int)digits.size() - 1; i >= 0; i--) {
            sum = one + digits[i];
            one = sum / 10;
            res[i] = sum % 10;
        }
        if(one > 0) {
            res.insert(res.begin(), one);
        }
        return res;
    }
    
    //5、帕斯卡三角
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > vals;
        vals.resize(numRows);
        
        for(int i = 0; i < numRows; i++) {
            vals[i].resize(i + 1);
            vals[i][0] = 1;
            vals[i][vals[i].size() - 1] = 1;
            for(int j = 1; j < vals[i].size() - 1; j++) {
                vals[i][j] = vals[i - 1][j - 1] + vals[i- 1][j];
            }
        }
        return vals;
    }
    
    //6、合并两个有序数组
    int* merge(int* nums1, int* nums2 ,int m, int n) {
        
        int i = m - 1, j = n - 1, tar = m + n - 1;
        
        while (j >= 0) {
            nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
        return  nums1;
    }
    
    //7、两数之和
    vector<int> twoSums(vector<int>& nums, int target) {
        unordered_map<int,int> record;
        vector<int> result;
        for(int i = 0 ; i < nums.size() ; i ++){
            int complement = target - nums[i];
            if(record.find(complement) != record.end()){
                int res[] = {i, record[complement]};
                return vector<int>(res, res + 2);
            }
            
            record[nums[i]] = i;
        }
        return result;
    }
    
    // 9、寻找两个有序数组的中位数
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        unsigned long n = nums1.size();
        unsigned long m = nums2.size();
        
        if (n > m)  //保证数组1一定最短
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        // Ci 为第i个数组的割,比如C1为2时表示第1个数组只有2个元素。LMaxi为第i个数组割后的左元素。RMini为第i个数组割后的右元素。
        unsigned long LMax1 = 0, LMax2 = 0, RMin1 = 0, RMin2 = 0, c1, c2, lo = 0, hi = 2 * n;  //我们目前是虚拟加了'#'所以数组1是2*n长度
        
        while (lo <= hi)   //二分
        {
            c1 = (lo + hi) / 2;  //c1是二分的结果
            c2 = m + n - c1;
            
            LMax1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
            RMin1 = (c1 == 2 * n) ? INT_MAX : nums1[c1 / 2];
            LMax2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
            RMin2 = (c2 == 2 * m) ? INT_MAX : nums2[c2 / 2];
            if (LMax1 > RMin2)
                hi = c1 - 1;
            else if (LMax2 > RMin1)
                lo = c1 + 1;
            else
                break;
        }
        return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
    }
    
    
    
    
    //遍历一维数组
    void reverse_index(vector<int> vec){
        int i;
        cout << "reverse index : " << endl;
        for (i = 0; i < vec.size(); i++){
            cout << vec[i] << " ";
        }
    }
    
    //遍历二维数组
    void reverse_indexs(vector<vector<int>> vec){
        int i,j;
        cout << "Use index : " << endl;
        for (i = 0; i < vec.size(); i++)
        {
            for(j = 0; j < vec[i].size(); j++)
                cout << vec[i][j] << " ";
            cout << endl;
        }
    }
};

int main(int argc, const char * argv[]) {
    int a[] = {1,2,4,5,2,6,5};
    
    Solution solution;
    
    cout << solution.removeElement(a , getArrayLen(a), 5);
    
    int b[] = {1,2,3,4,4,5,5};
    cout << solution.removeDuplicates(b , getArrayLen(b));
    cout << endl;
    cout << endl;
    
    
    int c[] = {1,2,3,4,4,5,5};
    cout << solution.removeDuplicatess(c , getArrayLen(c));
    cout << endl;
    cout << endl;
    
    
    vector<int> digits;
    vector<int> reslut;
    
    digits.push_back(1);
    digits.push_back(2);
    digits.push_back(3);
    
    reslut = solution.plusOne(digits);
    solution.reverse_index(reslut);
    cout << endl;
    cout << endl;
    
    
    vector<vector<int>> vec;
    vec = solution.generate(6);
    solution.reverse_indexs(vec);
    cout << endl;
    cout << endl;
    
    
    int A[10] = {1, 2, 3, 4, 5};
    int B[5] = {2, 3, 5, 7, 9};
    int* C = solution.merge(A, B, 5, 5);
    for (int i = 0; i < 10; i++) {
        cout << C[i]  << " ";
    }
    cout << endl;
    cout << endl;
    
    
    
    std::vector<int> nums;
    std::vector<int> resultSum;
    
    nums.push_back(2);
    nums.push_back(11);
    nums.push_back(7);
    nums.push_back(15);
    
    resultSum = solution.twoSums(nums, 18);
    solution.reverse_index(resultSum);
    cout << endl;
    cout << endl;
    
    
    vector<int> nums1 = { 2,3, 5 };
    vector<int> nums2 = { 1,4,7, 9 };
    
    double ret = solution.findMedianSortedArrays(nums1, nums2);
    cout << ret  << " ";
    cout << endl;
    cout << endl;
    
    
    return 0;
}
