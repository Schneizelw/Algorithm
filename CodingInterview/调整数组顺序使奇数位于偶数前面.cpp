/*
时间限制：1秒 空间限制：32768K 热度指数：234006
本题知识点： 数组
题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，
所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/
/*
使用两个指针firstEven指向第一个偶数  cur用来遍历数组。
当cur指向奇数的时候将firstEven的值赋值为cur的值
当cur指向偶数的时候将该值放在一个临时的vector<int> temp上。

最后将temp的全部元素放到 数组array以firstEven为开始位置的后面。
*/

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if(array.size()==0) return;
        auto firstEven=array.begin();
        auto cur = firstEven;
        vector<int> temp;
        while(cur!=array.end()){
            if((*cur&1)){
               *(firstEven++) = *cur;
            }else{
                temp.push_back(*cur);
            }
            ++cur;
        }
        for(auto &e : temp){
            *(firstEven++) = e;
        }
        
    }
};
