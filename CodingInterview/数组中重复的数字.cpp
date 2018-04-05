
/*
时间限制：1秒 空间限制：32768K 热度指数：96830
本题知识点： 数组

题目描述
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。
也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 

*/

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(numbers==nullptr || length<=0)
            return false;
        for(int i=0;i<length;++i){
            while(numbers[i]!=i){
                if(numbers[i]==numbers[numbers[i]]){
                    *duplication = numbers[i];
                    return true;
                } 
                swap(numbers[i],numbers[numbers[i]]);
            }
        }
        return false;
    }
};
