/*
时间限制：1秒 空间限制：32768K 热度指数：104469
本题知识点： 数组
题目描述
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
*/

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int sz = data.size();
        if(sz<2) return;
        int myxor = 0;
        int flag = 1;
        for(int i=0;i<sz;++i){
            myxor ^= data[i];
        }
        //当前的myxor是两个出现一次的数的异或结果
        //找出第一位为1的位置，此位置反映了其中一个数的这个位为1 另一个的为0。
        while( (flag & myxor) == 0 )
            flag = flag<<1;
        //将全部的数据分成了两拨 与flag与为1 和 与flag与为0
        for(int i=0;i<sz;++i){
            if( (flag & data[i]) == 0 )
                *num1 ^= data[i];
            else
                *num2 ^= data[i];
        }  
    }
};
