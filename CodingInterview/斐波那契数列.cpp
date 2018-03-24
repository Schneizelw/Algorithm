/*
时间限制：1秒 空间限制：32768K 热度指数：270749
题目描述
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
n<=39
*/

class Solution {
public:
    int Fibonacci(int n) {
        if(n==0) return 0;//从0开始
        if(n==1||n==2) return 1;
        long first=1,second=1,third=0;
        n-=2;
        while(n--){
            third = first+second;
            first = second;
            second = third;
        }
        return second;
    }
};
