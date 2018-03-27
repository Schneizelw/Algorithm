/*
时间限制：1秒 空间限制：32768K 热度指数：84073
题目描述
求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,但是对于后面问题他就没辙了。
ACMer希望你们帮帮他,并把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数。

*/


class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if(n<=0) return 0;
        int count = 0; //计数
        int weight = 0;//位数
        int round = n;//"循环次数"
        int base = 1;//基值
        while(round>0){
            weight = round%10;//取出最低位
            round /=10;//循环次数
            count += base*round;
            if(weight==1)
                count += (n%base)+1;
                         //^^^^^^ former
            if(weight>1) 
                count +=base;
            base *= 10;
        }
        return count;
    }
};
